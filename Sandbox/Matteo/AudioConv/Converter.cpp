#include "Converter.h"

using namespace std;


Converter::Converter( )
: mInAudio( 0 )
, mOutAudio( 0 )
{

}

Converter::~Converter()
{
	
}
// --------------------------------------------------------------------------
//	 Convert 
// --------------------------------------------------------------------------
bool		
Converter::Convert( const Audio* inAudio, Audio* outAudio )
{
	mInAudio = inAudio;
	mOutAudio = outAudio;

	// initializing parameters 
	mFreqRatio = mInAudio->mFreq / mOutAudio->mFreq;
	mCurrFrame = 0;
	mCurrNeedPer = 1.0;
	mBytesPerSampleIn = mInAudio->mBps/8;
	mBytesPerSampleOut = mOutAudio->mBps/8;
	
	// the ratio of intensity depends from the difference in bps of input and output: 
	// it is a intesit normalization value
	if ( mBytesPerSampleOut == mBytesPerSampleIn )
		mIntesityRatio = 1.0;
	else if ( mBytesPerSampleOut > mBytesPerSampleIn )
		mIntesityRatio = 1 << ( mOutAudio->mBps - mInAudio->mBps );
	else 
		mIntesityRatio = 1. / ( 1 << ( mInAudio->mBps - mOutAudio->mBps ) );
	
	// only frequency downsampling:
	if ( mFreqRatio >= 1.0 )
	{
		// compute the needed space for output and allocate
		mOutAudio->mDataLength = static_cast < unsigned > ( ( mInAudio->mDataLength / ( mInAudio->mCCount * mBytesPerSampleIn ) )
																		  * ( ( mBytesPerSampleOut * mOutAudio->mCCount ) / mFreqRatio )  );
		mOutAudio->mData = new unsigned char[ mOutAudio->mDataLength ];

		DownSample();
	}
	// implement frequency upsampling
	// improve when at same frequency
	
	return true;
}

// --------------------------------------------------------------------------
//	 DownSample 
// --------------------------------------------------------------------------
void				
Converter::DownSample()
{
	vector < unsigned int > currSamples;
	vector <	double >			sampleAccum;
	double						mul;
	int							toRead;
	unsigned						outFrameCount = mOutAudio->mDataLength / (mOutAudio->mCCount * mBytesPerSampleOut);

	// this is the vector where the iput samples will be read:
	// created large to be sure, the dimension should be:
	// the input number of channels * the maximum number of input samples needed to calculate an output sample
	currSamples.reserve( ( mFreqRatio + 5.5 ) * mInAudio->mCCount ); 
	currSamples.resize( 0 );

	// this is an accumulator of the value of the input samples multiplied by a weight (factor)  
	// this accumulates for each output channel
	sampleAccum.resize( mOutAudio->mCCount );

	// loop on the number of output frames
	for ( unsigned i=0; i<outFrameCount; ++i )
	{
		// compute the number of input frames to read for the current output frame
		toRead = static_cast<int> ( mFreqRatio + (1.0-mCurrNeedPer) + .5 );

		// reset the accumulator
		for ( int c=0; c<mOutAudio->mCCount; ++c )
			sampleAccum[c] = 0;

		// read the needed input frames ( mCurrFrame stores the current position in the input file)
		if ( !ReadToVector( currSamples, toRead ) )
			return;
		
		// add the read frame with appropriate weight in the sampleAccum per each channel
		for ( int j=0; j<toRead; ++j )
		{
			// compute the weight and store it in "mul"
			if ( j == 0 )
				mul = mCurrNeedPer;
			else if ( j == toRead-1 ) 
				mul = ( mFreqRatio + (1.0 - mCurrNeedPer) ) - (toRead-1) ;
			else 
				mul = 1.0;

			// for each output channel select the input channel
			for ( int c=0; c<mOutAudio->mCCount; ++c )
			{
				if ( mOutAudio->mCCount == mInAudio->mCCount ) // same number of channels: easy
					sampleAccum[c] +=  mul * currSamples[c+j*mInAudio->mCCount];
				else 
				{  // only 1 and 2 channels supported
					// if output has two channel and input one: duplicate it
					if ( mOutAudio->mCCount > mInAudio->mCCount ) 
						sampleAccum[c] += mul * currSamples[j];
					else
					{
						// select here your policy: this is an average
						sampleAccum[c] += mul * ( currSamples[j*mInAudio->mCCount] + currSamples[1+j*mInAudio->mCCount] ) / 2.0;
					}
				}
			}
		}

		// compute the need percentage of the next current frame (it is a "reminder")
		mCurrNeedPer = 1.0 - ( ( mFreqRatio + (1.0 - mCurrNeedPer) ) - (toRead-1) );
		if ( mCurrNeedPer == 0.0 )
		{
			mCurrFrame += toRead;
			mCurrNeedPer = 1.0;
		}
		else
			mCurrFrame += (toRead-1);

		// write the accumulated samples in frame number "i"
		if ( !WriteToFrame( i, sampleAccum ) )
			return;
	}
}

// --------------------------------------------------------------------------
//	 ReadToVector 
// --------------------------------------------------------------------------
inline bool	
Converter::ReadToVector( std::vector< unsigned int> & outVec, int toRead )
{
	if ( (mCurrFrame+toRead) * mBytesPerSampleIn * mInAudio->mCCount
				> mInAudio->mDataLength )
		return false; // I shall throw !

	outVec.resize( toRead * mInAudio->mCCount );

	for ( int i=0; i<toRead; ++i )
	{
		for ( int c=0; c<mInAudio->mCCount; ++c )
		{
			unsigned int	byteIdx =  (mCurrFrame + i) * mInAudio->mCCount * mBytesPerSampleIn
												+ c * mBytesPerSampleIn ;
			unsigned char* bytePtr =  mInAudio->mData + byteIdx;

			switch ( mInAudio->mBps )
			{
			case 8: 
				outVec[c+i*mInAudio->mCCount] = *bytePtr ;
				break;
			case 16: 
				outVec[c+i*mInAudio->mCCount] = *bytePtr + ( *(bytePtr+1)<<8 );
				break;
			case 24: 
				outVec[c+i*mInAudio->mCCount] = *bytePtr + ( *(bytePtr+1)<<8 )  + ( *(bytePtr+2)<<16 );
				break;
			}
		}
	}

	return true;
}


// --------------------------------------------------------------------------
//	 WriteToSample 
// --------------------------------------------------------------------------
inline bool	
Converter::WriteToFrame( unsigned int inIdx, const std::vector< double >& inSamples )
{
	if ( inIdx * mBytesPerSampleOut * mOutAudio->mCCount > mOutAudio->mDataLength )
		return false; // I shall throw !
	
	for ( int c=0; c<mOutAudio->mCCount; ++c )
	{
		int				val = static_cast< int > ( inSamples[c] * mIntesityRatio / mFreqRatio + .5 );
		unsigned	int	byteIdx = inIdx * mOutAudio->mCCount * mBytesPerSampleOut 
										  + c * mBytesPerSampleOut ;
		unsigned char* bytePtr = mOutAudio->mData + byteIdx;

		switch ( mBytesPerSampleOut )
		{
		case 1: 
			*bytePtr = val ;
			break;
		case 2: 
			* bytePtr = val && 0x000000ff;
			*(bytePtr+1) = val>>8;
			break;
		case 3: 
			* bytePtr = val && 0x000000ff;
			*(bytePtr+1) = val>>8 && 0x000000ff;
			*(bytePtr+2) = val>>16 && 0x000000ff;
			break;
		}
	}

	return true;
}

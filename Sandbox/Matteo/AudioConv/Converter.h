#ifndef CONVERTER_H
#define CONVERTER_H

#include <vector> 

struct Audio
{
	Audio( double inF, int inB, int inC )
				: mFreq(inF), mBps(inB), mCCount( inC), mDataLength(0), mData(0) 
			{ /*if ( mChan != 1 || mChan != 2 ) throw();*/ } 
			// only 1 and 2 channels supported 

	~Audio() { };

	double			mFreq;			// frequency in KHz
	int				mBps;				// bit per samples
	int				mCCount;			// number of channels
	unsigned	int	mDataLength; 
	unsigned char*	mData;			// not owned !
};


class Converter 
{

public:
	Converter();
	~Converter();

	bool		Convert( const Audio* inAudio, Audio* outAudio );

private:
	const Audio*	mInAudio;
	Audio*			mOutAudio;

	double			mFreqRatio;
	unsigned			mCurrFrame; // currrent input frame to read
	double			mCurrNeedPer; // percentage needed of current sample
	int				mBytesPerSampleIn;
	int				mBytesPerSampleOut;
	double			mIntesityRatio;

	void				FreqDownSample();
	void				FreqSame();
	void				FreqUpSample();

	bool				ReadToVector( std::vector< unsigned int> & outVec, int toRead );
	bool				WriteToFrame( unsigned int inIdx, const std::vector< double >& inSamples );

};

#endif // CONVERTER_H



#include <QFileDialog> 
#include <fstream>
#include <string> 

#include "AudioConv.h"
#include "ConvertParam.h"
#include "Converter.h"


AudioConv::AudioConv(QWidget *parent, Qt::WFlags flags)
	: QDialog(parent, flags)
{
	setupUi(this);

	connect( mLoadBtn, SIGNAL(clicked()), this, SLOT(BrowseSlot()) );
	connect( mConvertBtn, SIGNAL(clicked()), this, SLOT(ConvertSlot()) );
}

AudioConv::~AudioConv()
{

}

// --------------------------------------------------------------------------
//	 ConvertSlot [private slot]
// --------------------------------------------------------------------------
void
AudioConv::ConvertSlot( )
{
	if ( 0 == mSelectedFile.size() )
	{
		AppendToLog("\nError: No input file selected" );
		return;
	}

	ConvertParam	dlg;
	if ( dlg.exec() )
	{
		AppendToLog( "\nConversion" );
		AppendToLog( "Input parameters: frequency " + FreqToString( mFreq ) );
		AppendToLog( "                     bit per sample " + BpsToString( mBps )  );
		AppendToLog( "                     channel count " + ChannelToString( mChan ) );
		
		double	outFreq = dlg.GetFreq();
		int		outBps = dlg.GetBps();
		int		outChans = dlg.GetChanCount();
		AppendToLog( "Output parameters: frequency " + FreqToString( outFreq ) );
		AppendToLog( "                     bit per sample " + BpsToString( outBps ) );
		AppendToLog( "                     channel count " + ChannelToString( outChans ) );

		Audio			input( mFreq, mBps, mChan );
		Audio			output( outFreq, outBps, outChans );
		
		if ( false == ReadFile( &input ) )
			AppendToLog( "Error reading input file" );
		else
		{
			Converter	conv;

			if ( conv.Convert( &input, &output ) )
			{
				QString outFileName = SaveFile ( output );
				if ( 0 == outFileName.size() )
					AppendToLog( "\nError saving audio file" );
				else
					AppendToLog( "\n\nSaved as <b>" + outFileName + "</b>" );

				delete[] output.mData;
			}

			delete[] input.mData;
		}
	}
}

// --------------------------------------------------------------------------
//	 ReadFile 
// --------------------------------------------------------------------------
bool
AudioConv::ReadFile( Audio* outAudio )
{
	using namespace std;

	if ( 0 == mSelectedFile.size() )
		return false;

	string			str = QString( mBasePath + "/" + mSelectedFile ).toStdString();
	ifstream			inFile( str.c_str(), ios_base::binary );

	if ( !inFile )
		return false;

	inFile.seekg( 0, ios_base::end ); 
	
	outAudio->mDataLength = inFile.tellg();
	
	if ( 0 == outAudio->mDataLength )
		return false;

	outAudio->mData = new unsigned char[outAudio->mDataLength];
	
	inFile.seekg( 0, ios_base::beg ); 
	inFile.read( (char*) outAudio->mData,  outAudio->mDataLength );

	//if ( inFile.good() )
	//	return false;
	//else
	return true;
}

// --------------------------------------------------------------------------
//	 SaveFile 
// --------------------------------------------------------------------------
QString
AudioConv::SaveFile( const Audio& inAudio )
{
	using namespace std;

	if ( 0 == inAudio.mDataLength )
		return QString(0);
	
	QString		outName = "out_f" + FreqToShortString( inAudio.mFreq ) + "_b" + BpsToString( inAudio.mBps ) 
								 + "_c" + ChannelToString( inAudio.mCCount ) + "_FROM_" + mSelectedFile;
	string		str = QString( mBasePath + "/" + outName ).toStdString();
	ofstream		outFile( str.c_str(), ios_base::binary );
	
	if ( outFile.good() ) 
	{
		outFile.write( (char*) inAudio.mData, inAudio.mDataLength );
		if ( outFile.good() ) 
			return outName;
	}
	return QString(0);
}

// --------------------------------------------------------------------------
//	 BrowseSlot [private slot]
// --------------------------------------------------------------------------
bool
AudioConv::BrowseSlot( ) 
{
	mLogText->clear();

	QStringList files = QFileDialog::getOpenFileNames ( 
												this, tr("Select Audio Raw File."), 
												"", "Audio raw (*.raw)", 0, 
												QFileDialog::DontResolveSymlinks ); 
	if ( files.size() )
	{
		QFileInfo	file( files[0] );
		mBasePath = file.canonicalPath();
		mSelectedFile = file.fileName(); 

		AppendToLog( "Selected file: <b>" + mSelectedFile + "<\b>" );

		QRegExp	freqRx( "_[f,F]\\d\\d?" );
	
		if ( -1 == freqRx.indexIn( mSelectedFile ) )
		{
			AppendToLog( "Error: Frequency unknown, ignoring file.\n         " \
						    "Set frequency adding _fNN to the file name.");
			mSelectedFile = "";
		}
		else 
		{
			QString str = freqRx.cap(0);
			str = str.right( str.size() - 2 );
			if ( ! StringToFreq( str, mFreq ) )
			{
				AppendToLog( "Error: Frequency not recognized, ignoring file.\n         "\
								 "Valid frequencies 8, 16, 22, 44.");
				mSelectedFile = "";
			}
		}

		QRegExp	bitRx( "_[b,B]\\d\\d?" );
	
		if ( -1 == bitRx.indexIn( mSelectedFile ) )
		{
			AppendToLog( "Error: Bit per sample unknown, ignoring file.\n         "\
							 "Set bit per sample adding _bNN to the file name.");
			mSelectedFile = "";
		}
		else 
		{
			QString str = bitRx.cap(0);
			str = str.right( str.size() - 2 );
			if ( ! StringToBps( str, mBps ) )
			{
				AppendToLog( "Error:  Bit per sample not recognized, ignoring file.\n         "\
								 "Valid values 8, 16, 24.");
				mSelectedFile = "";
			}
		}

		QRegExp	chanRx( "_[c,C]\\d" );
	
		if ( -1 == chanRx.indexIn( mSelectedFile ) )
		{
			AppendToLog( "Error: Channel number unknown, ignoring file.\n         " \
						    "Set channel number adding _cX to the file name.");
			mSelectedFile = "";
		}
		else 
		{
			QString str = chanRx.cap(0);
			str = str.right( str.size() - 2 );
			if ( ! StringToChannel( str, mChan ) )
			{
				AppendToLog( "Error: Frequency not recognized, ignoring file.\n         "\
								 "Valid frequencies 8, 16, 22, 44.");
				mSelectedFile = "";
			}
		}

		return true;
	}
	
	return false;
}

// --------------------------------------------------------------------------
//	 AppendToLog
// --------------------------------------------------------------------------
void
AudioConv::AppendToLog( const QString& inStr )
{
	mLogText->append( inStr );
}

// --------------------------------------------------------------------------
bool
AudioConv::StringToFreq( const QString& inStr, double &out )
{
	bool success = true;

	if ( inStr == "8" )
		out = 8.0;
	else if ( inStr == "16" )
		out = 16.0;
	else if ( inStr == "22" )
		out = 22.05;
	else if ( inStr == "44" )
		out = 44.1;		
	else
		success = false;

	return success;
}

// --------------------------------------------------------------------------
bool
AudioConv::StringToBps( const QString& inStr, int& out )
{
	bool success = true;

	if ( inStr == "8" )
		out = 8;
	else if ( inStr == "16" )
		out = 16;
	else if ( inStr == "24" )
		out = 24;
	else
		success = false;

	return success;
}

// --------------------------------------------------------------------------
bool
AudioConv::StringToChannel( const QString& inStr, int& out )
{
	bool success = true;

	if ( inStr == "1" )
		out = 1;
	else if ( inStr == "2" )
		out = 2;
	else
		success = false;

	return success;
}

// --------------------------------------------------------------------------
QString
AudioConv::FreqToString( double inVal )
{
	if ( inVal == 8.0 )
		return QString( " 8.0 KHz " );
	else if ( inVal == 16.0 )
		return QString( " 16.0 KHz " );
	else if ( inVal == 22.05 )
		return QString( " 22.05 KHz " );
	else if ( inVal == 44.1 )
		return QString( " 44.1 KHz " );

	return QString("");
}

// --------------------------------------------------------------------------
QString			
AudioConv::BpsToString( int inVal )
{
	QString str;
	str.setNum( inVal );
	return str;
}

// --------------------------------------------------------------------------
QString			
AudioConv::ChannelToString( int inVal )
{
	QString str;
	str.setNum( inVal );
	return str;
}

// --------------------------------------------------------------------------
QString
AudioConv::FreqToShortString( double inVal )
{
	QString str;
	str.setNum( static_cast< int >( inVal ) );
	return str;
}

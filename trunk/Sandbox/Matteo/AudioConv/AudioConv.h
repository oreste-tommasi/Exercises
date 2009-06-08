#ifndef AUDIOCONV_H
#define AUDIOCONV_H

#include <QtGui/QDialog>
#include <QtGui>
#include <QString>
#include "ui_AudioConv.h"

// forward declaration
class Audio;

class AudioConv : public QDialog, private Ui::AudioConvClass
{
	Q_OBJECT

public:
	AudioConv(QWidget *parent = 0, Qt::WFlags flags = 0);
	~AudioConv();

public slots:
	void				AppendToLog( const QString& inStr );

private slots:
	bool				BrowseSlot( );
	void				ConvertSlot( );
	
private:
	bool				ReadFile( Audio* outAudio );
	QString			SaveFile( const Audio& inAudio );

	bool				StringToFreq( const QString& inStr, double &out );
	bool				StringToBps( const QString& inStr, int& out );
	bool				StringToChannel( const QString& inStr, int& out );

	QString			FreqToString( double inVal );
	QString			BpsToString( int inVal );
	QString			ChannelToString( int inVal );
	QString			FreqToShortString( double inVal );


	QString			mBasePath;
	QString			mSelectedFile;


	double			mFreq;
	int				mBps;
	int				mChan;
};

#endif // AUDIOCONV_H

#include "ConvertParam.h"

ConvertParam::ConvertParam(QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);

	QStringList	freqs;
	freqs.append( "8.0 Khz" );
	freqs.append( "16.0 Khz" );
	freqs.append( "22.05 Khz" );
	freqs.append( "44.1 Khz" );

	mFreqCmb->addItems( freqs );

	QStringList	bits;
	bits.append( "8" );
	bits.append( "16" );
	bits.append( "24" );
	
	mBpsCmb->addItems( bits );

	QStringList	chans;
	chans.append( "1" );
	chans.append( "2" );
	mChannelCmb->addItems( chans );

	connect( mButtonBox, SIGNAL(accepted()), this, SLOT(accept()) );
	connect( mButtonBox, SIGNAL(rejected()), this, SLOT(reject()) );
}


ConvertParam::~ConvertParam()
{
	
}

int	
ConvertParam::GetBps()
{
	switch ( mBpsCmb->currentIndex() )
	{
	case 0:
		return 8;
	case 1:
		return 16;
	case 2:
		return 24;
	}
	return 0;
}

double
ConvertParam::GetFreq()
{
	switch ( mFreqCmb->currentIndex() )
	{
	case 0:
		return 8.0;
	case 1:
		return 16.0;
	case 2:
		return 22.05;
	case 3:
		return 44.1;
	}
	return 0;
}

int
ConvertParam::GetChanCount()
{
	switch ( mChannelCmb->currentIndex() )
	{
	case 0:
		return 1;
	case 1:
		return 2;
	}
	return 0;
}
package it.geomind.myfirstapp;

import android.app.AlertDialog;
import android.app.Dialog;
import android.content.DialogInterface;
import android.os.Bundle;
import android.support.v4.app.DialogFragment;

/**
 */
public class MyAlertDialogFragment extends DialogFragment implements DialogInterface.OnClickListener
{
    public interface MyAlertDialogListener {
        void onFinishDialog( int inButtonIndex );
    }


    // constructor
    public MyAlertDialogFragment( String inTitle, String inMsg, String[] inButtonStrings,
                                  MyAlertDialogListener inListener )
    {
        mTitle = inTitle;
        mMsg = inMsg;
        mButtonStrings = inButtonStrings.clone();
        mChoiceCode = 0;
        mListener = inListener;
    }

    @Override
    public Dialog onCreateDialog(Bundle savedInstanceState)
    {
        // Use the Builder class for convenient dialog construction
        AlertDialog.Builder builder = new AlertDialog.Builder( getActivity() );

        if( !mTitle.isEmpty() )
            builder.setTitle( mTitle );

        if( !mMsg.isEmpty() )
            builder.setMessage( mMsg );

        if( mButtonStrings.length == 1 )
            builder.setPositiveButton( mButtonStrings[0], this );
        if( mButtonStrings.length == 2 )
        {
            builder.setNegativeButton( mButtonStrings[0], this );
            builder.setPositiveButton( mButtonStrings[1], this );
        }
        if( mButtonStrings.length >= 3 )
        {
            builder.setNegativeButton( mButtonStrings[0], this );
            builder.setNeutralButton( mButtonStrings[1], this );
            builder.setPositiveButton( mButtonStrings[2], this );
        }

        // Create the AlertDialog object and return it
        return builder.create();
    }

    public void onClick( DialogInterface dialog, int which )
    {
        mChoiceCode = which;
        if( mListener != null )
            mListener.onFinishDialog( mChoiceCode );
    }


    private String mTitle;
    private String mMsg;
    private String[] mButtonStrings;
    private int mChoiceCode;
    private MyAlertDialogListener mListener;
}

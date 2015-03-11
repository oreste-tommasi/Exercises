package it.geomind.myfirstapp;

import android.app.AlertDialog;
import android.app.Dialog;
import android.content.DialogInterface;
import android.os.Bundle;
import android.support.v4.app.DialogFragment;

/**
 */
public class MyAlertDialogFragment extends DialogFragment
{
    private String mTitle;
    private String mMsg;
    public int mChoiceCode;

    public MyAlertDialogFragment( String inTitle,  String inMsg )
    {
        mTitle = inTitle;
        mMsg = inMsg;
        mChoiceCode = 0;
    }

    @Override
    public Dialog onCreateDialog(Bundle savedInstanceState)
    {
        // Use the Builder class for convenient dialog construction
        AlertDialog.Builder builder = new AlertDialog.Builder( getActivity() );

        builder.setMessage( mMsg );

        builder.setPositiveButton("OK", new DialogInterface.OnClickListener() {
                    public void onClick(DialogInterface dialog, int id) {
                        mChoiceCode = 1;
                    }
                });

        builder.setNegativeButton("Cancel", new DialogInterface.OnClickListener() {
                    public void onClick(DialogInterface dialog, int id) {
                        mChoiceCode = 0;
                    }
                });

        if( !mTitle.isEmpty() )
            builder.setTitle( mTitle );

        // Create the AlertDialog object and return it
        return builder.create();
    }

}

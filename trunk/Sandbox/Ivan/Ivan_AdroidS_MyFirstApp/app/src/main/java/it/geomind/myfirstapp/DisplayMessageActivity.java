package it.geomind.myfirstapp;

import android.content.Intent;
import android.support.v7.app.ActionBarActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.TextView;


public class DisplayMessageActivity extends ActionBarActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        // Get the message from the intent
        Intent intent = getIntent();
        //String message = intent.getStringExtra(MyActivity.EXTRA_MESSAGE);
        String message = callNative();

        // Create the text view
        TextView textView = new TextView(this);
        textView.setTextSize(40);
        textView.setText(message);
        //Log.i("NDK ", callNative());

        callNativeWithTextView( textView );

        // Set the text view as the activity layout
        setContentView(textView);
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if (id == R.id.action_settings) {
            return true;
        }

        return super.onOptionsItemSelected(item);
    }

    public int showAlertDialog( String inTitle, String inMsg )
    {
        MyAlertDialogFragment dialog = new MyAlertDialogFragment( inTitle, inMsg );
        dialog.show( getSupportFragmentManager(), "MyAlertDialogFragment" );
        return dialog.mChoiceCode;
    }

    public native String callNative();
    public native void callNativeWithTextView( TextView textView );
}

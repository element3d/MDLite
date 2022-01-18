package com.MDLiteTest;
import android.content.Intent;
import android.database.Cursor;
import android.os.Bundle;
import android.provider.MediaStore;
import android.view.KeyEvent;
import android.view.View;

import com.carbon.element3d.e3Activity;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class MainActivity extends e3Activity {

    @Override
    public void onInteraction(String message, e3Activity.OnInteractionResultCallback c) {
        super.onInteraction(message, c);
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
		loadApplication("MDLiteTest");
        super.onCreate(savedInstanceState);
    }

    @Override
    public void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
    }

    @Override
    protected void onStart() {
        super.onStart();
    }

    @Override
    protected void onResume() {
        super.onResume();
    }

    @Override
    protected void onPause() {
        super.onPause();
    }

    @Override
    protected void onStop() {
        super.onStop();
    }

    /*@Override
    protected void onDestroy() {
        super.onDestroy();
    }*/
}
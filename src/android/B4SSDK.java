package org.apache.cordova.b4s;

import android.app.Application;
import android.content.Context;

import org.apache.cordova.CordovaPlugin;
import org.apache.cordova.CallbackContext;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import com.ezeeworld.b4s.android.sdk.B4SSettings;
import com.ezeeworld.b4s.android.sdk.B4SUserProperty;
import com.ezeeworld.b4s.android.sdk.BuildConfig;
import com.ezeeworld.b4s.android.sdk.monitor.MonitoringManager;
import com.ezeeworld.b4s.android.sdk.notifications.NotificationService;

/**
* This class echoes a string called from JavaScript.
*/
public class B4SSDK extends CordovaPlugin {

    @Override
    public boolean execute(String action, JSONArray args, CallbackContext callbackContext) throws JSONException {
        System.out.println("CDV-B4SSDK:"+action);
        if (action.equals("init")) {
            String appID = args.getString(0);
            System.out.println("CDV-B4SSDK appID="+appID);
            this.init(message, callbackContext);
            return true;
        }
        return false;
    }

    private void init(String message, CallbackContext callbackContext) {
        Application application = this.cordova.getActivity().getApplication();

        // Initialize the B4S SDK with our app-specific registration ID
        B4SSettings settings = B4SSettings.init(application, "MY-APP-ID");

        // Enable remote push notifications
//      settings.setPushMessagingSenderId("MY-GOOGLE-SENDER-ID");

        // Send deep links to our broadcast receiver (instead of the default launcher activity delivery)
        NotificationService.registerDeepLinkStyle(NotificationService.DeepLinkStyle.BroadcastReceiver);

        B4SUserProperty.get().store(B4SUserProperty.USER_FIRST_NAME, "Jean-Michel");
        B4SUserProperty.get().store(B4SUserProperty.USER_LAST_NAME, "Bécatresse");
        B4SUserProperty.get().store(B4SUserProperty.USER_GENDER, B4SUserProperty.Gender.Male);


        // Start the monitoring service, if needed
        MonitoringManager.ensureMonitoringService(application);

        callbackContext.success(message);

        /*if (message != null && message.length() > 0) {
            callbackContext.success(message);
        } else {
            callbackContext.error("Expected one non-empty string argument.");
        }*/
    }
}
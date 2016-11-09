package com.ezeeworld.neerby;

import android.app.Application;

import com.ezeeworld.b4s.android.sdk.B4SSettings;
import com.ezeeworld.b4s.android.sdk.B4SUserProperty;
import com.ezeeworld.b4s.android.sdk.BuildConfig;
import com.ezeeworld.b4s.android.sdk.monitor.MonitoringManager;
import com.ezeeworld.b4s.android.sdk.notifications.NotificationService;


/**
 * Created by kris on 08/11/2016.
 */
public class NeerbyApp extends Application {
    @Override
    public void onCreate() {
        super.onCreate();

    try {
            ApplicationInfo ai = getPackageManager().getApplicationInfo(getPackageName(), PackageManager.GET_META_DATA);
            Bundle bundle = ai.metaData;
            String appID = bundle.getString("NEERBY_APP_ID");
            // Initialize the B4S SDK with our app-specific registration ID
            B4SSettings settings = B4SSettings.init(this, NeerbyConstants.NEERBY_APP_ID);
            settings.setShouldLogMatching(true);
            settings.setShouldLogScanning(true);

            // Enable remote push notifications
            // settings.setPushMessagingSenderId("MY-GOOGLE-SENDER-ID");

            // Send deep links to our broadcast receiver (instead of the default launcher activity delivery)
            NotificationService.registerDeepLinkStyle(NotificationService.DeepLinkStyle.BroadcastReceiver);


            // Start the monitoring service, if needed
            MonitoringManager.ensureMonitoringService(this);
        } catch (Exception e) {
            System.err.println("Exception raised while initialising Neerby SDK: " + e.getMessage());
        }
    }
}

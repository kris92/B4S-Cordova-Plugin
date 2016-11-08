Cordova Neerby Plugin
========================

The purpose of this plugin is to offer an fast Neerby SDK integration for Cordova Android and iOS applications.

## Usage

#### 1. Install the plugin
(`cordova plugin add https://github.com/kris92/B4S-Cordova-Plugin.git`)

#### 2. iOS
You must set the Neerby ApplicationID for your application and set the background mode request application text.
ApplicationID is set with the NEERBY_APP_ID variable.
The Background mode text is set with the LOCATION_ALWAYS_USAGE_DESCRIPTION variable.

```sh
cordova plugin add https://github.com/kris92/B4S-Cordova-Plugin.git --variable NEERBY_APP_ID="SET_YOUR_OWN_APPID" --variable LOCATION_ALWAYS_USAGE_DESCRIPTION="This mode is requested to enable Neerby iBeacon detection."
```


In Xcode, open the 'Build Settings' tab.
Add a User-Defined setting named NEERBY_APP_ID and set its value with your Neerby ApplicationID.

You must set a phrase for the background mode request explication text.
In Xcode, open the 'Build Settings' tab.
Add a User-Defined setting named NEERBY_BEACON_BACKGROUND_REASON and set its value with your text.

#### 3. Android
The Neerby SDK cannot be integrated as a true Cordova plugin. The plugin installation script for Android add an Application subclass 'com.ezeeworld.neerby.NeerbyApp' to your project.
This class is instanciated through the AndroidManifest.xml file. The Manifest file is automatically patched with the plugin installation process.
Add a file named NeerbyConstants.java to your project. This file is used to set your own Neerby ApplicationID for your application.

```java
// NeerbyConstants.java

package com.ezeeworld.neerby;

public class NeerbyConstants {

    public static final String NEERBY_APP_ID = "YOUR-OWN-APPID";

}
```

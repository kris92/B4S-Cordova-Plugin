Cordova Neerby Plugin
========================

The purpose of this plugin is to offer an fast Neerby SDK integration for Cordova Android and iOS applications.

## Usage

#### 1. iOS prerequities
On iOS, the SDK parameters are set through Cordova CLI variables.
You must set the Neerby ApplicationID for your application and set the background mode request application text.
•ApplicationID is set with the NEERBY_APP_ID variable.
•Background mode text is set with the LOCATION_ALWAYS_USAGE_DESCRIPTION variable.

#### 2. Android
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

#### 3. Install the plugin
(`cordova plugin add https://github.com/kris92/B4S-Cordova-Plugin.git --variable NEERBY_APP_ID="SET_YOUR_OWN_APPID" --variable LOCATION_ALWAYS_USAGE_DESCRIPTION="This mode is requested to enable Neerby iBeacon detection."`)

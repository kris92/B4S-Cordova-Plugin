Cordova Neerby Plugin
========================

The purpose of this plugin is to offer an fast Neerby SDK integration for Cordova Android and iOS applications.

## Usage

#### 1. Install the plugin
(`cordova plugin add https://github.com/kris92/B4S-Cordova-Plugin.git`)

#### 2. iOS
You must set the Neerby ApplicationID for your application.
In Xcode, open the 'Build Settings' tab.
Add a User-Defined setting named NEERBY_APP_ID and set its value with your Neerby ApplicationID.

You must set a phrase for the background mode request explication text.
In Xcode, open the 'Build Settings' tab.
Add a User-Defined setting named NEERBY_BEACON_BACKGROUND_REASON and set its value with your text.

#### 3. Android
Add a file named NeerbyConstants.java to your project. This file is used to set the Neerby ApplicationID for your application.

```java
// NeerbyConstants.java

package com.ezeeworld.neerby;

public class NeerbyConstants {

    public static final String NEERBY_APP_ID = "YOUR-OWN-APPID";

}
```

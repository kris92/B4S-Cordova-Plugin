//
//  B4SConstants.h
//  BeaconForStoreSDK
//
//  Created by Ezeeworld on 23/04/2014.
//  Copyright (c) 2014 Ezeeworld. All rights reserved.
//

#ifndef BeaconForStoreSDK_B4SConstants_h
#define BeaconForStoreSDK_B4SConstants_h

extern int const    kB4SRequestedLocationAccuracy;
extern int const    kB4SRequestedLocationAccuracyWhenCellularOnly;
extern int const    kB4SRequestedAccuracyForRegionEntryNotification;
extern int const    kB4SRadiusForGeofencingWakeup;
extern int const    kB4SMaxTimeoutForNearestBeacon;
extern int const    kB4SSessionMaxStorageDuration;
extern int const    kB4SRegionTimeout; // 12h
extern int const    kB4SCacheValidity;
extern int const    kB4SQueryTimeout;
extern int const    kB4SMaxProximityBeacons;
extern int const    kB4SDefaultTxPower;
extern float const  kB4SDefaultPathLoss;
extern float const  kB4SShortRangeRssiLimit;
extern float const  kB4SShortRangePathLoss;
extern float const  kB4SDefaultTxPowerBatteryCompensation;
extern float const  kB4SDefaultTxPowerTemperatureCompensation;
extern float const  kB4SBeaconloopDetectionInterval;
extern int const    kB4SBeaconMinSessionDuration;
extern int const    kB4SBeaconConnectTimeout;
extern double const kB4SBackgroundModeDuration;
extern int const    kB4SBtWarningRepeatCounter;
extern int const    kB4SInitialBeaconRssi;

/**
 * Min distance the device the device must leave a geofence radius to be considered as out.
 */
extern int const    kB4SGeofenceRangeOutDistanceInMeters;

extern float const kLongitudeToMetersRatio;
extern float const kLatitudeToMetersRatio;

/**
 * To avoid outdated notifications (typ : App was put in sleep mode while processing notification loop)
 */
extern int const    kB4SMaxDurationForNotifyingRegionEntry;

/**
 *  Maximum of virtual beacons supported.
 */
extern int const    kB4SMaxVirtualBeacons;

/**
 *  Minimum delay between each query of configurations. This parameter is only used
 * on move detection.
 */
extern int const    kB4SMinimumDurationBetweenConfigurationDownloadRequest;

/**
 * Duration while the app is kept in background when no beacons are nearby
 */
extern int const    kB4SMaximumDurationWhileInBackgroundWithoutBeaconsAround;


extern NSString * const kB4SMainIdentifier;

/**
 *  B4S Geofence identifier
 */
extern NSString * const kB4SGeofenceIdentifier;

/**
 *  B4S Beacons UUID (shared by all beacons)
 */
extern NSString * const kB4SUuid;

#pragma mark - HTTP Header Fields

/**
 *  B4S Api Key Custom HTTP Header Field
 */
extern NSString    *const  kB4SHTTPHeaderFieldXB4SApiKey;

/**
 *  B4S App ID Custom HTTP Header Field
 */
extern NSString    *const  kB4SHTTPHeaderFieldXB4SAppID;

/**
 *  B4S Auth Token Custom HTTP Header Field
 */
extern NSString    *const  kB4SHTTPHeaderFieldXB4SAuthToken;

/**
 *  B4S User ID Custom HTTP Header Field
 */
extern NSString    *const  kB4SHTTPHeaderFieldXB4SUserID;


#pragma mark - HTTP Header Values

/**
 *  B4S Api Key
 */
extern  NSString        *const      kB4HTTPHeaderApiKey;

#endif

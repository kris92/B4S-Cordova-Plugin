//
//  B4SSingleton+Private.h
//  BeaconForStoreSDK
//
//  Created by Ezeeworld on 23/04/2014.
//  Copyright (c) 2014 Ezeeworld. All rights reserved.
//

@import Foundation;
@import UIKit;
@import CoreLocation;
#import "B4SSingleton.h"
#import "B4SBeacon+Private.h"

@class B4SStorageManager;
@class B4SSession;
@class B4SApplication;
@class B4SGroup;
@class B4SCategory;
@class B4SLiveBeacon;
@class B4SUserAccount;
@class B4SCustomerData;
@class B4SShop;
@class B4SBeacon;
@class B4SInteraction;
@class B4SUserProperties;
@class B4SSniffer;
@class NBInteractionEvent;

extern NSString *const kB4SMainConfigUpdateNotificationName;
extern NSString *const kB4SBeaconsListUpdatedNotification;
extern NSString *const kB4SBeaconsChangedGeofencesNotification;


extern NSString    *const  kB4SConstRemoteIncomingNotificationID;
extern NSString    *const  kB4SConstRemoteIncomingNotificationType;
extern NSString    *const  kB4SConstRemoteIncomingNotificationData;

extern  NSString    *const  kB4SsDeviceUDID;
extern  NSString    *const  kB4SsDeviceModel;
extern  NSString    *const  kB4SsDeviceOs;
extern  NSString    *const  kB4SsOsVersion;

extern NSString    *const      kB4SUserPropertyApplicationSDKLocalNotificationsEnabled;
extern NSString    *const      kB4SUserPropertyApplicationSDKRemoteNotificationsEnabled;
extern NSString    *const      kB4SUserPropertyApplicationSDKVersion;
extern NSString    *const      kB4SUserPropertyDeviceAdvertisingTrackingValue;
extern NSString    *const      kB4SUserPropertyDeviceAdvertisingTrackingEnabled;
extern NSString    *const      kB4SUserPropertyDeviceModel;
extern NSString    *const      kB4SUserPropertyDeviceOsName;
extern NSString    *const      kB4SUserPropertyDeviceOsVersion;
extern NSString    *const      kB4SUserPropertyDeviceCarrier;
extern NSString    *const      kB4SUserPropertyDeviceWifiEnabled;
extern NSString    *const      kB4SUserPropertyDeviceWatchCount;
extern NSString    *const      kB4SUserPropertyDeviceStorageTotal;
extern NSString    *const      kB4SUserPropertyDeviceStorageFree;

extern NSString *const kB4SInteractionsRefreshed;
@protocol B4SPrivateDelegate <NSObject>

typedef NS_ENUM(NSUInteger, B4SLoginResponseStatus)
{
    B4SLoginResponseStatusSuccess = 0,
    B4SLoginResponseStatusInvalidLogin = 1,
    B4SLoginResponseStatusError = 2
};

@optional
- (void)beaconInfos:(B4SBeacon *)beacon;
- (void)beaconsInRange:(NSArray *)beacons
               nearest:(B4SBeacon *)aBeacon;
- (void)notify:(UILocalNotification *)notification;
@end


typedef NS_ENUM(NSUInteger, B4SEnvironment)
{
    B4SEnvironmentProduction,
    B4SEnvironmentPreProd,
    B4SEnvironmentDevelopment
};

/*
 * B4SEnvironment as a NSString
 * @return Returns a B4SEnvironment as a human-readable string
 */
NSString        *stringForB4SEnvironment(B4SEnvironment environment);


@interface B4SSingleton () <UINavigationControllerDelegate, UIImagePickerControllerDelegate>

/*
 * Returns a human-readable version string: x.y.x-<build #>-<branch> / <git hash>
 */
+ (NSString *)versionString;

/*
 * Returns a human-readable short version string: x.y.x-<build #>
 */
+ (NSString *)shorVersionString;

/**
 *  AF Request timeout
 */
@property int                 requestTimeout;
@property (nonatomic) Boolean manageStatEvents;
@property (nonatomic, retain) NSString *appId;
@property (nonatomic, retain) NSString *clientId;
@property (nonatomic, retain) NSString *userId;
@property (nonatomic, retain) NSString *pinCode;
@property (nonatomic, retain) NSString *authToken;
@property int                 keyChainAccessReturnCode;

@property   (nonatomic, retain) B4SUserProperties   *userProperties;

/**
 * CoreData instance
 */
@property (nonatomic, retain) B4SStorageManager *storageManager;


/// Returns the current environment
- (B4SEnvironment)environment;

/**
 *  Latest location of the ios device
 */
@property (nonatomic, retain) CLLocation *location;

/**
 * Callby the sniffer when location changed. Return true if we leaved the current
 * bounding box.
 */
- (BOOL)setLatestLocation:(CLLocation *)location
         withAverageSpeed:(float)aSpeed
            andSpeedIndex:(int)aSpeedIndex;


/**
 *  Set the server to send the API requests to. If this method is called *after* the B4SSingleton has already been initialised, the app will exit. The newly set environment will be used on next launch
 */
+ (void)setEnvironment:(B4SEnvironment)environment;

/**
 *  The base URL for API calls
 * Current values:  @"https://api.beaconforstore.com/api/v1/sdk”, @“http://api.preprod.beaconforstore.com/api/v1/sdk" and @"http://api.dev.beaconforstore.com/api/v1/sdk";
 *  @return Returns the base URL to prepend to API calls. This is *not* terminated with a forward slash
 */
- (NSString *)apiBaseURL;

/**
 *  Enable or disable use of the IDFA for tracking purposes.
 *  Default value is TRUE
 */
@property   (nonatomic)     BOOL    useIDFA;

/**
 * Clear customer journey
 */
- (long)clearCustomerJourney;

@property (nonatomic) Boolean demonstrationMode;
@property (nonatomic) BOOL adminMode;

/**
 *  Set this property to true to accelerate immediate beacon detection
 *  When detecting a beacon the Kalman filter is initialised with a close distance to bias distance computation. If a beacon is indeed close to the device, its proper distance is computed faster
 */
@property (nonatomic) BOOL favorCloseBeaconDistanceForRanging;

- (void)queryAppPinCode:(void (^)(NSString *pinCode))completion;
- (void)pinCodeLogin:(NSString *)pinCode
          completion:(void (^)(B4SApplication *app))completion;
- (void)appSwap:(NSString *)appId;
- (void)accountInfos:(void (^)(Boolean success, B4SUserAccount *accountInfos))completion ;
+ (B4SSingleton*) setupSharedInstanceWithAppId:(NSString *)anAppId
                                     adminMode:(BOOL)isAdminMode;
+ (B4SSingleton*) setupSharedInstanceWithAppId:(NSString *)anAppId
                                   andClientId:(NSString *)clientId
                                     adminMode:(BOOL)isAdminMode;
- (void)deleteBeaconWithInnerName:(NSString *)innerName completion:(void (^)(Boolean success))completion;

/**
 * Force quit background application if she was still active since 30s and no beacons are nearby.
 */
- (void) stopApplicationIfPossible;

- (void)stopRangingBeacon;
- (BOOL)startBeaconModeWithMajor:(int)aMajor andMinor:(int)aMinor andType:(B4SBeaconType)newType andBatteryLevel:(unsigned int)newBatteryLevel;
- (BOOL)stopBeaconMode;
- (void)fullAppsList:(void (^)(NSArray<B4SApplication *> *apps))completion;
- (void)createAccount:(NSString *)anEmail
             password:(NSString *)aPassword
            firstName:(NSString *)aFirstName
             lastName:(NSString *)aLastName
               street:(NSString *)aStreet
              zipCode:(NSString *)aZipCode
                 city:(NSString *)aCity
              country:(NSString *)aCountry
                phone:(NSString *)aPhone
              company:(NSString *)aCompany
           completion:(void (^)(Boolean success, Boolean alreadyExists))completion;
- (void)updateAccount:(B4SUserAccount *)account
           completion:(void (^)(Boolean success))completion;
//- (void)waitForClosestBeacon;
- (void)lostPassword:(NSString *)anEmail
          completion:(void (^)(Boolean success, Boolean unknownEmail))completion;

- (void)loginWithEmail:(NSString *)email andPassword:(NSString *)password completion:(void (^)(B4SLoginResponseStatus status, NSString *errorMessage))completion;
- (void)logout;
- (void)regionStatusUpdate:(CLRegion *)region;
- (void)resetInteractionsCache;
- (void)clearInteractionsCache;
- (void)didRangeBeacons:(NSArray *)beacons inRegion:(CLBeaconRegion *)region;
- (Boolean)isAuthentified;
- (void)startTimer;
- (void)stopTimer;

- (void)saveApplication:(B4SApplication *)anApplication
             completion:(void (^)(Boolean success))completion;
- (void)deleteAplication:(B4SApplication *)application
              completion:(void (^)(Boolean success))completion;
- (void)saveGroup:(B4SGroup *)group
       completion:(void (^)(Boolean success))completion;
- (void)deleteGroup:(B4SGroup *)group
         completion:(void (^)(Boolean success))completion;
- (void)saveShop:(B4SShop *)shop
      completion:(void (^)(Boolean success))completion;
- (void)deleteShop:(B4SShop *)shop
        completion:(void (^)(Boolean success))completion;
- (void)saveCategory:(B4SCategory *)category
          completion:(void (^)(Boolean success))completion;
- (void)deleteCategory:(B4SCategory *)category
            completion:(void (^)(Boolean success))completion;

- (void)saveInteraction:(B4SInteraction *)interactiona
             completion:(void (^)(Boolean success))completion;
- (void)deleteInteraction:(B4SInteraction *)interaction
               completion:(void (^)(Boolean success))completion;

- (void)setApplicationValidityStatus:(BOOL)aStatus;
- (void)updateBeacon:(B4SBeacon *)beacon;
- (void)dbRefreshTest:(CLLocation *)location
               beacon:(B4SLiveBeacon *)beacon
                cause:(B4SConfigUpdateCause)aCause;

- (void)fullInteractionsList:(void (^)(NSDictionary<NSString *, B4SInteraction *> *interactions))completion;

- (B4SNetworkStatus)networkStatus;
- (NSString *)networkStatusAsString;
- (BOOL)haveBluetooth;
- (Boolean)notifyScanForBeacon:(B4SBeacon *)aBeacon
                forInteraction:(B4SInteraction *)anInteraction
                asGeolocalized:(BOOL)geolocalized
                        inShop:(B4SShop *)aShop
        withInteractionSession:(NSString *)aSessionId
                      andDelay:(int)delayInSeconds
                   andAccuracy:(float)locationAccuracyInMeters;

- (void)sendExSessionData:(B4SSession *)session directly:(BOOL)isDirect;

+ (B4SSingleton*) setupSharedInstanceWithAppId:(NSString *)anAppId
                            notificationsSetup:(BOOL)notificationsEnabled;


/**
 If set to true, the interactions list will be set accordingly to the nearest beacon and not the phone location.
 */
- (void)setDemoMode:(BOOL)enabled;
/**
 Force configuration reload (even if already cached) and clear interactions counters.
 */
- (void)demoReset;

/**
 * Request iOS to keep application alive a bit more longer.
 */
- (void)rearmBackgroundMode;

/**
 *  This methods sends a /beaconFound to the B4S server (used to compute server-side the list of installed apps on the device
 This should be called when:
 - a beacon is found
 - the users enters a beacon region
 
 *  @param beaconName The beacon name as B4S:<major>:<minor> (if available). Is nil, an empty string is sent to the server
 */
- (void)sendBeaconFoundQueryWithBeaconName:(NSString *)beaconName;


/**
 *  Convert a B4SActionType to its string representation
 *
 *  @param type The action type
 *
 *  @return The actiontype string representation, or nil if the type is unknown
 */
NSString        *B4SActionTypeToString(B4SActionType type);

/**
 Enable notifications. A categories set can be specified.
 A default category identifier (B4S) is created for beacons notifications.
 */
- (void)notificationsSetup:(NSMutableSet *)categories;
/**
 Force full reload of interactions, groups, shops, beacons
 */
- (void)configRefresh:(B4SConfigUpdateCause)aCause;


/**
 Enable/Disable the SDK bluetooth warning message if Bluetooth is OFF
 */
- (void)setBluetoothWarnStatus:(BOOL)enabled;
/**
 Return the full beacons list
 */
- (void)fullBeaconsList:(void (^)(NSArray<B4SBeacon *> *beacons))completion;

typedef NS_ENUM(NSUInteger, B4SLiveBeaconInfoStatus) {
    B4SLiveBeaconInfoStatusBelongToAnotherCustomer,
    B4SLiveBeaconInfoStatusExistingBeacon,
    B4SLiveBeaconInfoStatusNewBeacon,
    B4SLiveBeaconInfoStatusError
};

/**
 *  Get infos on a B4SLiveBeacon
 *
 *  @param beacon     The detected beacon
 *  @param completion The completion block. If infoStatus is B4SLiveBeaconInfoStatusExistingBeacon, the beacon instance passed as a parameter is updated with the info fetched from the server, otherwise it is left untouched
 */
- (void)getLiveBeaconInfos:(B4SLiveBeacon *)beacon withCompletion:(void (^)(B4SLiveBeacon *beacon, B4SLiveBeaconInfoStatus infoStatus))completion;

- (void)registerBeacon:(B4SBeacon *)aBeacon
              withName:(NSString *)aName
           description:(NSString *)beaconDescription
              category:(B4SCategory *)aCategory
                 group:(B4SGroup *)aGroup
                  shop:(B4SShop *)aShop
            completion:(void (^)(B4SBeacon *beacon, BOOL result))completion;

- (void)showDebugMap:(id)sender;
- (void)closeDebugMap:(id)sender;

@property (nonatomic, retain) B4SSniffer *sniffer;
/**
 *  Fetch all interaction history from the DB. Returns nil if logInteractionHistoryToDatabase == FALSE (or was == FALSE during previous runs)
 *
 *  @return Returns the complete interaction history
 */
- (NSArray <NBInteractionEvent *>*)allInteractionHistoryEvents;

/**
 *  Fetch interaction history in time range. Returns nil if logInteractionHistoryToDatabase == FALSE (or was == FALSE during previous runs)
 *
 *  @param beforeDate The end of the time period
 *  @param afterDate  The start of the time period
 *
 *  @return ALl the fetched events
 */
- (NSArray <NBInteractionEvent *>*)interactionHistoryEventsBeforeDate:(NSDate *)beforeDate andAfterDate:(NSDate *)afterDate;

/**
 *  Purge the interaction history
 *
 *  @return Returns NO if an error occurs, YES otherwise
 */
- (BOOL)clearInteractionHistory;

/**
 * Request additional background time to iOS IF
 * • ATM mode is requested
 * • WIFI is disabled.
 * This method helps us to maintain app alive in background.
 */
- (void)rearmBackgroundModeForTrackingWhenNoWifi;

/**
 *  Enable interaction history. This will store all played interactions in a local CoreData DB. If needed, this MUST be set to TRUE BEFORE startStandaloneMode: (otherwise interactions played before won't be stored)
 Default value is FALSE
 */
@property (assign) BOOL logInteractionHistoryToDatabase;

@end

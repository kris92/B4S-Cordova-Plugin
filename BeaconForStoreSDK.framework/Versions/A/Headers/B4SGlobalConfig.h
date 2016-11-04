//
//  BeaconForStoreSDK.h
//  BeaconForStoreSDK 
//
//  Created by Ezeeworld on 23/04/2014.
//  Copyright (c) 2014 Ezeeworld. All rights reserved.
//

@import Foundation;
@import CoreLocation;
#import "B4SEnums.h"

@class B4SShop;
@class B4SMotionDetector;
@class B4SDeviceCalibration;

typedef NS_ENUM(NSInteger, B4SRemoteLoggingLevel) {
    B4SRemoteLoggingLevel_NO,
    B4SRemoteLoggingLevel_ERRORS,
    B4SRemoteLoggingLevel_WARNINGS,
    B4SRemoteLoggingLevel_INFO,
    B4SRemoteLoggingLevel_DEBUG
};

typedef NS_ENUM(NSInteger, B4SRemoteLoggingMedium) {
    B4SRemoteLoggingMedium_ALL,
    B4SRemoteLoggingMedium_WIFI_ONLY,
    B4SRemoteLoggingMedium_WWAN_ONLY,
    B4SRemoteLoggingMedium_LOCAL_ONLY
};

typedef NS_ENUM(NSInteger, B4SLogStatus) {
    B4SLogStatus_NO,
    B4SLogStatus_REMOTE,
    B4SLogStatus_LOCAL
};

@interface B4SGlobalConfig : NSObject

/**
 *  Cache validity in minutes
 */
@property (readonly) NSNumber *beaconsCacheValidity; // In minutes
@property (nonatomic, strong) NSString *appId;
@property (nonatomic, strong) NSString *clientId;
@property (readonly) NSString *udid;
@property (readonly) NSNumber *backgroundTimeout;
@property (readonly) NSNumber *geofencingRadius;
@property (readonly) NSString *beaconsUuid;
@property (nonatomic) float mapHeading;

/**
 *   TRUE if the SDK should only send data when connected to a WiFi network
 */
@property (readonly) BOOL wifiOnlyUpload;

/**
 *  TRUE if the SDK should only send data when connected to a power source
 */
@property (readonly) BOOL pluggedOnlyUpload;

@property (readonly)   NSUInteger locationTrackingMaxUploadSize;
@property (readonly)   NSUInteger locationTrackingHistorySize;
@property (readonly)   NSUInteger locationTrackingMaxRecordsToKeep;
@property (readonly)   NSUInteger locationTrackingUploadInterval;


@property (readonly) NSNumber *scanSampleRate; // Sample rate used to send passive scan record to the back
@property (nonatomic, strong) CLLocation *currentGPSLocation;

@property (nonatomic, strong) NSDictionary *keychain;
/**
 * Side length of the bounding box we are collecting coordinates inside.
 */
@property (nonatomic) long boundingBoxSideLength;
/**
 * We only record coordinates if the user move more than locationTrackingMinRequiredDisplacementInMeters since
 * last record.
 */
@property (nonatomic) long minDistanceBetweenUserCoords;
/**
 * We only record coordinates if the last record was inserted more than locationTrackingMinRequiredTimeInSeconds ago.
 */
@property (nonatomic) long minTimeBetweenUserCoords;

/**
 * TRUE if location tracking is enabled by the server. Default value is NO
 */
@property (readonly) BOOL enablePositionTrackingFromServer;

/**
 * TRUE if location tracking is enabled. Default value is YES. Use this to override the value set by the server. This value is ignored if enablePositionTrackingFromServer == FALSE
 */
@property (nonatomic) BOOL enablePositionTracking;



@property   (readonly) NSUInteger   maxUserPropertyCount;

/**
 *  Is the device using a custom calibration to compute beacon distance
 */
@property   (readonly)      BOOL    isDeviceCalibrated;

/**
 *  Radius of beacons to be downloaded, in meters
 */
@property (readonly) NSNumber *radius; 

- (instancetype)initWithBaseURL:(NSString *)anUrl applicationId:(NSString *)anAppId adminMode:(BOOL)isAdminMode;
- (BOOL)areParametersUptodate;
- (void)getApplicationData:(void (^)(NSError *error))completion;
- (BOOL)configurationLoaded;
- (void)clearCache;
- (BOOL)cacheExists;

- (B4SLogStatus)loggingForLevel:(B4SRemoteLoggingLevel)level;

- (B4SDeviceCalibration *)getDeviceTxForLevel:(NSInteger)level
                               andBeaconModel:(NSString *)beaconHardwareModel;

- (void)queryAdminSetup;

- (void)getNearestShopAtLongitude:(float)aLongitude andLatitude:(float)aLatitude completion:(void (^)(B4SShop *shop))completion;
/**
 *  Test if the given shop is inside the configuration radius centered to the device
 *
 *  @param shop Shop object to test
 *
 *  @return True if the shop is inside
 */
- (BOOL)isShopInsideConfigurationRadius:(B4SShop *)shop;

+ (B4SGlobalConfig*) sharedInstance;
+ (B4SGlobalConfig*) setupSharedInstanceWithBaseURL:(NSString *)anUrl
                                      applicationId:(NSString *)anAppId
                                          adminMode:(BOOL)isAdminMode;

- (void)queryRegistrationParamsWithCompletion:(void (^)(void))completion;
@end

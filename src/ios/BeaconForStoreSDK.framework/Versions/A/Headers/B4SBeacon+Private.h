//
//  B4SBeacon+Private.h
//  BeaconForStoreSDK
//
//  Created by Ezeeworld on 23/04/2014.
//  Copyright (c) 2014 Ezeeworld. All rights reserved.
//

@import Foundation;
@import CoreLocation;
#import "B4SBeacon.h"

@class B4SInteraction;
@class B4SExSession;

typedef NS_ENUM(NSInteger, B4SBeaconType) {
    B4SBeaconTypeUnknown,
    B4SBeaconTypeBattery = 1,
    B4SBeaconTypeUSB = 2,
    B4SBeaconTypeLongRange = 3,
    B4SBeaconTypeConnected = 4,
    B4SBeaconTypeLongRangeUSB = 5,
    B4SBeaconTypeSoftware = 6
} ;

/**
 *  Returns a string describing a beacon type
 *
 *  @param type a B4SBeaconType value
 *
 *  @return Returns a string describing a beacon type
 */
NSString        *stringForB4SBeaconType(B4SBeaconType type);



@interface B4SBeacon ()

/**
 *  Init a B4SBeacon with the dictionary received from /api/v1/sdk/listBeacons
 *
 *  @param dictionary The received dictionary
 *
 *  @return The new beacon
 */
- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

- (instancetype)initWithInnerName:(NSString *)aInnerName andMajor:(long)aMajor andMinor:(long)aMinor ;
- (instancetype)initWithInnerName:(NSString *)innerName;
- (instancetype)initWithMajor:(long)aMajor andMinor:(long)aMinor;

@property (nonatomic, retain) NSString *beaconId;
@property   (readonly) B4SBeaconType   type;

@property (nonatomic, retain) NSString * shopId;

@property (nonatomic) float smoothedRssi;
@property (nonatomic) int rawBattLevel;
@property (nonatomic, retain) NSString *swVersion;


@property (nonatomic) int notificationsCounter;
@property (nonatomic) int notificationConsecutiveTicks;

@property   (nonatomic, strong) NSString    *beaconDescription;

@property (nonatomic) BOOL batteryUpdateNeeded;
@property (nonatomic) BOOL batteryLevelUpdated;
/**
 *  broadcast interval value broadcasted by the beacon
 */
@property (nonatomic) NSInteger currentBroadcastInterval;
/**
 *  beacon color value broadcasted by the beacon
 */
@property (nonatomic) NSInteger currentColor;
/**
 *  beacon xmit power level value broadcasted by the beacon
 */
@property (nonatomic) NSInteger currentPowerLevel;
/**
 *  Requested beacon broadcast interval in ms. If the beacon is seen with another value it will be updated
 */
@property (nonatomic) NSInteger requestedBroadcastInterval;
/**
 *  Requested beacon xmit power level. If the beacon is seen with another value it will be updated
 */
@property (nonatomic) NSInteger requestedPowerLevel;

@property   (nonatomic) NSDate  *firstEventDate;
@property (nonatomic, retain) NSString * beaconPushSoundname;

- (void)refreshMajorAndMinor;
- (void)clearInteractions;
- (void)addInteraction:(B4SInteraction *)anInteraction;

+ (NSString *)beaconKeyWithMajor:(long)aMajor andMinor:(long)aMinor;
+ (NSString *)beaconKeyWithBeacon:(B4SBeacon *)aBeacon;
+ (void)removeBeaconWithInnerName:(NSString *)innerName;
+ (void)convertHexString:(NSString *)aString toMajor:(int *)aMajor minor:(int *)aMinor;
+ (B4SBeacon *)addBeacon:(B4SBeacon *)aBeacon;
+ (B4SBeacon *)getBeaconWithInnerName:(NSString *)aBeaconInnerName;
+ (void)clear;

+ (NSDictionary *)databaseProperties;
@end


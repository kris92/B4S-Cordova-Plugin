//
//  B4S_Beacon.h
//  BeaconForStoreSDK
//
//  Created by Ezeeworld on 12/03/2014.
//  Copyright (c) 2014 Ezeeworld. All rights reserved.
//

@import Foundation;
@import CoreData;
@import CoreBluetooth;
@import CoreLocation;

#import "B4SBeacon.h"

@class B4SMotionDetector;
@class B4SGroup;
@class B4SShop;
@class B4SInteraction;
@class B4SGlobalConfig;

typedef void(^B4SBeaconResult)(NSError *error);

@interface B4SLiveBeacon : B4SBeacon

@property (nonatomic, retain) NSString * categoryId;
@property (nonatomic, retain) NSString * groupId;
@property (nonatomic, retain) NSString * country;

@property (nonatomic) int   activeChannel;

/**
 *  Last computed distance between the beacon and the last current location
 *  (for a virtual beacons only)
 */
@property (nonatomic) float   lastComputedNotificationDistance;

/**
 *  TX power for the device
 */
@property (nonatomic) int   txPower;

/**
 *  PassLoss for the device
 */
@property (nonatomic) float   pathLoss;

/**
 *  Hardware model used to query the tx
 */
@property (nonatomic, retain) NSString *hardwareModel;

/**
 * Coordinates based index
 */
@property (nonatomic, strong) NSString *compositeCoordinateIndex;
@property (nonatomic) float roundedLat;
@property (nonatomic) float roundedLon;

- (instancetype)initAsVirtualBeaconWithInnerName:(NSString *)vBeaconInnerName
                                     andLocation:(CLLocation *)aLocation
                                       andRadius:(int)aRadius
                                         andName:(NSString *)aName;
- (instancetype)initWithMajor:(long)aMajor
                     andMinor:(long)aMinor;
- (void)addInteraction:(B4SInteraction *)interaction;
- (void)clear;
- (void)clearRssiValue;

+ (B4SLiveBeacon *)getBeaconWithId:(NSString *)aBeaconId;

//- (NSString *)getCompositeIndex;
/**
 * Returns an index based on coordiantes pair. It is used for coordinates aggregation
 */
+ (NSString *)generateCompositeCoordinateIndex:(CLLocationCoordinate2D)aCoordinate;

- (float)computeNotificationDistanceFrom:(CLLocation *)currentLocation;
/** 
 * Compute distance index. This fast method is required when dealing with a large amount of locations
 */
- (float)fastComputeNotificationDistanceFrom:(CLLocation *)currentLocation;
/**
 *
 */
- (float)fastComputeNotificationDistanceFromGeohashCenterTo:(CLLocation *)currentLocation;
/**
 * Returns CLCircularRegion matching the virtual beacon.
 */
+ (CLCircularRegion *)circularRegionForCompositeIndex:(NSString *)aCompositeIndex;
/**
 * Returns a one virtual beacons located at a precise coordinate identified with a compositeIndex.
 */
+ (B4SLiveBeacon *)getOneBeaconAtCompositeIndex:(NSString *)aCompositeIndex;
/**
 * Returns a list of virtual beacons located at a precise coordinate identified with a compositeIndex.
 */
+ (NSMutableSet<B4SLiveBeacon *> *)virtualBeaconsAtCompositeIndex:(NSString *)aCompositeIndex;
/**
 * Returns all geohashes
 */
+ (NSArray<B4SLiveBeacon *> *)getGeoHashesNear;
/**
 * Returns a filtered list of virtual beacons which are near a given position.
 * We use a very basic geocoding approach to obtains a list of virtual beacons.
 */
+ (NSSet<B4SLiveBeacon *> *)virtualBeaconsNear:(CLLocation *)currentCoordinates;
+ (NSSet<B4SLiveBeacon *> *)virtualGeoHashNear:(CLLocation *)currentLocation;
+ (NSSet<B4SLiveBeacon *> *)virtualBeaconsNearestFromLocation:(CLLocation *)currentLocation;
/**
 *  The number of beacons
 *
 *  @return Returns the number of beacons
 */
+ (NSUInteger)count;
+ (void)clear;
+ (void)clearVBeacons;
+ (void)clearRssiValues;

+ (NSSet<B4SLiveBeacon *> *)virtualBeacons;
+ (NSArray<B4SLiveBeacon *> *)beacons;
+ (BOOL)isB4SDevice:(NSString *)aName;
+ (B4SLiveBeacon *)addVirtualBeacon:(B4SLiveBeacon *)aBeacon;
+ (B4SLiveBeacon *)addBeaconWithMajor:(long)aMajor
                             andMinor:(long)aMinor;
+ (B4SLiveBeacon *)addBeaconWithBeaconName:(NSString *)aName
                           andMajorString:(NSString *)majorString
                            andMinorString:(NSString *)minorString
                                 andPower:(int)beaconPowerLevel
                    andAdvertisingInterval:(int)advertisingInterval
                                  andModel:(NSString *)beaconHardwareModel;
+ (B4SLiveBeacon *)getBeaconWithInnerName:(NSString *)key;
+ (NSArray<B4SLiveBeacon *> *)getSortedBeaconsList;
+ (B4SLiveBeacon *)getApplicationNearestBeacon;
+ (B4SLiveBeacon *)getNearestBeacon;

/**
 *  Get the beacons (including unregistered beacons and beacons belonging to another customer) detected by the device with a range
 *
 *  @param rangeInCentimeters The range to filter the beacons
 *  @return An Array of B4SLiveBeacons sorted by distance or nil if there are no immediate beacons
 */
+ (NSArray<B4SLiveBeacon *> *)allBeaconsWithRange:(int)rangeInCentimeters;

+ (void)unsetBeaconsWithCategory:(NSString *)categoryId;
+ (void)unsetBeaconsWithShop:(NSString *)shopId;
+ (void)unsetBeaconsWithGroup:(NSString *)groupId;

- (float)recordRssi:(float)rssi;

- (float)computeDistance;

- (void)updateBeaconWithBroadcastInterval:(NSInteger)anIntervalInMs
                               andTxPower:(NSInteger)aPowerInDb
                            forPeripheral:(CBPeripheral *)aPeripheral
                            withBTManager:(CBCentralManager *)btManager
                     andBTManagerDelegate:(id)aDelegate
                                   result:(B4SBeaconResult)result;
- (void) connectOnPeripheral:(CBPeripheral *)aPeripheral
                  andManager:(CBCentralManager *)btManager
                      result:(B4SBeaconResult)result;
/**
 *  Send AT command to beacon
 *
 *  @param command full ATcommand
 *  @param result  callback
 */
- (void) sendCommand:(NSString *)command
              result:(B4SBeaconResult) result;
- (BOOL) isConnected;
- (void) disconnect:(B4SBeaconResult)result;

@end

//
//  B4SInteraction+Private.h
//  BeaconForStoreSDK
//
//  Created by Ezeeworld on 12/03/2014.
//  Copyright (c) 2014 Ezeeworld. All rights reserved.
//

@import Foundation;
@import CoreData;
@import CoreLocation;
#import "B4SInteraction.h"


@class B4SShop;
@class B4SLiveBeacon;
@class B4SStorageManager;
@class B4SCustomerJourneyStep;

typedef NS_ENUM(NSInteger, B4SInteractionDistanceModel) {
    B4SInteractionDistanceModel_STANDARD,
    B4SInteractionDistanceModel_LONGRANGE,
    B4SInteractionDistanceModel_GEOLOCIN,
    B4SInteractionDistanceModel_GEOLOCOUT
};


@interface B4SInteraction (PrivateGetters)

/*
 * The name of the campaign associated with an interaction
 */
@property (readonly) NSString *campaignName;
@end

@interface B4SInteraction ()
@property (nonatomic) int nextWaveDelay;
@property (nonatomic) BOOL wasOpened;
@property (nonatomic) BOOL sendOnlyIfNotOpened;
@property (nonatomic) BOOL autoUnlockEnabled;
@property (nonatomic) int notificationsCount;
@property (nonatomic, retain) NSDate *postponedNotificationDate;
@property (nonatomic) int distanceModel;
@property (nonatomic) BOOL bGeoNotifyIfBeacon;
@property (nonatomic) BOOL lockOnEnabled;
@property (nonatomic) long proximity;
@property (nonatomic) BOOL isIncomingInteraction;
@property (nonatomic) BOOL isOutgoingInteraction;
@property (nonatomic, retain) NSDate * startDate;
@property (nonatomic, retain) NSDate * endDate;
@property (nonatomic) NSInteger startTime;
@property (nonatomic) NSInteger endTime;
@property (nonatomic, retain) NSDate * lastScanDate;
@property (nonatomic, retain) NSString *checksum;
@property (nonatomic, retain) NSDate * creationDate;
@property (nonatomic, assign) B4SInteractionType type;
@property (nonatomic, assign) B4SNotificationType notificationType;
@property (nonatomic, retain) B4SCustomerJourneyStep* customerJourneyStep;
@property (nonatomic, retain) NSDate *futureNotificationDate;


/**
 Shops Categories to the interaction
 */
@property (nonatomic, strong) NSMutableDictionary *categories;
/**
 Groups associated to the interaction
 */
@property (nonatomic, strong) NSMutableDictionary *groups;
/**
 Shops associated to the interaction
 */
@property (nonatomic, strong) NSMutableDictionary *shops;

/*
  Init a new Interaction with the values received from the /interactionsList query
 */
- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

/**
 * Test if given beacon is inside interaction range.
 */
-(BOOL)testRangeIn:(B4SLiveBeacon *)aBeacon;
/**
 * Test if given beacon is outside interaction range.
 */
-(BOOL)testRangeOut:(B4SLiveBeacon *)aBeacon;
/**
 * Test time and date condition.
 */
-(BOOL)testTimeAndDateConditions:(B4SStorageManager *)aStorage;

- (void)addCategory:(NSString *)category;
- (void)addGroup:(NSString *)group;
- (void)addShop:(NSString *)shop;
- (BOOL)hasCategory:(NSString *)category andGroup:(NSString *)group orShop:(NSString *)shop;
+ (B4SInteraction *)getLocalInteractionById:(NSString *)anInteractionId;
+ (B4SInteraction *)addInteraction:(B4SInteraction *)anInteraction;
+ (NSDictionary<NSString *, B4SInteraction *> *)fullInteractionsTable;
+ (NSString *)md5;
/**
 * Clear all interactions counters
 */
+ (void)clearInteractionsCounters;
+ (void)setMD5:(NSString *)md5;
- (void)removeReference;
+ (void)unsetInteractionsWithCategory:(NSString *)categoryId;
+ (void)unsetInteractionsWithShop:(NSString *)shopId;
+ (void)unsetInteractionsWithGroup:(NSString *)groupId;
+ (void)clearInteractions;

@end

B4SInteractionType      interactionTypeForString(NSString *string);
B4SNotificationType      notificationTypeForString(NSString *string);

/// Return the human-readable string for a B4SInteractionType, in english
NSString        *stringForInteractionType(B4SInteractionType type);


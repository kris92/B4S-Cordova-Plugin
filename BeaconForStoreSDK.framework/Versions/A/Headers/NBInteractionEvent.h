//
//  NBInteractionEvent.h
//  BeaconForStoreSDK
//
//  Created by Francois Reboursier on 12/05/16.
//  Copyright © 2016 Ezeeworld. All rights reserved.
//

@import Foundation;
@import CoreData;
@import CoreLocation;

#import "B4SInteraction.h"
NS_ASSUME_NONNULL_BEGIN

@interface NBInteractionEvent : NSObject

@property (nonatomic)   NSInteger       rowID;
@property (nonnull, nonatomic, retain) NSString *campaignName;
@property (nonnull, nonatomic, retain) NSDate *date;
@property (nonnull, nonatomic, retain) NSString *identifier;
@property (nonnull, nonatomic, retain) NSString *interactionName;
@property (nonnull, nonatomic, retain) NSNumber *latitude;
@property (nonnull, nonatomic, retain) NSNumber *locationAccuracy;
@property (nonnull, nonatomic, retain) NSNumber *longitude;
@property (nonnull, nonatomic, retain) NSString *message;
@property (nonnull, nonatomic, retain) NSNumber *notificationType;

@property (nonnull, nonatomic, retain) NSNumber *interactionType;

@property (nonnull, nonatomic, retain) NSNumber *radius;
/**
 *  The radius really used to trigger the virtual beacon interaction, that is with a margin
 */
@property (nonnull, nonatomic, retain) NSNumber *actualRadius;
@property (nonnull, nonatomic, retain) NSString *shopCity;
@property (nonnull, nonatomic, retain) NSNumber *shopLatitude;
@property (nonnull, nonatomic, retain) NSNumber *shopLongitude;
/**
 *  TRUE for zone / beacon enter, FALSE for exit
 */
@property (nonnull, nonatomic, retain) NSNumber *incoming;
@property (nonnull, nonatomic, retain) NSString *shopName;
@property (nonnull, nonatomic, retain) NSString *shopZipCode;


/**
 *  Check if an interaction is passive
 *
 *  @return Returns TRUE if notificationType == 
 */
- (BOOL)isPassive;
- (CLLocation *)interactionLocation;
- (CLLocation *)shopLocation;
- (NSNumber *)radiusInMeters;
- (B4SInteractionType)type;
- (NSNumber *)actualRadiusInMeters;

/**
 *  Interaction direction
 *
 *  @return YES for zone enter, FALSE for zone exit
 */
- (BOOL)isIncoming;

+ (NSDictionary *)databaseProperties;

@end

NS_ASSUME_NONNULL_END

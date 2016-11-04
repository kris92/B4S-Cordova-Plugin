//
//  B4SShop+Private.h
//
//  Created by Ezeeworld on 19/03/2014.
//  Copyright (c) 2014 Fanny Renauld. All rights reserved.
//

@import Foundation;
@import CoreLocation;
#import "B4SShop.h"

@class B4SGroup;

@interface B4SShop ()

@property (nonatomic) float defaultTxPower;
@property (nonatomic) float defaultPathLoss;
@property (nonatomic) float txPowerBatteryCompensation;
@property (nonatomic) float txPowerTemperatureCompensation;
@property (nonatomic) float nMapHeading;
@property (nonatomic, retain) CLLocation *location;

@property (nonatomic, retain) NSString *sSSID;
@property (nonatomic, retain) NSString *sKey;

- (instancetype)initWithDictionary:(NSDictionary *)shopDict;
+ (B4SShop *)addShop:(B4SShop *)aShop;
- (void)removeReference;
+ (void)unsetShopsWithGroupId:(NSString *)groupId;
+ (void)clear;
+ (void)setNearestShop:(B4SShop *)shop;
- (BOOL)isEqualToShop:(B4SShop *)shop;
@end

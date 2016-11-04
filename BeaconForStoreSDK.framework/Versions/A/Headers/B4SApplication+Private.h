//
//  B4SApplication.h
//  BeaconForStoreSDK
//
//  Created by Ezeeworld on 21/07/2014.
//  Copyright (c) 2014 Ezeeworld. All rights reserved.
//

@import Foundation;

#import "B4SApplication.h"
@interface B4SApplication ()
@property (nonatomic, retain) NSString *clientId;
@property (nonatomic, retain) NSString *bundleId;
@property (nonatomic, retain) NSString *pinCode;
@property (nonatomic, retain) NSString *brandName;
@property (nonatomic, retain) NSString *brandPictureId;
@property (nonatomic) NSInteger radius;


+ (B4SApplication *)addApplication:(B4SApplication *)anApplication;
- (void)removeReference;
+ (void)saveApplication:(B4SApplication *)anApplication
             completion:(void (^)(Boolean success))completion;
+ (void)removeApplication:(B4SApplication *)anApplication
               completion:(void (^)(Boolean success))completion;
+ (void)removeApplicationById:(NSString *)anApplicationId
                   completion:(void (^)(Boolean success))completion;

+ (void)clear;

@end

//
//  ResourcesManager.h
//  BeaconForStoreSDK
//
//  Created by Ezeeworld on 13/11/2014.
//  Copyright (c) 2014 Ezeeworld. All rights reserved.
//

@class B4SResource;

static NSString *kB4SResourceTypeImage = @"IMG";
static NSString *kB4SResourceTypeBrandImage = @"BRD";
static NSString *kB4SResourceTypeSound = @"SND";

@interface B4SResourcesManager : NSObject

@property (nonatomic, retain) NSString *clientId;
@property (nonatomic, retain) NSString *appId;

- (void)setUserId:(NSString *)userId andAuthToken:(NSString *)authToken;
+ (BOOL)saveResource:(B4SResource *)resource completion:(void (^)(NSString *resId))completion;
+ (BOOL)updateName:(B4SResource *)resource completion:(void (^)(BOOL success))completion;
+ (BOOL)removeResource:(B4SResource *)resource completion:(void (^)(BOOL success))completion;
+ (void)resourcesOfType:(NSString *)aType completion:(void (^)(BOOL success))completion;
+ (B4SResourcesManager*) sharedInstance;

@end

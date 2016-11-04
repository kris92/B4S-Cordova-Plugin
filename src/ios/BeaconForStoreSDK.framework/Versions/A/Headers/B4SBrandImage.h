//
//  B4SBrandImage.h
//  BeaconForStoreSDK
//
//  Created by Ezeeworld on 10/06/2015.
//  Copyright (c) 2015 Ezeeworld. All rights reserved.
//

@import UIKit;
#import "B4SResource.h"

@interface B4SBrandImage : B4SResource

@property (nonatomic, retain) UIImage *image;
@property (nonatomic, retain)   NSDate  *date;

- (instancetype)initWithImage:(UIImage *)anImage andName:(NSString *)aName;
- (instancetype)initWithDictionary:(NSDictionary *)dictionary;
- (BOOL)save:(void (^)(NSString *resId))completion;
- (BOOL)update:(void (^)(BOOL success))completion;
- (void)remove:(void (^)(BOOL success))completion;
+ (void)addImage:(B4SBrandImage *)anImage;
+ (void)load:(void (^)(NSSet *images))completion;
+ (int)count;
+ (void)clear;
+ (NSArray<B4SBrandImage *> *)images;

/**
 *  Get the most recent image
 *
 *  @return Most recent image
 */
+ (B4SBrandImage *)getMostRecentImage;
+ (B4SBrandImage *)getImageWithName:(NSString *)imageName;

@end

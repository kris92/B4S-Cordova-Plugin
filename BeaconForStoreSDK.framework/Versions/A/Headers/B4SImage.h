//
//  B4SImage.h
//  BeaconForStoreSDK
//
//  Created by Ezeeworld on 13/11/2014.
//  Copyright (c) 2014 Ezeeworld. All rights reserved.
//

@import UIKit;
#import "B4SResource.h"

@interface B4SImage : B4SResource

@property (nonatomic, retain) UIImage *image;

- (instancetype)initWithImage:(UIImage *)anImage andName:(NSString *)aName;
- (BOOL)save:(void (^)(NSString *resId))completion;
- (BOOL)update:(void (^)(Boolean success))completion;
- (void)remove:(void (^)(Boolean success))completion;
+ (void)addImage:(B4SImage *)anImage;
+ (void)load:(void (^)(NSSet *images))completion;
+ (int)count;
+ (void)clear;
+ (NSArray<B4SImage *> *)images;
+ (NSArray<B4SImage *> *)sortedImages;
+ (B4SImage *)getImage:(NSString *)imageName;

@end

//
//  B4SResource.h
//  BeaconForStoreSDK
//
//  Created by Ezeeworld on 13/11/2014.
//  Copyright (c) 2014 Ezeeworld. All rights reserved.
//

@import Foundation;

@interface B4SResource : NSObject

@property (nonatomic, retain) NSString *resId;
@property (nonatomic, retain) NSString *resName;
@property (nonatomic, retain) NSURL *resUrl;
@property (nonatomic, retain) NSData *resData;
@property (nonatomic, retain) NSString *resMD5;

@end

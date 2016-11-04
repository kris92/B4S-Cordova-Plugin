//
//  B4SDeviceCalibration.h
//  BeaconForStoreSDK
//
//  Created by Ezeeworld on 20/12/2014.
//  Copyright (c) 2014 Ezeeworld. All rights reserved.
//

@import Foundation;

@interface B4SDeviceCalibration : NSObject

@property (readonly) int txPower;
@property (readonly) float pathLoss;
@property (readonly) NSString  *beaconHardwareModel;
@property (readonly) NSInteger    beaconLevel;

- (instancetype)initWithBeaconHardwareModel:(NSString *)hardwareModel andBeaconLevel:(NSInteger)aBeaconLevel andTransmittedPower:(int)aTransmittedPower andPathLoss:(float)aPathLoss;
@end
//
//  B4SSDK.h
//  HelloWorld
//
//  Created by Christophe Janot on 22/10/2016.
//
//

#ifndef B4SSDK_h
#define B4SSDK_h

#import "APPAppEventDelegate.h"
#import <Cordova/CDVPlugin.h>
#import <BeaconForStoreSDK/BeaconForStoreSDK.h>

@interface B4SSDK : CDVPlugin <B4SDelegate,APPAppEventDelegate>

- (void)init:(CDVInvokedUrlCommand *)command;

@end

#endif /* B4SSDK_h */

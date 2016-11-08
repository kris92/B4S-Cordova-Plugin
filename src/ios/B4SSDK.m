//
//  B4SSDK.m
//  HelloWorld
//
//  Created by Christophe Janot on 22/10/2016.
//
//

#import <Foundation/Foundation.h>
#import "B4SSDK.h"
#import <Cordova/CDVPlugin.h>

@implementation B4SSDK

- (void)pluginInitialize {
    NSLog(@"[B4SSDK.pluginInitialize]");
    
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(finishLaunching:)
                                                 name:UIApplicationDidFinishLaunchingNotification
                                               object:nil];
}

- (void)init:(CDVInvokedUrlCommand *)command {
    NSLog(@"[B4SSDK.init]");
    
    CDVPluginResult* pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:@""];
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

- (void)finishLaunching:(NSNotification *)notification {
    NSLog(@"[B4SSDK.finishLaunching]");
    
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(notificationProcessed:)
                                                 name:kB4SNotificationProcessedNotification
                                               object:nil];
    
    NSString *appID = [[NSBundle mainBundle] objectForInfoDictionaryKey:@"NeerbyAppID"];
    B4SSingleton *b4sSingleton = [B4SSingleton setupSharedInstanceWithAppId:appID];
    
    b4sSingleton.delegate = self;
    [b4sSingleton setUserProperty:kB4SUserPropertyUsereMailKey withString:@"cja@ezeeworld.com"];
    
    [b4sSingleton startStandAloneMode];
}

- (void) didReceiveLocalNotification:(NSNotification*)localNotification
{
    UILocalNotification *notif = (UILocalNotification *)(localNotification.object);
    NSLog(@"B4SSDK.didReceiveLocalNotification : %@",notif.userInfo);
    
    [[B4SSingleton sharedInstance] notificationFeedback:notif.userInfo];
}

- (void)notificationProcessed:(UILocalNotification *)notificationData {
    
    int actionId = [[notificationData.userInfo objectForKey:kB4SNotifActionId] intValue];
    
    NSLog(@"notificationProcessed : %@",notificationData);
    NSLog(@"[notificationProcessed] beaconId=%@",[notificationData.userInfo objectForKey:kB4SNotifBeaconId]);
    NSLog(@"[notificationProcessed] beaconName=%@",[notificationData.userInfo objectForKey:kB4SNotifContentName]);
    NSLog(@"[notificationProcessed] distance=%@",[notificationData.userInfo objectForKey:kB4SNotifDistance]);
    NSLog(@"[notificationProcessed] interaction name=%@",[notificationData.userInfo objectForKey:kB4SNotifContentName]);
    NSLog(@"[notificationProcessed] interaction id=%@",[notificationData.userInfo objectForKey:kB4SNotifContentId]);
    NSLog(@"[notificationProcessed] text=%@",[notificationData.userInfo objectForKey:kB4SNotifText]);
    NSLog(@"[notificationProcessed] group clientRef=%@",[notificationData.userInfo objectForKey:kB4SNotifGroupRef]);
    NSLog(@"[notificationProcessed] store clientRef=%@",[notificationData.userInfo objectForKey:kB4SNotifStoreRef]);
    NSLog(@"[notificationProcessed] beacon clientRef=%@",[notificationData.userInfo objectForKey:kB4SNotifBeaconRef]);
    NSLog(@"[notificationProcessed] beacon udid=%@",[notificationData.userInfo objectForKey:kB4SBeaconUdid]);
    NSLog(@"[notificationProcessed] beacon major=%@",[notificationData.userInfo objectForKey:kB4SBeaconMajor]);
    NSLog(@"[notificationProcessed] beacon minor=%@",[notificationData.userInfo objectForKey:kB4SBeaconMinor]);
    NSLog(@"[notificationProcessed] actionId=%d",actionId);
    
    if(actionId == B4SActionType_INAPP) {
        NSString *pageId = [notificationData.userInfo objectForKey:kB4SNotifPageId];
        NSLog(@"[notificationProcessed] inapp pageId : %@",pageId);
    }
}

@end
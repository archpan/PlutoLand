//
//  UIDevice+PL.h
//  Apollo
//
//  Created by xhan on 10-10-22.
//  Copyright 2010 Baidu.com. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface UIDevice(PL)

+ (long long)getTotalDiskSpaceInBytes ;

+ (long long)getFreeDiskSpaceInBytes ;

- (NSString *) platform;
- (NSString *) platformString;

@property(nonatomic,readonly) BOOL isIOS5;  //deprecate
@property(nonatomic,readonly) BOOL isIOS5above;
@property(nonatomic,readonly) BOOL isIOS6above;
@property(nonatomic,readonly) BOOL isIOS7AndAbove;
@property(nonatomic,readonly) BOOL isIOS8AndAbove;

@property(readonly) NSString* currentVersion;
@property(readonly) NSString* currentBuild;

@property(readonly) BOOL isJailbreak;
@property(readonly) BOOL isIAPcrack;
@end

// ios7 beforel
@interface UIDevice (IdentifierAddition)
- (NSString *) macaddress;
/*
 * @method uniqueDeviceIdentifier
 * @description use this method when you need a unique identifier in one app.
 * It generates a hash from the MAC-address in combination with the bundle identifier
 * of your app.
 */

- (NSString *) uniqueDeviceIdentifier;

/*
 * @method uniqueGlobalDeviceIdentifier
 * @description use this method when you need a unique global identifier to track a device
 * with multiple apps. as example a advertising network will use this method to track the device
 * from different apps.
 * It generates a hash from the MAC-address only.
 */

- (NSString *) uniqueGlobalDeviceIdentifier;

@end



@interface UIDevice (Process)
+ (NSArray *)runningProcesses;
+ (NSArray *)runningProcesses:(BOOL)isMoreInfo; //default is true -> dict with process name and PID
@end


@interface UIDevice (NetDetect)
/*
 0 = No wifi or cellular  - gprs return 0
 1 = 2G and earlier? (not confirmed)
 2 = 3G? (not yet confirmed)
 3 = 4G
 4 = LTE
 5 = Wifi
 */
- (int) dataNetworkTypeFromStatusBar;
@end


// ios7 and later
@interface UIDevice (UUID)
- (NSString *) adUUID;
@end

extern UIDevice* MyDevice();
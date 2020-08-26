//
//  ESLLogger.h
//  Pods
//
//  Created by xiaobo on 2020/7/22.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ESLLogger : NSObject

@property (copy, nonatomic) NSString *roomId;
@property (assign, nonatomic) BOOL userPaused;

+ (instancetype)sharedLogger;

+ (void)logSpeedTest:(NSArray<NSDictionary *> *)result;
+ (void)logStreamConnectFailed:(NSString *)reason failCount:(NSInteger)count;
+ (void)logMessageConnectFailed:(NSDictionary *)result failCount:(NSInteger)count;
+ (void)logStreamConnectSuccess:(NSDictionary *)result;
+ (void)logMessageConnectSuccess:(NSDictionary *)result;
+ (void)logStreamConnectInterrupt:(NSString *)reason;
+ (void)logMessageConnectInterrupt:(NSDictionary *)result;
+ (void)logNetworkIssue:(NSDictionary *)result;
+ (void)logDeviceIssue:(NSDictionary *)result;

+ (void)sendSpeedTestResult:(NSArray<NSDictionary *> *)result;
+ (void)sendPermissionTestResult:(NSDictionary *)result;

@end

NS_ASSUME_NONNULL_END

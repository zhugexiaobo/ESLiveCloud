//
//  ESLMessager.h
//  Pods
//
//  Created by xiaobo on 2020/7/15.
//

#import <Foundation/Foundation.h>
@class ESLMQTT;

NS_ASSUME_NONNULL_BEGIN

@protocol ESLMessagerDelegate <NSObject>

- (void)chatMessage:(NSDictionary *)msg;
- (void)entered:(NSDictionary *)data;
- (void)roomLike:(NSString *)likeNum;
- (void)userOnline:(NSArray *)users count:(NSString *)countNum;
- (void)userLeave:(NSArray *)users count:(NSString *)countNum;
- (void)leadQrcode:(BOOL)showing;
- (void)connectionError:(NSError *)error retryCount:(NSInteger)retry;
- (void)connectionSuccess;

- (void)nodeSpeedTestControl;
- (void)hardwarePermissionsCheckControl;
- (void)changeRegionControl;
- (void)deleteChatControl:(NSString *)msgId;
- (NSDictionary *)streamDebugInfo;

@end

@interface ESLMessager : NSObject

@property (weak, nonatomic) id<ESLMessagerDelegate> delegate;
@property (assign, nonatomic) BOOL isConnected;

- (instancetype)initWithMqtt:(ESLMQTT *)mqtt;
- (void)connect;
- (void)disconnect;
- (void)sendMessage:(NSString *)string;


@end

NS_ASSUME_NONNULL_END

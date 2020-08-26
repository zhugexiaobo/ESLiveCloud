//
//  ESLRoom.h
//  Pods
//
//  Created by xiaobo on 2020/7/15.
//

#import <Foundation/Foundation.h>
#import "ESLMQTT.h"

NS_ASSUME_NONNULL_BEGIN

@interface ESLRoom : NSObject

@property (copy, nonatomic) NSString *roomId;
@property (copy, nonatomic) NSString *name;
@property (copy, nonatomic) NSString *logo;
@property (copy, nonatomic) NSString *userId;
@property (copy, nonatomic) NSString *userIp;
@property (copy, nonatomic) NSString *userName;
@property (copy, nonatomic) NSString *userRole;
@property (copy, nonatomic) NSString *startAt;
@property (copy, nonatomic) NSString *endAt;
@property (copy, nonatomic) NSString *actualStartAt;
@property (copy, nonatomic) NSString *actualEndAt;
@property (copy, nonatomic) NSString *status;
@property (copy, nonatomic) NSString *viewerNum;
@property (copy, nonatomic) NSString *likeNum;
@property (strong, nonatomic) NSArray *speedNodes;
@property (copy, nonatomic) NSString *picture;
@property (copy, nonatomic) NSString *playM3u8;
@property (copy, nonatomic) NSString *pushRtmpUrl;
@property (copy, nonatomic) NSString *viewerUrl;
@property (copy, nonatomic) NSString *welcome;
@property (strong, nonatomic) ESLMQTT *mqtt;
@property (strong, nonatomic) NSDictionary *media;
@property (copy, nonatomic) NSString *sharePoster;

+ (void)enterRoom:(void (^)(ESLRoom *__nullable room, NSError *_Nullable error))block;

@end

NS_ASSUME_NONNULL_END

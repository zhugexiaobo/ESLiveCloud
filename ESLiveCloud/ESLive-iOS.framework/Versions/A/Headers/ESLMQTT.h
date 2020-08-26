//
//  ESLMQTT.h
//  Pods
//
//  Created by xiaobo on 2020/7/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ESLMQTT : NSObject

@property (copy, nonatomic) NSString *host;
@property (copy, nonatomic) NSString *clientId;
@property (copy, nonatomic) NSString *username;
@property (copy, nonatomic) NSString *password;
@property (copy, nonatomic) NSString *priWTopic;
@property (copy, nonatomic) NSString *priRTopic;
@property (copy, nonatomic) NSString *secWTopic;
@property (copy, nonatomic) NSString *secRTopic;

@property (copy, nonatomic) NSString *uip;
@property (copy, nonatomic) NSString *uname;

@end

NS_ASSUME_NONNULL_END

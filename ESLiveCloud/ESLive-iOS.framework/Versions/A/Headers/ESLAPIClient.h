//
//  ESLAPIClient.h
//  Pods
//
//  Created by xiaobo on 2020/7/14.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ESLAPIClient : NSObject

+ (instancetype)sharedClient;
+ (void)resetClient;

- (void)addUserAuthWithUsername:(NSString *)username password:(NSString *)password;
- (void)GETWithPath:(NSString *)aPath params:(nullable NSDictionary *)params
           callback:(nullable void (^)(id _Nullable data, NSError * _Nullable error))block;
- (void)POSTWithPath:(NSString *)aPath params:(nullable NSDictionary *)params
            callback:(nullable void (^)(id _Nullable data, NSError * _Nullable error))block;
- (void)PUTWithPath:(NSString *)aPath params:(nullable NSDictionary *)params
           callback:(nullable void (^)(id _Nullable data, NSError * _Nullable error))block;
- (void)DELETEWithPath:(NSString *)aPath params:(nullable NSDictionary *)params
              callback:(nullable void (^)(id _Nullable data, NSError * _Nullable error))block;
- (void)PATCHWithPath:(NSString *)aPath params:(nullable NSDictionary *)params
             callback:(nullable void (^)(id _Nullable data, NSError * _Nullable error))block;


@end

NS_ASSUME_NONNULL_END

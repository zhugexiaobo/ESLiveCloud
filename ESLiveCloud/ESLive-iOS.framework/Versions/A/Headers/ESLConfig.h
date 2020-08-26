//
//  ESLConfig.h
//  Pods
//
//  Created by xiaobo on 2020/7/14.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ESLConfig : NSObject

@property (strong, nonatomic, nullable) NSString *apiBaseURLString;
@property (strong, nonatomic, nullable) NSString *userToken;

+ (instancetype)sharedConfig;
+ (void)resetSharedConfig;

@end

NS_ASSUME_NONNULL_END

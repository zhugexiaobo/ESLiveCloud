//
//  ESLHUD.h
//  Pods
//
//  Created by xiaobo on 2020/7/14.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ESLHUD : NSObject

+ (void)dismiss;
+ (void)showLoading;
+ (void)showLoadingStatus:(NSString *)string;
+ (void)showNativeLoading:(UIView *)view;
+ (void)dismissNativeLoading:(UIView *)view;
+ (void)showText:(NSString *)string dismissBlock:(nullable void (^)(void))block;
+ (void)showError:(NSError *)error dismissBlock:(nullable void (^)(void))block;
+ (void)showActionableText:(NSString *)string dismissBlock:(nullable void (^)(void))block;

@end

NS_ASSUME_NONNULL_END

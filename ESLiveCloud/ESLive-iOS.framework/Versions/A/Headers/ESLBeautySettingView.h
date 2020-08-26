//
//  ESLBeautySettingView.h
//  Pods
//
//  Created by xiaobo on 2020/7/27.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ESLBeautyDelegate <NSObject>

- (void)beautyEnable:(BOOL)enable beautyLevel:(CGFloat)beauty brightLevel:(CGFloat)bright toneLevel:(CGFloat)tone;

@end

@interface ESLBeautySettingView : UIView

@property (weak, nonatomic) id<ESLBeautyDelegate> delegate;

@end

NS_ASSUME_NONNULL_END

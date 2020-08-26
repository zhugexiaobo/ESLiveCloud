//
//  ESLLikeAnimator.h
//  Pods
//
//  Created by xiaobo on 2020/8/19.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ESLLikeAnimator : NSObject

- (instancetype)initOnView:(UIView*)view atPoint:(CGPoint)point;
- (void)animateItems:(NSInteger)count;


@end

NS_ASSUME_NONNULL_END

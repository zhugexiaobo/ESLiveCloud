//
//  ESLSpeedMeasure.h
//  Pods
//
//  Created by xiaobo on 2020/7/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ESLSpeedMeasure : NSObject

+ (void)measureNodeSpeed:(NSArray <NSDictionary *>*)nodes
                 results:(void (^)(NSArray<NSDictionary *> *speeds))results;

@end

NS_ASSUME_NONNULL_END

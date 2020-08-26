//
//  ESLShelfView.h
//  Pods
//
//  Created by xiaobo on 2020/8/19.
//

#import <UIKit/UIKit.h>
#import "ESLGoodsCell.h"

NS_ASSUME_NONNULL_BEGIN

@interface ESLShelfView : UIView

@property (strong, nonatomic) NSString *roomId;

- (void)updateList;

@end

NS_ASSUME_NONNULL_END

//
//  ESLGoodsCell.h
//  Pods
//
//  Created by xiaobo on 2020/8/19.
//

#import <UIKit/UIKit.h>
#import "ESLGoods.h"

NS_ASSUME_NONNULL_BEGIN

@protocol ESLGoodsCellDelegate <NSObject>

- (void)goodsAction:(ESLGoods *)goods;

@end

@interface ESLGoodsCell : UITableViewCell

@property (strong, nonatomic) ESLGoods *goods;
@property (weak, nonatomic) id<ESLGoodsCellDelegate> delegate;

@end

NS_ASSUME_NONNULL_END

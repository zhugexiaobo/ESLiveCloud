//
//  ESLChatCell.h
//  Pods
//
//  Created by xiaobo on 2020/7/16.
//

#import <UIKit/UIKit.h>
#import "ESLChatMessage.h"

NS_ASSUME_NONNULL_BEGIN

@protocol ESLChatCellDelegate <NSObject>

- (void)cellLongPressed:(ESLChatMessage *)message;

@end

@interface ESLChatCell : UITableViewCell

@property (strong, nonatomic) ESLChatMessage *message;
@property (weak, nonatomic) id<ESLChatCellDelegate> delegate;

@end

NS_ASSUME_NONNULL_END

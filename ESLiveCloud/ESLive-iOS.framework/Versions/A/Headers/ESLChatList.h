//
//  ESLChatList.h
//  Pods
//
//  Created by xiaobo on 2020/7/16.
//

#import <UIKit/UIKit.h>
@class ESLChatMessage;

NS_ASSUME_NONNULL_BEGIN

@interface ESLChatList : UITableView

- (void)userComing:(NSString *)uname;
- (void)receivingMessage:(ESLChatMessage *)msg;
- (void)deleteMessage:(NSString *)msgId;

@end

NS_ASSUME_NONNULL_END

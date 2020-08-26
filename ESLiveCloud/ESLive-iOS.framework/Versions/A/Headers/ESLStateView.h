//
//  ESLStateView.h
//  Pods
//
//  Created by xiaobo on 2020/8/14.
//

#import <UIKit/UIKit.h>
@class ESLRoom, ESLChatMessage;

NS_ASSUME_NONNULL_BEGIN

@protocol ESLStateViewDelegate <NSObject>

- (void)startLiveRoom;
- (void)finishLiveRoom;
- (void)showLiveGoodsShelf;
- (void)shareLiveRoom;
- (void)switchCamera:(BOOL)front;
- (void)switchMic:(BOOL)on;
- (void)showBeautySetting:(BOOL)show;
- (void)showQR:(BOOL)show;
- (void)viewTouched;

@end

@interface ESLStateView : UIView

@property (weak, nonatomic) id<ESLStateViewDelegate> delegate;

- (void)roomInfo:(ESLRoom *)room userPaused:(BOOL)paused;
- (void)liveStarted;
- (void)leadQRShowing:(BOOL)showing;
- (void)liveStreamStucked:(BOOL)stucked;
- (void)userOnlineUpdate:(NSString *)online;
- (void)userTotalUpdate:(NSString *)total;
- (void)receivingLike:(NSString *)likeNum;
- (void)receivingChatMessage:(ESLChatMessage *)msg;
- (void)receivingUserComingMessage:(NSDictionary *)user;
- (void)receivingDeleteMessage:(NSString *)msgId;

@end

NS_ASSUME_NONNULL_END

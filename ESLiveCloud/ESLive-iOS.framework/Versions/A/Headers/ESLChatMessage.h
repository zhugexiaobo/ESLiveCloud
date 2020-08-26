//
//  ESLChatMessage.h
//  Pods
//
//  Created by xiaobo on 2020/7/24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ESLMessageType) {
    ESLMessageTypeChat,
    ESLMessageTypeNotice,
    ESLMessageTypeOnline
};

@interface ESLChatMessage : NSObject

@property (assign, nonatomic) ESLMessageType type;
@property (copy, nonatomic) NSString *uid;
@property (copy, nonatomic) NSString *uname;
@property (copy, nonatomic) NSString *msg;
@property (copy, nonatomic) NSString *history;
@property (copy, nonatomic) NSString *mid;
@property (copy, nonatomic) NSString *ts;

- (void)muteMember:(void (^)(BOOL success, NSError *_Nullable error))block;

@end

NS_ASSUME_NONNULL_END

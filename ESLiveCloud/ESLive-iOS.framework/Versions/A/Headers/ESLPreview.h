//
//  ESLPreview.h
//  Pods
//
//  Created by xiaobo on 2020/7/15.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ESLPreviewDelegate <NSObject>

- (void)liveStreamStuck:(BOOL)stuck;

@end


@interface ESLPreview : UIView

@property (strong, nonatomic) NSDictionary *debugInfo;
@property (assign, nonatomic) BOOL liveStarted;
@property (weak, nonatomic) id<ESLPreviewDelegate> delegate;

- (void)setupWithConfig:(NSDictionary *)config;
- (void)startWithUrl:(NSString *)url;
- (void)stop;
- (void)changeCameraPosition:(BOOL)front;
- (void)changeMic:(BOOL)on;
- (void)openBeautySetting:(BOOL)open;

@end

NS_ASSUME_NONNULL_END

//
//  ESLGoods.h
//  Pods
//
//  Created by xiaobo on 2020/8/19.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ESLGoods : NSObject

@property (copy, nonatomic) NSString *goodsId;
@property (assign, nonatomic) BOOL isDeleted;
@property (copy, nonatomic) NSString *name;
@property (copy, nonatomic) NSString *no;
@property (assign, nonatomic) BOOL onShelf;
@property (copy, nonatomic) NSString *picture;
@property (copy, nonatomic) NSString *price;
@property (copy, nonatomic) NSString *roomId;
@property (copy, nonatomic) NSString *url;


+ (void)requestsGoodsListWithParams:(NSDictionary *)params
                           callback:(void (^)(NSArray<ESLGoods *> *__nullable list, NSError *_Nullable error))block;
- (void)onShelf:(void (^)(ESLGoods *__nullable goods, NSError *_Nullable error))block;
- (void)offShelf:(void (^)(ESLGoods *__nullable goods, NSError *_Nullable error))block;

@end

NS_ASSUME_NONNULL_END

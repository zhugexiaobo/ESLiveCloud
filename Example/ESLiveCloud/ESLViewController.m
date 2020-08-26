//
//  ESLViewController.m
//  ESLiveCloud
//
//  Created by zhugexiaobo on 08/21/2020.
//  Copyright (c) 2020 zhugexiaobo. All rights reserved.
//

#import "ESLViewController.h"
#import <ESLive-iOS/ESLiveViewController.h>
#import <ESLive-iOS/ESLConfig.h>
#import <ESLive-iOS/ESLHUD.h>
#import "AFHTTPSessionManager.h"


@interface ESLViewController ()

@end

@implementation ESLViewController

- (instancetype)initWithCoder:(NSCoder *)aDecoder {
    self = [super initWithCoder:aDecoder];
    if (self){
        [self initializeForm];
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)initializeForm {
    XLFormDescriptor *form;
    XLFormSectionDescriptor *section;
    XLFormRowDescriptor *row;

    form = [XLFormDescriptor formDescriptorWithTitle:@"直播平台开发测试入口"];

    section = [XLFormSectionDescriptor formSection];
    section.title = @"创建直播间";
    [form addFormSection:section];

    row = [XLFormRowDescriptor formRowDescriptorWithTag:@"roomTitle" rowType:XLFormRowDescriptorTypeText title:@"直播间名称"];
    [row.cellConfigAtConfigure setObject:@"直播间名称" forKey:@"textField.placeholder"];
    [section addFormRow:row];

    row = [XLFormRowDescriptor formRowDescriptorWithTag:@"create" rowType:XLFormRowDescriptorTypeButton title:@"创建直播间"];
    row.action.formSelector = @selector(createRoom:);
    [section addFormRow:row];

    
    section = [XLFormSectionDescriptor formSection];
    section.title = @"进入直播间";
    [form addFormSection:section];

    row = [XLFormRowDescriptor formRowDescriptorWithTag:@"roomId" rowType:XLFormRowDescriptorTypeText title:@"直播间ID"];
    [row.cellConfigAtConfigure setObject:@"直播间ID" forKey:@"textField.placeholder"];
    [section addFormRow:row];

    row = [XLFormRowDescriptor formRowDescriptorWithTag:@"speaker" rowType:XLFormRowDescriptorTypeText title:@"用户昵称"];
    [row.cellConfigAtConfigure setObject:@"用户昵称" forKey:@"textField.placeholder"];
    [section addFormRow:row];
    
    row = [XLFormRowDescriptor formRowDescriptorWithTag:@"role" rowType:XLFormRowDescriptorTypeSelectorPickerViewInline title:@"角色"];
    row.selectorOptions = @[@"主播", @"观众"];
    row.value = @"主播";
    [section addFormRow:row];
    
    row = [XLFormRowDescriptor formRowDescriptorWithTag:@"enter" rowType:XLFormRowDescriptorTypeButton title:@"进入直播间"];
    row.action.formSelector = @selector(enterRoom:);
    [section addFormRow:row];

    self.form = form;
}


- (void)createRoom:(XLFormRowDescriptor *)sender {
    [self deselectFormRow:sender];
    NSString *name = self.form.formValues[@"roomTitle"] ?: @"测试直播";
    NSInteger start = (NSDate.date.timeIntervalSince1970 + 300) * 1000;
    NSInteger end = start + 3600000;
    NSDictionary *params = @{@"accessKey": @"testAccessKey",
                             @"secretKey": @"testSecretKey",
                             @"roomName": name,
                             @"startAt": @(start),
                             @"endAt": @(end)};
    AFHTTPSessionManager *client = [[AFHTTPSessionManager alloc] initWithBaseURL:[NSURL URLWithString:ESLConfig.sharedConfig.apiBaseURLString]
                                            sessionConfiguration:nil];
    client.requestSerializer = [[AFJSONRequestSerializer alloc] init];
    client.responseSerializer = [AFCompoundResponseSerializer serializer];
    [client.requestSerializer setValue:@"application/json" forHTTPHeaderField:@"Content-Type"];
    [client POST:@"api/dev/createRoom" parameters:params headers:nil progress:nil success:^(NSURLSessionDataTask * _Nonnull task, id  _Nullable responseObject) {
        id data = [NSJSONSerialization JSONObjectWithData:responseObject
                                                  options:NSJSONReadingAllowFragments
                                                    error:nil];
        XLFormRowDescriptor *row = [sender.sectionDescriptor.formDescriptor formRowWithTag:@"roomId"];
        row.value = data[@"roomId"];
        [self reloadFormRow:row];
        [self enterRoom:nil];
    } failure:^(NSURLSessionDataTask * _Nullable task, NSError * _Nonnull error) {
        [ESLHUD showError:error dismissBlock:nil];
    }];
}

- (void)enterRoom:(XLFormRowDescriptor *)sender {
    [self deselectFormRow:sender];
    if (!self.form.formValues[@"roomId"]) {
        return;
    }
    NSDictionary *params = @{@"accessKey": @"testAccessKey",
                             @"secretKey": @"testSecretKey",
                             @"userId": @"1",
                             @"userName": self.form.formValues[@"speaker"] ?: @"主播01",
                             @"role": @"speaker",
                             @"roomId": self.form.formValues[@"roomId"]};
    AFHTTPSessionManager *client = [[AFHTTPSessionManager alloc] initWithBaseURL:[NSURL URLWithString:ESLConfig.sharedConfig.apiBaseURLString]
                                            sessionConfiguration:nil];
    client.requestSerializer = [[AFJSONRequestSerializer alloc] init];
    client.responseSerializer = [AFCompoundResponseSerializer serializer];
    [client.requestSerializer setValue:@"application/json" forHTTPHeaderField:@"Content-Type"];
    [client POST:@"api/dev/createRoomToken" parameters:params headers:nil progress:nil success:^(NSURLSessionDataTask * _Nonnull task, id  _Nullable responseObject) {
        id data = [NSJSONSerialization JSONObjectWithData:responseObject
                                                  options:NSJSONReadingAllowFragments
                                                    error:nil];
        ESLiveViewController *live = [[ESLiveViewController alloc] initWithToken:data[@"token"]];
        live.modalPresentationStyle = UIModalPresentationFullScreen;
        [self presentViewController:live animated:YES completion:nil];
    } failure:^(NSURLSessionDataTask * _Nullable task, NSError * _Nonnull error) {
        [ESLHUD showError:error dismissBlock:nil];
    }];
}

@end

//
//  LeanMessageManager.m
//
//  Created on 15/3/21.
//  Copyright (c) 2015年 Jack & lzwjava All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVOSCloud/AVOSCloud.h>
#import <AVOSCloudIM/AVOSCloudIM.h>

#define WEAKSELF typeof(self) __weak weakSelf = self;

#define kDidReceiveTypedMessageNotification @"didReceiveTypedMessageNotification"

typedef enum : NSInteger {
    ConversationTypeOneToOne = 0,
    ConversationTypeGroup = 1,
} ConversationType;

typedef void (^DidReceiveTypedMessageBlock)(AVIMConversation *conversation, AVIMTypedMessage *message);

@interface LeanMessageManager : NSObject

+ (void)setupApplication;

+ (instancetype)manager;

- (NSString *)selfClientID;

- (void)setupDidReceiveTypedMessageCompletion:(DidReceiveTypedMessageBlock)didReceiveTypedMessageCompletion;

- (void)openSessionWithClientID:(NSString *)clientID
                     completion:(AVBooleanResultBlock)completion;

- (void)closeSessionWithBlock:(AVBooleanResultBlock)block;

- (void)createConversationsWithClientIDs:(NSArray *)clientIDs
                        conversationType:(ConversationType)conversationType
                              completion:(AVIMConversationResultBlock)completion;

- (void)fetchConversationById:(NSString *)conversationId block:(AVIMConversationResultBlock)block;
@end

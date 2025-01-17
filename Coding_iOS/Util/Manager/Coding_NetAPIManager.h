//
//  Coding_NetAPIManager.h
//  Coding_iOS
//
//  Created by 王 原闯 on 14-7-30.
//  Copyright (c) 2014年 Coding. All rights reserved.
//


#import "CodingNetAPIClient.h"
#import "Projects.h"
#import "Tasks.h"
#import "ProjectMember.h"
#import "ProjectTopics.h"
#import "Tweets.h"
#import "Users.h"
#import "PrivateMessages.h"
#import "ProjectMember.h"
#import "CodingTips.h"
#import "CodeTree.h"
#import "CodeFile.h"
#import "ProjectFolders.h"
#import "ProjectFiles.h"
#import "CodeBranchOrTag.h"
#import "MRPRS.h"
#import "MRPR.h"
#import "MRPRBaseInfo.h"
#import "Commit.h"
#import "FileChanges.h"
#import "FileLineChange.h"
#import "CommitInfo.h"
#import "Commits.h"
#import "ProjectTag.h"
#import "CodingBanner.h"
#import "PointRecords.h"
#import "FileVersion.h"

@class CSTopic;

typedef NS_ENUM(NSUInteger, VerifyType){
    VerifyTypeUnknow = 0,
    VerifyTypePassword,
    VerifyTypeTotp,
};

@interface Coding_NetAPIManager : NSObject
+ (instancetype)sharedManager;

//UnRead
- (void)request_UnReadCountWithBlock:(void (^)(id data, NSError *error))block;
- (void)request_UnReadNotificationsWithBlock:(void (^)(id data, NSError *error))block;


//Login
- (void)request_Login_With2FA:(NSString *)otpCode andBlock:(void (^)(id data, NSError *error))block;
- (void)request_Login_WithParams:(id)params andBlock:(void (^)(id data, NSError *error))block;
- (void)request_Register_WithParams:(id)params andBlock:(void (^)(id data, NSError *error))block;
- (void)request_CaptchaNeededWithPath:(NSString *)path andBlock:(void (^)(id data, NSError *error))block;
- (void)request_SendMailToPath:(NSString *)path email:(NSString *)email j_captcha:(NSString *)j_captcha andBlock:(void (^)(id data, NSError *error))block;
- (void)request_SetPasswordToPath:(NSString *)path params:(NSDictionary *)params andBlock:(void (^)(id data, NSError *error))block;

//Project
- (void)request_Projects_WithObj:(Projects *)projects andBlock:(void (^)(Projects *data, NSError *error))block;
- (void)request_ProjectsHaveTasks_WithObj:(Projects *)projects andBlock:(void (^)(id data, NSError *error))block;
- (void)request_Project_UpdateVisit_WithObj:(Project *)project andBlock:(void (^)(id data, NSError *error))block;
- (void)request_ProjectDetail_WithObj:(Project *)project andBlock:(void (^)(id data, NSError *error))block;
- (void)request_ProjectActivityList_WithObj:(ProjectActivities *)proActs andBlock:(void (^)(NSArray *data, NSError *error))block;
- (void)request_ProjectTaskList_WithObj:(Tasks *)tasks andBlock:(void (^)(Tasks *data, NSError *error))block;
- (void)request_ProjectMembers_WithObj:(Project *)project andBlock:(void (^)(id data, NSError *error))block;
- (void)request_ProjectMembersHaveTasks_WithObj:(Project *)project andBlock:(void (^)(NSArray *data, NSError *error))block;
- (void)request_ProjectMember_Quit:(ProjectMember *)curMember andBlock:(void (^)(id data, NSError *error))block;
- (void)request_Project_Pin:(Project *)project andBlock:(void (^)(id data, NSError *error))block;

- (void)request_NewProject_WithObj:(Project *)project image:(UIImage *)image andBlock:(void (^)(NSString *data, NSError *error))block;
- (void)request_UpdateProject_WithObj:(Project *)project andBlock:(void (^)(Project *data, NSError *error))block;
- (void)request_UpdateProject_WithObj:(Project *)project icon:(UIImage *)icon andBlock:(void (^)(id data, NSError *error))block progerssBlock:(void (^)(CGFloat progressValue))progress;;
- (void)request_DeleteProject_WithObj:(Project *)project passCode:(NSString *)passCode type:(VerifyType)type andBlock:(void (^)(Project *data, NSError *error))block;

//MRPR
- (void)request_MRPRS_WithObj:(MRPRS *)curMRPRS andBlock:(void (^)(MRPRS *data, NSError *error))block;
- (void)request_MRPRBaseInfo_WithObj:(MRPR *)curMRPR andBlock:(void (^)(MRPRBaseInfo *data, NSError *error))block;
- (void)request_MRPRCommits_WithObj:(MRPR *)curMRPR andBlock:(void (^)(NSArray *data, NSError *error))block;
- (void)request_MRPRFileChanges_WithObj:(MRPR *)curMRPR andBlock:(void (^)(FileChanges *data, NSError *error))block;
- (void)request_MRPRAccept:(MRPR *)curMRPR andBlock:(void (^)(id data, NSError *error))block;
- (void)request_MRPRRefuse:(MRPR *)curMRPR andBlock:(void (^)(id data, NSError *error))block;
- (void)request_MRPRCancel:(MRPR *)curMRPR andBlock:(void (^)(id data, NSError *error))block;
- (void)request_CommitInfo_WithUserGK:(NSString *)userGK projectName:(NSString *)projectName commitId:(NSString *)commitId andBlock:(void (^)(CommitInfo *data, NSError *error))block;
- (void)request_PostCommentWithPath:(NSString *)path params:(NSDictionary *)params andBlock:(void (^)(id data, NSError *error))block;
- (void)request_DeleteLineNote:(NSNumber *)lineNoteId inProject:(NSString *)projectName ofUser:(NSString *)userGK andBlock:(void (^)(id data, NSError *error))block;
- (void)request_DeleteLineNoteWithPath:(NSString *)path andBlock:(void (^)(id data, NSError *error))block;

//File
- (void)request_Folders:(ProjectFolders *)folders inProject:(Project *)project andBlock:(void (^)(id data, NSError *error))block;
- (void)request_FilesInFolder:(ProjectFolder *)folder andBlock:(void (^)(id data, NSError *error))block;
- (void)request_DeleteFolder:(ProjectFolder *)folder andBlock:(void (^)(id data, NSError *error))block;
- (void)request_RenameFolder:(ProjectFolder *)folder andBlock:(void (^)(id data, NSError *error))block;
- (void)request_DeleteFiles:(NSArray *)fileIdList inProject:(NSNumber *)project_id andBlock:(void (^)(id data, NSError *error))block;
- (void)request_MoveFiles:(NSArray *)fileIdList toFolder:(ProjectFolder *)folder andBlock:(void (^)(id data, NSError *error))block;
- (void)request_CreatFolder:(NSString *)fileName inFolder:(ProjectFolder *)parentFolder inProject:(Project *)project andBlock:(void (^)(id data, NSError *error))block;
- (void)request_FileDetail:(ProjectFile *)file andBlock:(void (^)(id data, NSError *error))block;
- (void)request_FileContent:(ProjectFile *)file andBlock:(void (^)(id data, NSError *error))block;
- (void)request_EditFile:(ProjectFile *)file withContent:(NSString *)contentStr andBlock:(void (^)(id data, NSError *error))block;
- (void)request_RenameFile:(ProjectFile *)file withName:(NSString *)nameStr andBlock:(void (^)(id data, NSError *error))block;

- (void)request_ActivityListOfFile:(ProjectFile *)file andBlock:(void (^)(id data, NSError *error))block;
- (void)request_VersionListOfFile:(ProjectFile *)file andBlock:(void (^)(id data, NSError *error))block;
- (void)request_DeleteComment:(NSNumber *)comment_id inFile:(ProjectFile *)file andBlock:(void (^)(id data, NSError *error))block;
- (void)request_RemarkFileVersion:(FileVersion *)curVersion withStr:(NSString *)remarkStr andBlock:(void (^)(id data, NSError *error))block;
- (void)request_DeleteFileVersion:(FileVersion *)curVersion andBlock:(void (^)(id data, NSError *error))block;
- (void)request_OpenShareOfFile:(ProjectFile *)file andBlock:(void (^)(id data, NSError *error))block;
- (void)request_CloseShareHash:(NSString *)hashStr andBlock:(void (^)(id data, NSError *error))block;

//Code
- (void)request_CodeTree:(CodeTree *)codeTree withPro:(Project *)project codeTreeBlock:(void (^)(id codeTreeData, NSError *codeTreeError))block;
- (void)request_CodeFile:(CodeFile *)codeFile withPro:(Project *)project andBlock:(void (^)(id data, NSError *error))block;
- (void)request_CodeBranchOrTagWithPath:(NSString *)path withPro:(Project *)project andBlock:(void (^)(id data, NSError *error))block;
- (void)request_Commits:(Commits *)curCommits withPro:(Project *)project andBlock:(void (^)(id data, NSError *error))block;


//Task
- (void)request_AddTask:(Task *)task andBlock:(void (^)(id data, NSError *error))block;
- (void)request_DeleteTask:(Task *)task andBlock:(void (^)(id data, NSError *error))block;
- (void)request_EditTask:(Task *)task oldTask:(Task *)oldTask andBlock:(void (^)(id data, NSError *error))block;
- (void)request_EditTask:(Task *)task withDescriptionStr:(NSString *)descriptionStr andBlock:(void (^)(id data, NSError *error))block;
- (void)request_EditTask:(Task *)task withTags:(NSMutableArray *)selectedTags andBlock:(void (^)(id data, NSError *error))block;
- (void)request_ChangeTaskStatus:(Task *)task andBlock:(void (^)(id data, NSError *error))block;
- (void)request_TaskDetail:(Task *)task andBlock:(void (^)(id data, NSError *error))block;
- (void)request_ActivityListOfTask:(Task *)task andBlock:(void (^)(id data, NSError *error))block;
- (void)request_DoCommentToTask:(Task *)task andBlock:(void (^)(id data, NSError *error))block;
- (void)request_DeleteComment:(TaskComment *)comment ofTask:(Task *)task andBlock:(void (^)(id data, NSError *error))block;

//User
- (void)request_AddUser:(User *)user ToProject:(Project *)project andBlock:(void (^)(id data, NSError *error))block;

//Topic
- (void)request_ProjectTopicList_WithObj:(ProjectTopics *)proTopics andBlock:(void (^)(id data, NSError *error))block;
- (void)request_ProjectTopic_WithObj:(ProjectTopic *)proTopic andBlock:(void (^)(id data, NSError *error))block;
- (void)request_ModifyProjectTpoic:(ProjectTopic *)proTopic andBlock:(void (^)(id data, NSError *error))block;
- (void)request_AddProjectTpoic:(ProjectTopic *)proTopic andBlock:(void (^)(id data, NSError *error))block;
- (void)request_Comments_WithProjectTpoic:(ProjectTopic *)proTopic andBlock:(void (^)(id data, NSError *error))block;
- (void)request_DoComment_WithProjectTpoic:(ProjectTopic *)proTopic andBlock:(void (^)(id data, NSError *error))block;
- (void)request_ProjectTopic_Delete_WithObj:(ProjectTopic *)proTopic andBlock:(void (^)(id data, NSError *error))block;

- (void)request_ModifyProjectTpoicLabel:(ProjectTopic *)proTopic
                               andBlock:(void (^)(id data, NSError *error))block;
- (void)request_ProjectTopic_Count_WithPath:(NSString *)path
                                   andBlock:(void (^)(id data, NSError *error))block;
- (void)request_ProjectTopic_LabelMy_WithPath:(NSString *)path
                                     andBlock:(void (^)(id data, NSError *error))block;

// Project Tag
- (void)request_TagListInProject:(Project *)project type:(ProjectTagType)type andBlock:(void (^)(id data, NSError *error))block;
- (void)request_AddTag:(ProjectTag *)tag toProject:(Project *)project andBlock:(void (^)(id data, NSError *error))block;
- (void)request_DeleteTag:(ProjectTag *)tag inProject:(Project *)project andBlock:(void (^)(id data, NSError *error))block;
- (void)request_ModifyTag:(ProjectTag *)tag inProject:(Project *)project andBlock:(void (^)(id data, NSError *error))block;

//Tweet
- (void)request_Tweets_WithObj:(Tweets *)tweets andBlock:(void (^)(id data, NSError *error))block;
- (void)request_Tweet_DoLike_WithObj:(Tweet *)tweet andBlock:(void (^)(id data, NSError *error))block;
- (void)request_Tweet_DoComment_WithObj:(Tweet *)tweet andBlock:(void (^)(id data, NSError *error))block;
- (void)request_Tweet_DoTweet_WithObj:(Tweet *)tweet andBlock:(void (^)(id data, NSError *error))block;
- (void)request_Tweet_Likers_WithObj:(Tweet *)tweet andBlock:(void (^)(id data, NSError *error))block;
- (void)request_Tweet_Comments_WithObj:(Tweet *)tweet andBlock:(void (^)(id data, NSError *error))block;
- (void)request_Tweet_Delete_WithObj:(Tweet *)tweet andBlock:(void (^)(id data, NSError *error))block;
- (void)request_TweetComment_Delete_WithTweet:(Tweet *)tweet andComment:(Comment *)comment andBlock:(void (^)(id data, NSError *error))block;
- (void)request_Tweet_Detail_WithObj:(Tweet *)tweet andBlock:(void (^)(id data, NSError *error))block;
- (void)request_PublicTweetsWithTopic:(NSInteger)topicID andBlock:(void (^)(id data, NSError *error))block;


//User
- (void)request_UserInfo_WithObj:(User *)curUser andBlock:(void (^)(id data, NSError *error))block;
- (void)request_ResetPassword_WithObj:(User *)curUser andBlock:(void (^)(id data, NSError *error))block;
- (void)request_FollowersOrFriends_WithObj:(Users *)curUsers andBlock:(void (^)(id data, NSError *error))block;
- (void)request_FollowedOrNot_WithObj:(User *)curUser andBlock:(void (^)(id data, NSError *error))block;
- (void)request_UserJobArrayWithBlock:(void (^)(id data, NSError *error))block;
- (void)request_UserTagArrayWithBlock:(void (^)(id data, NSError *error))block;
- (void)request_UpdateUserInfo_WithObj:(User *)curUser andBlock:(void (^)(id data, NSError *error))block;
- (void)request_PointRecords:(PointRecords *)records andBlock:(void (^)(id data, NSError *error))block;

//Message
- (void)request_PrivateMessages:(PrivateMessages *)priMsgs andBlock:(void (^)(id data, NSError *error))block;
- (void)request_Fresh_PrivateMessages:(PrivateMessages *)priMsgs andBlock:(void (^)(id data, NSError *error))block;
- (void)request_SendPrivateMessage:(PrivateMessage *)nextMsg andBlock:(void (^)(id data, NSError *error))block;
- (void)request_SendPrivateMessage:(PrivateMessage *)nextMsg andBlock:(void (^)(id data, NSError *error))block progerssBlock:(void (^)(CGFloat progressValue))progress;
- (void)request_playedPrivateMessage:(PrivateMessage *)pm;
- (void)request_CodingTips:(CodingTips *)curTips andBlock:(void (^)(id data, NSError *error))block;
- (void)request_markReadWithCodingTips:(CodingTips *)curTips andBlock:(void (^)(id data, NSError *error))block;
- (void)request_markReadWithCodingTipIdStr:(NSString *)tipIdStr andBlock:(void (^)(id data, NSError *error))block;
- (void)request_DeletePrivateMessage:(PrivateMessage *)curMsg andBlock:(void (^)(id data, NSError *error))block;
- (void)request_DeletePrivateMessagesWithObj:(PrivateMessage *)curObj andBlock:(void (^)(id data, NSError *error))block;

//Git Related
- (void)request_StarProject:(Project *)project andBlock:(void (^)(id data, NSError *error))block;
- (void)request_WatchProject:(Project *)project andBlock:(void (^)(id data, NSError *error))block;
- (void)request_ForkProject:(Project *)project andBlock:(void (^)(id data, NSError *error))block;
- (void)request_ReadMeOFProject:(Project *)project andBlock:(void (^)(id data, NSError *error))block;
- (void)request_FileDiffDetailWithPath:(NSString *)path andBlock:(void (^)(id data, NSError *error))block;
- (void)request_ForkTreeWithOwner:(NSString *)owner_name project:(NSString *)project_name andBlock:(void (^)(id data, NSError *error))block;

//Image
- (void)uploadTweetImage:(UIImage *)image
               doneBlock:(void (^)(NSString *imagePath, NSError *error))done
              progerssBlock:(void (^)(CGFloat progressValue))progress;

- (void)request_UpdateUserIconImage:(UIImage *)image
                       successBlock:(void (^)(id responseObj))success
                       failureBlock:(void (^)(NSError *error))failure
                      progerssBlock:(void (^)(CGFloat progressValue))progress;
- (void)loadImageWithPath:(NSString *)imageUrlStr completeBlock:(void (^)(UIImage *image, NSError *error))block;

//Other
- (void)request_Users_WithSearchString:(NSString *)searchStr andBlock:(void (^)(id data, NSError *error))block;
- (void)request_MDHtmlStr_WithMDStr:(NSString *)mdStr inProject:(Project *)project andBlock:(void (^)(id data, NSError *error))block;
- (void)request_VerifyTypeWithBlock:(void (^)(VerifyType type, NSError *error))block;

- (void)request_Users_WithTopicID:(NSInteger)topicID andBlock:(void (^)(id data, NSError *error))block;
- (void)request_JoinedUsers_WithTopicID:(NSInteger)topicID page:(NSInteger)page andBlock:(void (^)(id data, NSError *error))block;


//Topic HotKey
- (void)request_TopicHotkeyWithBlock:(void (^)(id data, NSError *error))block;
//Topic
- (void)request_TopicAdlistWithBlock:(void (^)(id data, NSError *error))block;
- (void)request_HotTopiclistWithBlock:(void (^)(id data, NSError *error))block;

- (void)request_Tweet_WithSearchString:(NSString *)strSearch andPage:(NSInteger)page andBlock:(void (^)(id data, NSError *error))block;

- (void)request_TopicDetailsWithTopicID:(NSInteger)topicID block:(void (^)(id data, NSError *error))block;
- (void)request_TopTweetWithTopicID:(NSInteger)topicID block:(void (^)(id data, NSError *error))block;

- (void)request_JoinedTopicsWithUserGK:(NSString *)userGK page:(NSInteger)page block:(void (^)(id data, BOOL hasMoreData, NSError *error))block;
- (void)request_WatchedTopicsWithUserGK:(NSString *)userGK page:(NSInteger)page block:(void (^)(id data, BOOL hasMoreData, NSError *error))block;

- (void)request_Topic_DoWatch_WithUrl:(NSString *)url andBlock:(void (^)(id data, NSError *error))block;
- (void)request_BannersWithBlock:(void (^)(id data, NSError *error))block;

@end

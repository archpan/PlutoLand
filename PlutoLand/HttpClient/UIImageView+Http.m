//
//  UIImageView+Http.m
//  PlutoLand
//
//  Created by xu xhan on 7/15/10.
//  Copyright 2010 xu han. All rights reserved.
//

#import "UIImageView+Http.h"
#import "PLHttpQueue.h"
#import "PLImageLoader.h"
#import "PLImageCacheC.h"



@implementation UIImageView(Http)

- (void)fetchByURL:(NSString*)urlstr userInfo:(NSDictionary*)info freshOnSucceed:(BOOL)isFresh placeHolder:(UIImage*)img cache:(BOOL)cache
{
	UIImage* aimage = [[PLImageCacheC sharedCache] getImageByURL:urlstr];
	if (aimage) {
		self.image = aimage;
//		PLOG(@"- loaded cached image :%@",urlstr);
		return;
	}
    if (img) {
        self.image = img;
    }
	PLImageLoader* loader = [[PLImageLoader alloc] init];	
	[loader fetchForImageView:self URL:urlstr freshOnSucceed:isFresh cacheEnable:cache userInfo:info];
	[[PLHttpQueue sharedQueue] addQueueItem:loader];
	[loader release];
}

- (void)fetchByURL:(NSString*)urlstr userInfo:(NSDictionary*)info freshOnSucceed:(BOOL)isFresh placeHolder:(UIImage*)img
{
    [self fetchByURL:urlstr
            userInfo:info
      freshOnSucceed:isFresh
         placeHolder:img
               cache:YES];
}

- (void)fetchByURL:(NSString*)urlstr
{
	return [self fetchByURL:urlstr userInfo:nil freshOnSucceed:YES placeHolder:nil];
}

- (void)fetchByURL:(NSString*)urlstr placeHolder:(UIImage*)img
{
    return [self fetchByURL:urlstr userInfo:nil freshOnSucceed:YES placeHolder:img];
}

- (BOOL)cleanFetchURL:(NSString*)url
{
    [[PLImageCacheC sharedCache] removeURL:url fromDisk:YES];
    return YES;
}
@end

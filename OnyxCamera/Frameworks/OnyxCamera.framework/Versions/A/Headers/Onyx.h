//
//  ONYX.h
//  OnyxCamera
//
//  Created by Matthew Wheatley on 9/27/17.
//  Copyright © 2017 Diamond Fortress. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "OnyxConfiguration.h"
#import "OnyxViewController.h"
#import "OnyxEnums.h"

#define OnyxBlue [UIColor colorWithRed:(float)(54.0/255.0) green:(float)(152.0/255.0) blue:(float)(211.0/255.0) alpha:1.0]

@interface Onyx : NSObject <OnyxViewControllerDelegate> {
    NSInteger selectedFinger;
    NSInteger fingerDirection;
    UIView* spinnerView;
    UIActivityIndicatorView* activityIndicatorView;
}

/*!
 * @brief ONYX's delegate
 */
@property (strong, nonatomic) id delegate;

/*!
 * @brief ONYX Config data
 */
@property OnyxConfiguration* onyxConfig;
@property UIViewController* viewController;
@property OnyxResult* onyxResult;

extern NSString * const IMAGE_URI_PREFIX;
extern NSString * const ONYX_ICON_IMAGE_DATA;

-(void)doSetup:(OnyxConfiguration*)onyxConfig;
-(void)capture:(UIViewController*)viewController;

@end

#pragma mark - OnyxViewControllerDelegate

// Onyx Delegate methods
@protocol OnyxDelegate
- (void) Onyx:(Onyx *)controller successCallback:(NSData *)data;
- (void) Onyx:(Onyx *)controller errorCallback:(NSError *)error;
@end

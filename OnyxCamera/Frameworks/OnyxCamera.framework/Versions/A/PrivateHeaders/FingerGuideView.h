//
//  ONXFingerGuideView.h
//  IDFingerScanApp
//
//  Created by zaknixon on 6/29/13.
//  Copyright (c) 2013 Diamond Fortress Technologies. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CaptureNetOutputs.h"

/**
 Class that represents a guide view used to help 
 user's properly position their finger in the camera's view.
 */
@interface FingerGuideView : UIView {
    UIImageView *tooCloseImageView;
    UIImageView *tooFarImageView;
    UIImageView *captureImageView;
    UIImageView *logoImageView;
    
}

@property (nonatomic) CGRect frame;

/** 
 Color of the guide geometry.
 */
@property (nonatomic,strong) UIColor *color;
@property Side side;
@property Side defaultSide;
@property Together togetherness;
@property Depth depth;
@property float height;
@property float offset;

@end

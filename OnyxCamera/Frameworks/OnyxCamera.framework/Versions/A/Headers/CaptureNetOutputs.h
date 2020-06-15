//
//  CaptureNetOutputs.h
//  OnyxCamera
//
//  Created by Will Lucas on 8/11/19.
//  Copyright © 2019 Diamond Fortress. All rights reserved.
//

#import <Foundation/Foundation.h>

extern const int BATCH_SIZE;
extern const int IMAGE_WIDTH;
extern const int IMAGE_HEIGHT;
extern const int IMAGE_DEPTH;
extern const int OUTPUT_DEPTH;

typedef enum Side : NSUInteger {
    kSideBackground,
    kLeft,
    kRight
} Side;

typedef enum Together : NSUInteger {
    kApart,
    kTogetherBackground,
    kTogether
} Together;

typedef enum Depth : NSUInteger {
    kDepthBackground,
    kCapture,
    kTooClose,
    kTooFar
} Depth;

NS_ASSUME_NONNULL_BEGIN

@interface CaptureNetOutputs : NSObject

@property NSArray *sideOutputs;
@property NSArray *togetherOutputs;
@property NSArray *depthOutputs;

@property NSData *maskData;
@property NSDictionary *labels;

- (instancetype)initWithOutputs:(NSArray *)side together:(NSArray *)together depth:(NSArray *)depth mask:(NSData *)mask labels:(NSDictionary *)labels;

- (Side)getSide;
- (NSString*)getSideString;
- (Together)getTogetherness;
- (NSString*)getTogethernessString;
- (Depth)getDepth;
- (NSString*)getDepthString;

-(NSString*)description;

@end

NS_ASSUME_NONNULL_END

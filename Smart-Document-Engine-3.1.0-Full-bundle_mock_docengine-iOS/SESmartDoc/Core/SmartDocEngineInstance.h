/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import <UIKit/UIKit.h>

#import <objcdocengine/doc_result.h>
#import <objcdocengine/doc_engine.h>

#import <objcsecommon/se_image.h>

@protocol SmartDocumentEngineDelegate <NSObject>
@optional
- (void) SmartDocumentEngineObtainedSingleImageResult:(nonnull SEDocResultRef *)result;
@end

@protocol SmartDocumentEngineInitializationDelegate <NSObject>
@optional
- (void) SmartDocumentEngineInitialized;
- (void) SmartDocumentEngineSessionStarted;
- (void) SmartDocumentEngineSessionDismissed;
@end

@interface SmartDocumentEngineInstance : NSObject

@property (weak, nonatomic, nullable, readonly) id<SmartDocumentEngineDelegate> engineDelegate;
@property (weak, nonatomic, nullable, readonly) id<SmartDocumentEngineInitializationDelegate> initializationDelegate;

@property (strong, nullable, readonly) SEDocEngine* engine; // main configuration of Smart Document Engine
@property (strong, nullable, readonly) SEDocSession* session; // current recognition session
@property (strong, nullable) SEDocSessionSettings* sessionSettings; // current session settings

@property BOOL engineInitialized;
@property BOOL sessionRunning;

- (nonnull instancetype) initWithSignature:(nonnull NSString *)signature;
- (void) setEngineDelegate:(nullable __weak id<SmartDocumentEngineDelegate>)delegate;
- (void) setInitializationDelegate:(nullable __weak id<SmartDocumentEngineInitializationDelegate>)delegate;

- (void) initializeEngine:(nonnull NSString *)bundlePath;

- (void) initSession;
- (void) dismissSession;

- (void) processSingleImage:(nonnull SECommonImageRef *)image;
- (void) processSingleImageFromFile:(nonnull NSString *)filePath;
- (void) processSingleImageFromUIImage:(nonnull UIImage *)image;

- (void) addSingleImage:(nonnull SECommonImageRef *)image;
- (void) addSingleImageFromFile:(nonnull NSString *)filePath;
- (void) addSingleImageFromUIImage:(nonnull UIImage *)image;

- (void) processImage:(nonnull SECommonImageRef *)image;
- (void) processImageFromFile:(nonnull NSString *)filePath;
- (void) processImageFromUIImage:(nonnull UIImage *)image;

- (void) addImage:(nonnull SECommonImageRef *)image;
- (void) addImageFromFile:(nonnull NSString *)filePath;
- (void) addImageFromUIImage:(nonnull UIImage *)image;

- (int) getCurrentFrameId;

@end


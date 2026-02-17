/*
  Copyright (c) 2016-2025, Smart Engines Service LLC
  All rights reserved.
*/

#import "SmartDocEngineInstance.h"

#import <objcdocengine/doc_forward_declarations.h>
#import <objcdocengine/doc_basic_object.h>
#import <objcdocengine/doc_basic_objects_iterator.h>
#import <objcdocengine/doc_document.h>
#import <objcdocengine/doc_documents_iterator.h>
#import <objcdocengine/doc_engine.h>
#import <objcdocengine/doc_external_processor.h>
#import <objcdocengine/doc_feedback.h>
#import <objcdocengine/doc_fields.h>
#import <objcdocengine/doc_fields_iterators.h>
#import <objcdocengine/doc_graphical_structure.h>
#import <objcdocengine/doc_objects.h>
#import <objcdocengine/doc_objects_collection.h>
#import <objcdocengine/doc_objects_collections_iterator.h>
#import <objcdocengine/doc_processing_settings.h>
#import <objcdocengine/doc_result.h>
#import <objcdocengine/doc_session.h>
#import <objcdocengine/doc_session_settings.h>
#import <objcdocengine/doc_tags_collection.h>
#import <objcdocengine/doc_video_session.h>
#import <objcdocengine/doc_view.h>
#import <objcdocengine/doc_views_collection.h>
#import <objcdocengine/doc_views_iterator.h>

@interface SmartDocumentEngineInstance () {
  // no members
}

@property NSString* signature;

@property (weak, nonatomic, nullable, readwrite) id<SmartDocumentEngineDelegate> engineDelegate;
@property (weak, nonatomic, nullable, readwrite) id<SmartDocumentEngineInitializationDelegate> initializationDelegate;

@property (strong, nullable, readwrite) SEDocEngine* engine; // main configuration of Smart Document Engine
@property (strong, nullable, readwrite) SEDocSession* session; // current recognition session
@property (readwrite) int pageNumber; // (TEMPORARY) page number for session
@property (readwrite) int frameId; // current frame (view) id

@end

@implementation SmartDocumentEngineInstance {
  BOOL delegateReceivesSingleImageResults;
  
  BOOL delegateReceivesInit;
  BOOL delegateReceivesSessionStarted;
  BOOL delegateReceivesSessionDismissed;
}

@synthesize engine, session, sessionSettings;

- (instancetype) init {
  NSException* exc = [NSException
        exceptionWithName:@"SignatureError"
        reason:@"SmartDocumentEngineInstance must be created with signature (use initWithSignature:)"
        userInfo:nil];
  @throw exc;
}

- (instancetype) initWithSignature:(NSString *)inputSignature {
  if (self = [super init]) {
    // Storing signature
    self.signature = inputSignature;
      
    self.engineInitialized = NO;
    self.sessionRunning = NO;
    
    // Initializing delegates cache
    delegateReceivesSingleImageResults = NO;
    
    delegateReceivesInit = NO;
    delegateReceivesSessionStarted = NO;
    delegateReceivesSessionDismissed = NO;
  }
  return self;
}

- (void) setEngineDelegate:(nullable __weak id<SmartDocumentEngineDelegate>)delegate {
  _engineDelegate = delegate;
  delegateReceivesSingleImageResults = NO;
  if (self.engineDelegate) {
    delegateReceivesSingleImageResults =
        [self.engineDelegate respondsToSelector:@selector(SmartDocumentEngineObtainedSingleImageResult:)];
  }
}

- (void) setInitializationDelegate:(nullable __weak id<SmartDocumentEngineInitializationDelegate>)delegate {
  _initializationDelegate = delegate;
  delegateReceivesInit = NO;
  delegateReceivesSessionStarted = NO;
  delegateReceivesSessionDismissed = NO;
  if (self.initializationDelegate) {
    delegateReceivesInit =
        [self.initializationDelegate respondsToSelector:@selector(SmartDocumentEngineInitialized)];
    delegateReceivesSessionStarted =
        [self.initializationDelegate respondsToSelector:@selector(SmartDocumentEngineSessionStarted)];
    delegateReceivesSessionDismissed =
        [self.initializationDelegate respondsToSelector:@selector(SmartDocumentEngineSessionDismissed)];
  }
}

- (void) initializeEngine:(nonnull NSString*) bundlePath {
  self.engine = [[SEDocEngine alloc] initFromFile:bundlePath
                                     withLazyInit:YES];
  self.sessionSettings = [self.engine createSessionSettings];
  
  // Logging supported document types
  NSLog(@"Supported modes for configured engine:");
  SECommonStringsVectorIterator* modesEnd = [self.sessionSettings supportedModesEnd];
  for (SECommonStringsVectorIterator* it = [self.sessionSettings supportedModesBegin];
       ![it isEqualToIter:modesEnd];
       [it advance]) {
    NSLog(@" --> %@", [it getValue]);
  }
  NSLog(@"Supported document types for configured engine:");
  
  for (int i = 0; i < [self.sessionSettings getInternalEnginesCount]; ++i) {
    int docs_count = [self.sessionSettings getSupportedDocumentTypesCountForEngine:i];
    for (int j = 0; j < docs_count; ++j) {
      NSLog(@" --> %@", [self.sessionSettings getSupportedDocumentTypeForEngine:i withDocumentTypeID:j]);
    }
  }
  
  self.session = nil;
  self.pageNumber = 0;
  self.sessionRunning = NO;
  
  self.engineInitialized = YES;
  
  if (delegateReceivesInit) {
    [self.initializationDelegate SmartDocumentEngineInitialized];
  }
}

- (void) initSession {
  if (!self.engineInitialized) {
    NSException* exc = [NSException
          exceptionWithName:@"SmartDocumentEngineInstanceError"
          reason:@"SmartDocumentEngineInstance cannot initialize session while engine is not yet initialized"
          userInfo:nil];
    @throw exc;
  }
  
  NSLog(@"Enabled document types for recognition session to be created:");
  for (int i = 0; i < [self.sessionSettings getEnabledDocumentTypesCount]; ++i) {
    NSLog(@" --> %@", [self.sessionSettings getEnabledDocumentTypeAt:i]);
  }
  
  self.session = [self.engine spawnSessionWithSettings:self.sessionSettings
                                         withSignature:self.signature
                                  withFeedbackReporter:nil
                                 withExternalProcessor:nil];
  self.pageNumber = 1;
  
  self.sessionRunning = YES;
  
  if (delegateReceivesSessionStarted) {
    [self.initializationDelegate SmartDocumentEngineSessionStarted];
  }
}

- (void) dismissSession {
  self.sessionRunning = NO;
  self.session = nil;
  self.pageNumber = 0;

  if (delegateReceivesSessionDismissed) {
    [self.initializationDelegate SmartDocumentEngineSessionDismissed];
  }
}

- (void) processSingleImage:(nonnull SECommonImageRef *)image{
  if (self.sessionRunning) {
    [self.session reset];
    self.pageNumber = 0;
    
    SEDocProcessingSettings* proc_settings = [self.session createProcessingSettings];
    [[proc_settings getMutableRef] setOptionWithName:@"page_number" to:[NSString stringWithFormat:@"%d", self.pageNumber]];
    
    int src_id = [self.session registerImage:image];
    [[proc_settings getMutableRef] setCurrentSourceIDTo:src_id];
    [self.session process:proc_settings];
    
    self.frameId = proc_settings.getRef.getCurrentSourceID;
    SEDocResultRef* result = [self.session getMutableCurrentResult];

    dispatch_async(dispatch_get_main_queue(), ^{
      if (self->delegateReceivesSingleImageResults) {
        [self.engineDelegate SmartDocumentEngineObtainedSingleImageResult:result];
      }
    });
  }
}

- (void) processSingleImageFromFile:(nonnull NSString *)filePath {
  if (self.sessionRunning) {
    SECommonImage* image = [[SECommonImage alloc] initFromFile:filePath
                                                   withMaxSize:nil];
    [self processSingleImage:[image getRef]];
  }
}

- (void) processSingleImageFromUIImage:(nonnull UIImage *)image {
  if (self.sessionRunning) {
    SECommonImage* proxyImage = [[SECommonImage alloc] initFromUIImage:image];
    [self processSingleImage:[proxyImage getRef]];
  }
}

- (void) addSingleImage:(nonnull SECommonImageRef *)image {
  if (self.sessionRunning) {
    self.pageNumber++;
    
    SEDocProcessingSettings* proc_settings = [self.session createProcessingSettings];
    [[proc_settings getMutableRef] setOptionWithName:@"page_number" to:[NSString stringWithFormat:@"%d", self.pageNumber]];
    
    int src_id = [self.session registerImage:image];
    [[proc_settings getMutableRef] setCurrentSourceIDTo:src_id];
    [self.session process:proc_settings];
    
    self.frameId = proc_settings.getRef.getCurrentSourceID;
    SEDocResultRef* result = [self.session getCurrentResult];
    
    dispatch_async(dispatch_get_main_queue(), ^{
      if (self->delegateReceivesSingleImageResults) {
        [self.engineDelegate SmartDocumentEngineObtainedSingleImageResult:result];
      }
    });
  }
}

- (void) addSingleImageFromFile:(nonnull NSString *)filePath {
  if (self.sessionRunning) {
    SECommonImage* image = [[SECommonImage alloc] initFromFile:filePath
                                                   withMaxSize:nil];
    [self addSingleImage:[image getRef]];
  }
}

- (void) addSingleImageFromUIImage:(nonnull UIImage *)image {
  if (self.sessionRunning) {
    SECommonImage* proxyImage = [[SECommonImage alloc] initFromUIImage:image];
    [self addSingleImage:[proxyImage getRef]];
  }
}

- (void) processImage:(nonnull SECommonImageRef *)image{
  if (self.sessionRunning) {
    [self.session reset];
    self.pageNumber = 0;
    
    SEDocProcessingSettings* proc_settings = [self.session createProcessingSettings];
    [[proc_settings getMutableRef] setOptionWithName:@"page_number" to:[NSString stringWithFormat:@"%d", self.pageNumber]];
    
    [self.session processImage:image withProcessingSettings:proc_settings];
    
    SEDocResultRef* result = [self.session getMutableCurrentResult];
    if ([NSThread isMainThread]) {
      if (delegateReceivesSingleImageResults) {
        [self.engineDelegate SmartDocumentEngineObtainedSingleImageResult:result];
      }
    } else {
      dispatch_sync(dispatch_get_main_queue(), ^{
        if (delegateReceivesSingleImageResults) {
          [self.engineDelegate SmartDocumentEngineObtainedSingleImageResult:result];
        }
      });
    }
  }
}


- (void) processImageFromFile:(nonnull NSString *)filePath {
  if (self.sessionRunning) {
    SECommonImage* image = [[SECommonImage alloc] initFromFile:filePath
                                                   withMaxSize:nil];
    [self processImage:[image getRef]];
  }
}

- (void) processImageFromUIImage:(nonnull UIImage *)image {
  if (self.sessionRunning) {
    SECommonImage* proxyImage = [[SECommonImage alloc] initFromUIImage:image];
    [self processImage:[proxyImage getRef]];
  }
}

- (void) addImage:(nonnull SECommonImageRef *)image {
  if (self.sessionRunning) {
    self.pageNumber++;
    
    SEDocProcessingSettings* proc_settings = [self.session createProcessingSettings];
    [[proc_settings getMutableRef] setOptionWithName:@"page_number" to:[NSString stringWithFormat:@"%d", self.pageNumber]];
    
    [self.session processImage:image withProcessingSettings:proc_settings];
    
    SEDocResultRef* result = [self.session getCurrentResult];
    
    dispatch_async(dispatch_get_main_queue(), ^{
      if (self->delegateReceivesSingleImageResults) {
        [self.engineDelegate SmartDocumentEngineObtainedSingleImageResult:result];
      }
    });
  }
}

- (void) addImageFromFile:(nonnull NSString *)filePath {
  if (self.sessionRunning) {
    SECommonImage* image = [[SECommonImage alloc] initFromFile:filePath
                                                   withMaxSize:nil];
    [self addImage:[image getRef]];
  }
}

- (void) addImageFromUIImage:(nonnull UIImage *)image {
  if (self.sessionRunning) {
    SECommonImage* proxyImage = [[SECommonImage alloc] initFromUIImage:image];
    [self addImage:[proxyImage getRef]];
  }
}

- (int) getCurrentFrameId {
  return self.frameId;
}
@end


#define TRANQUIL_SUPPORT

#import <Foundation/Foundation.h>
#import "HTTPConnection.h"

typedef void (^HTTPErrorBlock)(id reason);
typedef id (^HTTPHandlerBlock)(HTTPConnection *, ...);

@interface HTTP : NSObject
@property(readwrite, strong) NSString *publicDir;
@property(readwrite, assign) BOOL enableDirListing, enableKeepAlive;
@property(readwrite, assign) unsigned int numberOfThreads;

- (BOOL)listenOnPort:(NSUInteger)port onError:(HTTPErrorBlock)aErrorHandler;

- (void)handleGET:(id)aRoute    with:(id)aHandler;
- (void)handlePOST:(id)aRoute   with:(id)aHandler;
- (void)handlePUT:(id)aRoute    with:(id)aHandler;
- (void)handleDELETE:(id)aRoute with:(id)aHandler;
- (void)handleWebSocket:(id)aHandler;
@end

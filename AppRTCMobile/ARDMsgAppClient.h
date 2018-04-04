/*
 *  Copyright 2014 The WebRTC Project Authors. All rights reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#import <Foundation/Foundation.h>
#import "WebRTC/RTCPeerConnection.h"
#import "WebRTC/RTCDataChannel.h"

#import "ARDSignalingChannel.h"

typedef NS_ENUM(NSInteger, ARDMsgAppClientState) {
  // Disconnected from servers.
  kARDMsgAppClientStateDisconnected,
  // Connecting to servers.
  kARDMsgAppClientStateConnecting,
  // Connected to servers.
  kARDMsgAppClientStateConnected,
};

@class ARDMsgAppClient;
@class ARDSettingsModel;
@class RTCMediaConstraints;

// The delegate is informed of pertinent events and will be called on the
// main queue.
@protocol ARDMsgAppClientDelegate <NSObject>

- (void)appClient:(ARDMsgAppClient *)client
    didChangeState:(ARDMsgAppClientState)state;

- (void)appClient:(ARDMsgAppClient *)client
    didChangeConnectionState:(RTCIceConnectionState)state;

- (void)appClient:(ARDMsgAppClient *)client
         onMessage:(NSString *)message;

- (void)appClient:(ARDMsgAppClient *)client
         didError:(NSError *)error;

- (void)appClient:(ARDMsgAppClient *)client
      didGetStats:(NSArray *)stats;

@end

// Handles connections to the AppRTC server for a given room. Methods on this
// class should only be called from the main queue.
@interface ARDMsgAppClient : NSObject <RTCPeerConnectionDelegate, RTCDataChannelDelegate, ARDSignalingChannelDelegate>

// If |shouldGetStats| is true, stats will be reported in 1s intervals through
// the delegate.
@property(nonatomic, assign) BOOL shouldGetStats;
@property(nonatomic, readonly) ARDMsgAppClientState state;
@property(nonatomic, weak) id<ARDMsgAppClientDelegate> delegate;
// Convenience constructor since all expected use cases will need a delegate
// in order to receive remote tracks.
- (instancetype)initWithDelegate:(id<ARDMsgAppClientDelegate>)delegate;

// Establishes a connection with the AppRTC servers for the given room id.
// |settings| is an object containing settings such as video codec for the call.
// If |isLoopback| is true, the call will connect to itself.
- (void)connectToRoomWithId:(NSString *)roomId
                   settings:(ARDSettingsModel *)settings
                 isLoopback:(BOOL)isLoopback;

- (void)sendMessage:(NSString*)message;

// Disconnects from the AppRTC servers and any connected clients.
- (void)disconnect;

@end

/***************************************************************************
                                NetTCP.h
                          -------------------
    begin                : Fri Nov  2 01:19:16 UTC 2001
    copyright            : (C) 2002 by Andy Ruder
    email                : aeruder@yahoo.com
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#import "NetBase.h"
#import <Foundation/NSObject.h>

@class NSString, NSNumber, NSString, NSData, NSMutableData;

@interface TCPSystem : NSObject
{
	NSString *errorString;
}
+ sharedInstance;

- (NSString *)errorString;

- (id)connectNetObject: (Class)netObject toIp: (NSString *)ip 
                onPort: (int)aPort withTimeout: (int)timeout;
- (id)connectNetObject: (Class)netObject toHost: (NSString *)host 
                onPort: (int)aPort withTimeout: (int)timeout;

- (NSString *)hostFromIp: (NSString *)ip;
- (NSString *)ipFromHost: (NSString *)host;
@end

@interface TCPPort : NSObject < NetPort >
    {
		int desc;
		Class netObjectClass;
	}
- initOnHost: (NSString *)aHost onPort: (int)aPort;
- initOnPort: (int)aPort;
- setNetObject: (Class)aClass;
- (int)desc;
- (void)connectionLost;
- newConnection;
@end

@interface TCPTransport : NSObject < NetTransport >
    {
		int desc;
		BOOL connected;
		NSMutableData *writeBuffer;
		NSString *address;
	}
- initWithDesc: (int)aDesc atAddress:(NSString *)theAddress;
- (NSData *)readData: (int)maxDataSize;
- (BOOL)isDoneWriting;
- writeData: (NSData *)data;
- (NSString *)address;
- (int)desc;
- (void)close;
@end
		

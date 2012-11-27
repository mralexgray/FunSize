/* Copyright (c) 2011, Nate Stedman <natesm@gmail.com>
 * 
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#import "NSNotificationCenter+FunSize.h"

@implementation NSNotificationCenter (FunSize)

#pragma mark - Class-Level Shortcuts
+(void)addObserver:(id)observer selector:(SEL)aSelector name:(NSString*)aName object:(id)anObject
{
    [[self defaultCenter] addObserver:observer selector:aSelector name:aName object:anObject];
}

+(id)addObserverForName:(NSString*)name
                 object:(id)obj
                  queue:(NSOperationQueue*)queue
             usingBlock:(void (^)(NSNotification*))block
{
    return [[self defaultCenter] addObserverForName:name object:obj queue:queue usingBlock:block];
}

+(void)postNotification:(NSNotification*)notification
{
    [[self defaultCenter] postNotification:notification];
}

+(void)postNotificationName:(NSString*)aName object:(id)anObject
{
    [[self defaultCenter] postNotificationName:aName object:anObject];
}

+(void)postNotificationName:(NSString*)aName object:(id)anObject userInfo:(NSDictionary*)aUserInfo
{
    [[self defaultCenter] postNotificationName:aName object:anObject userInfo:aUserInfo];
}

+(void)removeObserver:(id)observer
{
    [[self defaultCenter] removeObserver:observer];
}

+(void)removeObserver:(id)observer name:(NSString*)aName object:(id)anObject
{
    [[self defaultCenter] removeObserver:observer name:aName object:anObject];
}

#pragma mark - Posting Notifications on the Main Thread
-(void)postNotificationOnMainThread:(NSNotification*)notification
{
    [self postNotificationOnMainThread:notification waitUntilDone:NO];
}

-(void)postNotificationNameOnMainThread:(NSString*)aName object:(id)anObject
{
    [self postNotificationNameOnMainThread:aName object:anObject waitUntilDone:NO];
}

-(void)postNotificationNameOnMainThread:(NSString*)aName object:(id)anObject userInfo:(NSDictionary*)aUserInfo
{
    [self postNotificationNameOnMainThread:aName object:anObject userInfo:aUserInfo waitUntilDone:NO];
}

-(void)postNotificationOnMainThread:(NSNotification*)notification waitUntilDone:(BOOL)wait
{
    [self performSelectorOnMainThread:@selector(postNotification:) withObject:notification waitUntilDone:wait];
}

-(void)postNotificationNameOnMainThread:(NSString*)aName object:(id)anObject waitUntilDone:(BOOL)wait
{
    [self postNotificationNameOnMainThread:aName object:anObject userInfo:nil waitUntilDone:wait];
}

-(void)postNotificationNameOnMainThread:(NSString*)aName
                                 object:(id)anObject
                               userInfo:(NSDictionary*)aUserInfo
                          waitUntilDone:(BOOL)wait
{
    NSNotification* notification = [NSNotification notificationWithName:aName object:anObject userInfo:aUserInfo];
    [self postNotificationOnMainThread:notification waitUntilDone:wait];
}

#pragma mark - Class-Level Shortcuts for Posting Notifications on the Main Thread
+(void)postNotificationOnMainThread:(NSNotification*)notification
{
    [[self defaultCenter] postNotificationOnMainThread:notification];
}

+(void)postNotificationNameOnMainThread:(NSString*)aName object:(id)anObject
{
    [[self defaultCenter] postNotificationNameOnMainThread:aName object:anObject];
}

+(void)postNotificationNameOnMainThread:(NSString*)aName object:(id)anObject userInfo:(NSDictionary*)aUserInfo
{
    [[self defaultCenter] postNotificationNameOnMainThread:aName object:anObject userInfo:aUserInfo];
}

+(void)postNotificationOnMainThread:(NSNotification*)notification waitUntilDone:(BOOL)wait
{
    [[self defaultCenter] postNotificationOnMainThread:notification waitUntilDone:wait];
}

+(void)postNotificationNameOnMainThread:(NSString*)aName object:(id)anObject waitUntilDone:(BOOL)wait
{
    [[self defaultCenter] postNotificationNameOnMainThread:aName object:anObject waitUntilDone:wait];
}

+(void)postNotificationNameOnMainThread:(NSString*)aName
                                 object:(id)anObject
                               userInfo:(NSDictionary*)aUserInfo
                          waitUntilDone:(BOOL)wait
{
    [[self defaultCenter] postNotificationNameOnMainThread:aName object:anObject userInfo:aUserInfo waitUntilDone:wait];
}

@end

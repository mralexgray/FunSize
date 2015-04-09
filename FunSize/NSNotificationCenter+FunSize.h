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
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.	*/

@interface NSNotificationCenter (FunSize)

#pragma mark Class-Level Shortcuts
/** @name Class-Level Shortcuts */

/**	A class-level shortcut for the instance member, which is passed to `+defaultCenter`.
 *
 * @param observer The object to register as an observer.
 * @param aSelector A selector that specifies the message the observer will receive. The message should have one
 * argument, the `NSNotification` instance.
 * @param aName The name of the notification to register the observer for, or `nil` to receive all notifications.
 * @param anObject The object whose notifications the observer should be registered for, or `nil` to receive
 * notifications from all objects.	*/
+(void)addObserver:(id)observer selector:(SEL)aSelector name:(NSString*)aName object:(id)anObject;

/**	A class-level shortcut for the instance member, which is passed to `+defaultCenter`.
 *
 * @param name The name of the notification to register for, or `nil` to receive all notifications.
 * @param obj The object whose notifications should be registered for, or `nil` to receive notifications from all
 * objects.
 * @param queue The operation queue that the block should run on. If `nil` is passed, the block will run on the
 * posting thread.
 * @param block A block to be executed when the notification is posted. The block takes one argument, the
 * `NSNotification` instance.	*/
+(id)addObserverForName:(NSString*)name
                 object:(id)obj
                  queue:(NSOperationQueue*)queue
             usingBlock:(void (^)(NSNotification*))block;
             
/**	A class-level shortcut for the instance member, which is passed to `+defaultCenter`.
 * 
 * @param notification The notification to post.	*/
+(void)postNotification:(NSNotification*)notification;

/**	A class-level shortcut for the instance member, which is passed to `+defaultCenter`.
 *
 * @param aName The notification's name.
 * @param anObject The notification's object.	*/
+(void)postNotificationName:(NSString*)aName object:(id)anObject;

/**	A class-level shortcut for the instance member, which is passed to `+defaultCenter`.
 *
 * @param aName The notification's name.
 * @param anObject The notification's object.
 * @param aUserInfo The notification's user info dictionary.	*/
+(void)postNotificationName:(NSString*)aName object:(id)anObject userInfo:(NSDictionary*)aUserInfo;

/**	A class-level shortcut for the instance member, which is passed to `+defaultCenter`.
 *
 * @param observer The observer to remove.	*/
+(void)removeObserver:(id)observer;

/**	A class-level shortcut for the instance member, which is passed to `+defaultCenter`.
 *
 * @param observer The observer to remove.
 * @param aName The notification name to remove the observer for.
 * @param anObject The notification object to remove the observer for (or `nil`).	*/
+(void)removeObserver:(id)observer name:(NSString*)aName object:(id)anObject;

#pragma mark Posting Notifications on the Main Thread
/** @name Posting Notifications on the Main Thread */

/**	Posts a notification on the main thread.
 * 
 * This message will not wait for the selector to be performed on the main
 * thread.
 * 
 * @param notification The notification to post.	*/
-(void)postNotificationOnMainThread:(NSNotification*)notification;

/**	Posts a notification with a name and an object on the main thread.
 * 
 * This message will not wait for the selector to be performed on the main
 * thread.
 * 
 * @param aName The notification's name.
 * @param anObject The notification's object.	*/
-(void)postNotificationNameOnMainThread:(NSString*)aName object:(id)anObject;

/**	Posts a notification with a name, an object, and a user info dictionary on
 * the main thread.
 * 
 * This message will not wait for the selector to be performed on the main
 * thread.
 * 
 * @param aName The notification's name.
 * @param anObject The notification's object.
 * @param aUserInfo The notification's user info dictionary.	*/
-(void)postNotificationNameOnMainThread:(NSString*)aName object:(id)anObject userInfo:(NSDictionary*)aUserInfo;

/**	Posts a notification on the main thread.
 * 
 * @param notification The notification to post.
 * @param wait If the message should wait for the selector to be performed on
 * the main thread before returning.	*/
-(void)postNotificationOnMainThread:(NSNotification*)notification waitUntilDone:(BOOL)wait;

/**	Posts a notification with a name and an object on the main thread.
 * 
 * @param aName The notification's name.
 * @param anObject The notification's object.
 * @param wait If the message should wait for the selector to be performed on
 * the main thread before returning.	*/
-(void)postNotificationNameOnMainThread:(NSString*)aName object:(id)anObject waitUntilDone:(BOOL)wait;

/**	Posts a notification with a name, an object, and a user info dictionary on
 * the main thread.
 * 
 * @param aName The notification's name.
 * @param anObject The notification's object.
 * @param aUserInfo The notification's user info dictionary.
 * @param wait If the message should wait for the selector to be performed on
 * the main thread before returning.	*/
-(void)postNotificationNameOnMainThread:(NSString*)aName
                                 object:(id)anObject
                               userInfo:(NSDictionary*)aUserInfo
                          waitUntilDone:(BOOL)wait;

#pragma mark Class-Level Shortcuts for Posting Notifications on the Main Thread
/** @name Class-Level Shortcuts for Posting Notifications on the Main Thread */

/**	A class-level shortcut for the instance member provided by this category,
 * which is passed to `+defaultCenter`.
 * 
 * @param notification The notification to send.	*/
+(void)postNotificationOnMainThread:(NSNotification*)notification;

/**	A class-level shortcut for the instance member provided by this category,
 * which is passed to `+defaultCenter`.
 *
 * @param aName The notification's name.
 * @param anObject The notification's object.	*/
+(void)postNotificationNameOnMainThread:(NSString*)aName object:(id)anObject;

/**	A class-level shortcut for the instance member provided by this category,
 * which is passed to `+defaultCenter`.
 *
 * @param aName The notification's name.
 * @param anObject The notification's object.
 * @param aUserInfo The notification's user info dictionary.	*/
+(void)postNotificationNameOnMainThread:(NSString*)aName object:(id)anObject userInfo:(NSDictionary*)aUserInfo;

/**	A class-level shortcut for the instance member provided by this category,
 * which is passed to `+defaultCenter`.
 * 
 * @param notification The notification to post.
 * @param wait If the message should wait for the selector to be performed on
 * the main thread before returning.	*/
+(void)postNotificationOnMainThread:(NSNotification*)notification waitUntilDone:(BOOL)wait;

/**	A class-level shortcut for the instance member provided by this category,
 * which is passed to `+defaultCenter`.
 * 
 * @param aName The notification's name.
 * @param anObject The notification's object.
 * @param wait If the message should wait for the selector to be performed on
 * the main thread before returning.	*/
+(void)postNotificationNameOnMainThread:(NSString*)aName object:(id)anObject waitUntilDone:(BOOL)wait;

/**	A class-level shortcut for the instance member provided by this category,
 * which is passed to `+defaultCenter`.
 * 
 * @param aName The notification's name.
 * @param anObject The notification's object.
 * @param aUserInfo The notification's user info dictionary.
 * @param wait If the message should wait for the selector to be performed on
 * the main thread before returning.	*/
+(void)postNotificationNameOnMainThread:(NSString*)aName
                                 object:(id)anObject
                               userInfo:(NSDictionary*)aUserInfo
                          waitUntilDone:(BOOL)wait;

@end

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

#import <AppKit/AppKit.h>

@interface NSUserDefaults (FunSize)

#pragma mark Rects
/** @name Storing Rects */

/**	Retrieves a `NSRect` (stored as a string) from the user defaults.
 * 
 * @param defaultName The key the rect is stored under.	*/
-(NSRect)rectForKey:(NSString*)defaultName;

/**	Stores an `NSRect` (as a string) in the user defaults.
 * 
 * @param value The value to store.
 * @param defaultName The key to store the rect under.	*/
-(void)setRect:(NSRect)value forKey:(NSString*)defaultName;

/**	Retrieves a `CGRect` (stored as a string) from the user defaults.
 * 
 * @param defaultName The key the rect is stored under.	*/
-(CGRect)CGRectForKey:(NSString*)defaultName;

/**	Stores a `CGRect` (as a string) in the user defaults.
 * 
 * @param value The value to store.
 * @param defaultName The key to store the rect under.	*/
-(void)setCGRect:(CGRect)value forKey:(NSString*)defaultName;

#pragma mark Points
/** @name Storing Points */

/**	Retrieves a `NSPoint` (stored as a string) from the user defaults.
 * 
 * @param defaultName The key the point is stored under.	*/
-(NSPoint)pointForKey:(NSString*)defaultName;

/**	Stores an `NSPoint` (as a string) in the user defaults.
 * 
 * @param value The value to store.
 * @param defaultName The key to store the point under.	*/
-(void)setPoint:(NSPoint)value forKey:(NSString*)defaultName;

/**	Retrieves a `CGPoint` (stored as a string) from the user defaults.
 * 
 * @param defaultName The key the point is stored under.	*/
-(CGPoint)CGPointForKey:(NSString*)defaultName;

/**	Stores a `CGPoint` (as a string) in the user defaults.
 * 
 * @param value The value to store.
 * @param defaultName The key to store the point under.	*/
-(void)setCGPoint:(CGPoint)value forKey:(NSString*)defaultName;

#pragma mark Sizes
/** @name Storing Sizes */

/**	Retrieves a `NSSize` (stored as a string) from the user defaults.
 * 
 * @param defaultName The key the size is stored under.	*/
-(NSSize)sizeForKey:(NSString*)defaultName;

/**	Stores an `NSSize` (as a string) in the user defaults.
 * 
 * @param value The value to store.
 * @param defaultName The key to store the size under.	*/
-(void)setSize:(NSSize)value forKey:(NSString*)defaultName;

/**	Retrieves a `CGSize` (stored as a string) from the user defaults.
 * 
 * @param defaultName The key the size is stored under.	*/
-(CGSize)CGSizeForKey:(NSString*)defaultName;

/**	Stores a `CGSize` (as a string) in the user defaults.
 * 
 * @param value The value to store.
 * @param defaultName The key to store the size under.	*/
-(void)setCGSize:(CGSize)value forKey:(NSString*)defaultName;

#pragma mark NSRange
/** @name Storing Ranges */

/**	Retrieves a `NSRange` (stored as a string) from the user defaults.
 * 
 * @param defaultName The key the range is stored under.	*/
-(NSRange)rangeForKey:(NSString*)defaultName;

/**	Stores an `NSRange` (as a string) in the user defaults.
 * 
 * @param value The value to store.
 * @param defaultName The key to store the range under.	*/
-(void)setRange:(NSRange)value forKey:(NSString*)defaultName;

#pragma mark Class-Level Shortcuts
/** @name Class-Level Shortcuts */

/**	Sends the instance-level message to `+standardUserDefaults`.
 * 
 * @param defaultName The user default to retrieve.	*/
+(NSArray*)arrayForKey:(NSString*)defaultName;

/**	Sends the instance-level message to `+standardUserDefaults`.
 * 
 * @param defaultName The user default to retrieve.	*/
+(BOOL)boolForKey:(NSString*)defaultName;

/**	Sends the instance-level message to `+standardUserDefaults`.
 * 
 * @param defaultName The user default to retrieve.	*/
+(NSData*)dataForKey:(NSString*)defaultName;

/**	Sends the instance-level message to `+standardUserDefaults`.
 * 
 * @param defaultName The user default to retrieve.	*/
+(NSDictionary*)dictionaryForKey:(NSString*)defaultName;

/**	Sends the instance-level message to `+standardUserDefaults`.
 * 
 * @param defaultName The user default to retrieve.	*/
+(float)floatForKey:(NSString*)defaultName;

/**	Sends the instance-level message to `+standardUserDefaults`.
 * 
 * @param defaultName The user default to retrieve.	*/
+(NSInteger)integerForKey:(NSString*)defaultName;

/**	Sends the instance-level message to `+standardUserDefaults`.
 * 
 * @param defaultName The user default to retrieve.	*/
+(id)objectForKey:(NSString*)defaultName;

/**	Sends the instance-level message to `+standardUserDefaults`.
 * 
 * @param defaultName The user default to retrieve.	*/
+(NSArray*)stringArrayForKey:(NSString*)defaultName;

/**	Sends the instance-level message to `+standardUserDefaults`.
 * 
 * @param defaultName The user default to retrieve.	*/
+(NSString*)stringForKey:(NSString*)defaultName;

/**	Sends the instance-level message to `+standardUserDefaults`.
 * 
 * @param defaultName The user default to retrieve.	*/
+(double)doubleForKey:(NSString*)defaultName;

/**	Sends the instance-level message to `+standardUserDefaults`.
 * 
 * @param defaultName The user default to retrieve.	*/
+(NSURL*)URLForKey:(NSString*)defaultName;

/**	Sends the instance-level message to `+standardUserDefaults`.
 * 
 * @param value The value to set.
 * @param defaultName The user default to set.	*/
+(void)setBool:(BOOL)value forKey:(NSString*)defaultName;

/**	Sends the instance-level message to `+standardUserDefaults`.
 * 
 * @param value The value to set.
 * @param defaultName The user default to set.	*/
+(void)setFloat:(float)value forKey:(NSString*)defaultName;

/**	Sends the instance-level message to `+standardUserDefaults`.
 * 
 * @param value The value to set.
 * @param defaultName The user default to set.	*/
+(void)setInteger:(NSInteger)value forKey:(NSString*)defaultName;

/**	Sends the instance-level message to `+standardUserDefaults`.
 * 
 * @param value The value to set.
 * @param defaultName The user default to set.	*/
+(void)setObject:(id)value forKey:(NSString*)defaultName;

/**	Sends the instance-level message to `+standardUserDefaults`.
 * 
 * @param value The value to set.
 * @param defaultName The user default to set.	*/
+(void)setDouble:(double)value forKey:(NSString*)defaultName;

/**	Sends the instance-level message to `+standardUserDefaults`.
 * 
 * @param url The URL to set.
 * @param defaultName The user default to set.	*/
+(void)setURL:(NSURL*)url forKey:(NSString*)defaultName;

#pragma mark Class-Level Shortcuts for Rects
/** @name Class-Level Shortcuts for Rects */

/**	Retrieves a `NSRect` (stored as a string) from the standard user defaults.
 * 
 * @param defaultName The key the rect is stored under.	*/
+(NSRect)rectForKey:(NSString*)defaultName;

/**	Stores an `NSRect` (as a string) in the standard user defaults.
 * 
 * @param value The value to store.
 * @param defaultName The key to store the rect under.	*/
+(void)setRect:(NSRect)value forKey:(NSString*)defaultName;

/**	Retrieves a `CGRect` (stored as a string) from the standard user defaults.
 * 
 * @param defaultName The key the rect is stored under.	*/
+(CGRect)CGRectForKey:(NSString*)defaultName;

/**	Stores a `CGRect` (as a string) in the standard user defaults.
 * 
 * @param value The value to store.
 * @param defaultName The key to store the rect under.	*/
+(void)setCGRect:(CGRect)value forKey:(NSString*)defaultName;

#pragma mark Class-Level Shortcuts for Points
/** @name Class-Level Shortcuts for Points */

/**	Retrieves a `NSPoint` (stored as a string) from the standard user defaults.
 * 
 * @param defaultName The key the point is stored under.	*/
+(NSPoint)pointForKey:(NSString*)defaultName;

/**	Stores an `NSPoint` (as a string) in the standard user defaults.
 * 
 * @param value The value to store.
 * @param defaultName The key to store the point under.	*/
+(void)setPoint:(NSPoint)value forKey:(NSString*)defaultName;

/**	Retrieves a `CGPoint` (stored as a string) from the standard user defaults.
 * 
 * @param defaultName The key the point is stored under.	*/
+(CGPoint)CGPointForKey:(NSString*)defaultName;

/**	Stores a `CGPoint` (as a string) in the standard user defaults.
 * 
 * @param value The value to store.
 * @param defaultName The key to store the point under.	*/
+(void)setCGPoint:(CGPoint)value forKey:(NSString*)defaultName;

#pragma mark Class-Level Shortcuts for Sizes
/** @name Class-Level Shortcuts for Sizes */

/**	Retrieves a `NSSize` (stored as a string) from the standard user defaults.
 * 
 * @param defaultName The key the size is stored under.	*/
+(NSSize)sizeForKey:(NSString*)defaultName;

/**	Stores an `NSSize` (as a string) in the standard user defaults.
 * 
 * @param value The value to store.
 * @param defaultName The key to store the size under.	*/
+(void)setSize:(NSSize)value forKey:(NSString*)defaultName;

/**	Retrieves a `CGSize` (stored as a string) from the standard user defaults.
 * 
 * @param defaultName The key the size is stored under.	*/
+(CGSize)CGSizeForKey:(NSString*)defaultName;

/**	Stores a `CGSize` (as a string) in the standard user defaults.
 * 
 * @param value The value to store.
 * @param defaultName The key to store the size under.	*/
+(void)setCGSize:(CGSize)value forKey:(NSString*)defaultName;

#pragma mark Class-Level Shortcuts for NSRange
/** @name Class-Level Shortcuts for Ranges */

/**	Retrieves a `NSRange` (stored as a string) from the standard user defaults.
 * 
 * @param defaultName The key the range is stored under.	*/
+(NSRange)rangeForKey:(NSString*)defaultName;

/**	Stores an `NSRange` (as a string) in the standard user defaults.
 * 
 * @param value The value to store.
 * @param defaultName The key to store the range under.	*/
+(void)setRange:(NSRange)value forKey:(NSString*)defaultName;

@end

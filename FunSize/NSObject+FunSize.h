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

#import <Cocoa/Cocoa.h>
#import <Quartz/Quartz.h>

@interface NSObject (FunSize)

#pragma mark -
#pragma mark Properties
/** @name Properties */

/**
 * Iterates over the object's properties with a block.
 * 
 * @param propertyBlock A block, which will receive each property's name as an
 * `NSString*`.
 */
-(void)iteratePropertiesWithBlock:(void (^)(NSString*))propertyBlock;

#pragma mark -
#pragma mark Floating Point NSNumber valueForKey:/setValue:forKey:
/** @name Floating Point Keys */

/**
 * Retrieves a float value for a specified key.
 *
 * @param key The key.
 */
-(float)floatForKey:(NSString*)key;

/**
 * Sets a float value for a specified key.
 *
 * @param value The value to set.
 * @param key The key.
 */
-(void)setFloat:(float)value forKey:(NSString*)key;

/**
 * Retrieves a double value for a specified key.
 *
 * @param key The key.
 */
-(double)doubleForKey:(NSString*)key;

/**
 * Sets a double value for a specified key.
 *
 * @param value The value to set.
 * @param key The key.
 */
-(void)setDouble:(double)value forKey:(NSString*)key;

#pragma mark -
#pragma mark Signed NSNumber valueForKey:/setValue:forKey:
/** @name Signed Integer Keys */

/**
 * Retrieves a boolean value for a specified key.
 *
 * @param key The key.
 */
-(BOOL)boolForKey:(NSString*)key;

/**
 * Sets a boolean value for a specified key.
 *
 * @param value The value to set.
 * @param key The key.
 */
-(void)setBool:(BOOL)value forKey:(NSString*)key;

/**
 * Retrieves a character value for a specified key.
 *
 * @param key The key.
 */
-(char)charForKey:(NSString*)key;

/**
 * Sets a character value for a specified key.
 *
 * @param value The value to set.
 * @param key The key.
 */
-(void)setChar:(char)value forKey:(NSString*)key;

/**
 * Retrieves an `int` value for a specified key.
 *
 * @param key The key.
 */
-(int)intForKey:(NSString*)key;

/**
 * Sets an `int` value for a specified key.
 *
 * @param value The value to set.
 * @param key The key.
 */
-(void)setInt:(int)value forKey:(NSString*)key;

/**
 * Retrieves an `log` value for a specified key.
 *
 * @param key The key.
 */
-(long)longForKey:(NSString*)key;

/**
 * Sets an `long` value for a specified key.
 *
 * @param value The value to set.
 * @param key The key.
 */
-(void)setLong:(long)value forKey:(NSString*)key;

/**
 * Retrieves an `long long` value for a specified key.
 *
 * @param key The key.
 */
-(long long)longLongForKey:(NSString*)key;

/**
 * Sets an `long long` value for a specified key.
 *
 * @param value The value to set.
 * @param key The key.
 */
-(void)setLongLong:(long long)value forKey:(NSString*)key;

/**
 * Retrieves an integer value for a specified key.
 *
 * @param key The key.
 */
-(NSInteger)integerForKey:(NSString*)key;

/**
 * Sets an integer value for a specified key.
 *
 * @param value The value to set.
 * @param key The key.
 */
-(void)setInteger:(NSInteger)value forKey:(NSString*)key;

#pragma mark -
#pragma mark Unsigned NSNumber valueForKey:/setValue:forKey:
/** @name Unsigned Integer Keys */

/**
 * Retrieves an unsigned character value for a specified key.
 *
 * @param key The key.
 */
-(unsigned char)unsignedCharForKey:(NSString*)key;

/**
 * Sets an unsigned character value for a specified key.
 *
 * @param value The value to set.
 * @param key The key.
 */
-(void)setUnsignedChar:(unsigned char)value forKey:(NSString*)key;

/**
 * Retrieves an `unsigned short` value for a specified key.
 *
 * @param key The key.
 */
-(unsigned short)unsignedShortForKey:(NSString*)key;

/**
 * Sets an `unsigned short` value for a specified key.
 *
 * @param value The value to set.
 * @param key The key.
 */
-(void)setUnsignedShort:(unsigned short)value forKey:(NSString*)key;

/**
 * Retrieves an `unsigned int` value for a specified key.
 *
 * @param key The key.
 */
-(unsigned unsigned int)unsignedIntForKey:(NSString*)key;

/**
 * Sets an `unsigned int` value for a specified key.
 *
 * @param value The value to set.
 * @param key The key.
 */
-(void)setUnsignedInt:(unsigned int)value forKey:(NSString*)key;

/**
 * Retrieves an unsigned integer value for a specified key.
 *
 * @param key The key.
 */
-(NSUInteger)unsignedIntegerForKey:(NSString*)key;

/**
 * Sets an unsigned integer value for a specified key.
 *
 * @param value The value to set.
 * @param key The key.
 */
-(void)setUnsignedInteger:(NSUInteger)value forKey:(NSString*)key;

/**
 * Retrieves an `unsigned long` value for a specified key.
 *
 * @param key The key.
 */
-(unsigned long)unsignedLongForKey:(NSString*)key;

/**
 * Sets an `unsigned long` value for a specified key.
 *
 * @param value The value to set.
 * @param key The key.
 */
-(void)setUnsignedLong:(unsigned long)value forKey:(NSString*)key;

/**
 * Retrieves an `unsigned long long` value for a specified key.
 *
 * @param key The key.
 */
-(unsigned long long)unsignedLongLongForKey:(NSString*)key;

/**
 * Sets an `unsigned long long` value for a specified key.
 *
 * @param value The value to set.
 * @param key The key.
 */
-(void)setUnsignedLongLong:(unsigned long long)value forKey:(NSString*)key;

#pragma mark -
#pragma mark NSValue valueForKey:/setValue:forKey:
/** @name NSValue Keys */

/**
 * Retrieves an `NSSize` value for a specified key.
 *
 * @param key The key.
 */
-(NSSize)sizeForKey:(NSString*)key;

/**
 * Sets an `NSSize` value for a specified key.
 *
 * @param value The value to set.
 * @param key The key.
 */
-(void)setSize:(NSSize)value forKey:(NSString*)key;

/**
 * Retrieves an `NSRange` value for a specified key.
 *
 * @param key The key.
 */
-(NSRange)rangeForKey:(NSString*)key;

/**
 * Sets an `NSRange` value for a specified key.
 *
 * @param value The value to set.
 * @param key The key.
 */
-(void)setRange:(NSRange)value forKey:(NSString*)key;

/**
 * Retrieves an `NSRect` value for a specified key.
 *
 * @param key The key.
 */
-(NSRect)rectForKey:(NSString*)key;

/**
 * Sets an `NSRect` value for a specified key.
 *
 * @param value The value to set.
 * @param key The key.
 */
-(void)setRect:(NSRect)value forKey:(NSString*)key;

/**
 * Retrieves an `NSPoint` value for a specified key.
 *
 * @param key The key.
 */
-(NSPoint)pointForKey:(NSString*)key;

/**
 * Sets an `NSPoint` value for a specified key.
 *
 * @param value The value to set.
 * @param key The key.
 */
-(void)setPoint:(NSPoint)value forKey:(NSString*)key;

/**
 * Retrieves an `CATransform3D` value for a specified key.
 *
 * @param key The key.
 */
-(CATransform3D)CATransform3DForKey:(NSString*)key;

/**
 * Sets an `CATransform3D` value for a specified key.
 *
 * @param value The value to set.
 * @param key The key.
 */
-(void)setCATransform3D:(CATransform3D)value forKey:(NSString*)key;

#pragma mark -
#pragma mark Floating Point NSNumber valueForKeyPath:/setValue:forKeyPath:
/** @name Floating Point Key Paths */

/**
 * Retrieves a float value for a specified key path.
 *
 * @param keyPath The key path.
 */
-(float)floatForKeyPath:(NSString*)keyPath;

/**
 * Sets a float value for a specified key path.
 *
 * @param value The value to set.
 * @param keyPath The key path.
 */
-(void)setFloat:(float)value forKeyPath:(NSString*)keyPath;

/**
 * Retrieves a double value for a specified key path.
 *
 * @param keyPath The key path.
 */
-(double)doubleForKeyPath:(NSString*)keyPath;

/**
 * Sets a double value for a specified key path.
 *
 * @param value The value to set.
 * @param keyPath The key path.
 */
-(void)setDouble:(double)value forKeyPath:(NSString*)keyPath;

#pragma mark -
#pragma mark Signed NSNumber valueForKeyPath:/setValue:forKeyPath:
/** @name Signed Integer Key Paths */

/**
 * Retrieves a boolean value for a specified key path.
 *
 * @param keyPath The key path.
 */
-(BOOL)boolForKeyPath:(NSString*)keyPath;

/**
 * Sets a boolean value for a specified key path.
 *
 * @param value The value to set.
 * @param keyPath The key path.
 */
-(void)setBool:(BOOL)value forKeyPath:(NSString*)keyPath;

/**
 * Retrieves a character value for a specified key path.
 *
 * @param keyPath The key path.
 */
-(char)charForKeyPath:(NSString*)keyPath;

/**
 * Sets a character value for a specified key path.
 *
 * @param value The value to set.
 * @param keyPath The key path.
 */
-(void)setChar:(char)value forKeyPath:(NSString*)keyPath;

/**
 * Retrieves an `int` value for a specified key path.
 *
 * @param keyPath The key path.
 */
-(int)intForKeyPath:(NSString*)keyPath;

/**
 * Sets an `int` value for a specified key path.
 *
 * @param value The value to set.
 * @param keyPath The key path.
 */
-(void)setInt:(int)value forKeyPath:(NSString*)keyPath;

/**
 * Retrieves an `log` value for a specified key path.
 *
 * @param keyPath The key path.
 */
-(long)longForKeyPath:(NSString*)keyPath;

/**
 * Sets an `long` value for a specified key path.
 *
 * @param value The value to set.
 * @param keyPath The key path.
 */
-(void)setLong:(long)value forKeyPath:(NSString*)keyPath;

/**
 * Retrieves an `long long` value for a specified key path.
 *
 * @param keyPath The key path.
 */
-(long long)longLongForKeyPath:(NSString*)keyPath;

/**
 * Sets an `long long` value for a specified key path.
 *
 * @param value The value to set.
 * @param keyPath The key path.
 */
-(void)setLongLong:(long long)value forKeyPath:(NSString*)keyPath;

/**
 * Retrieves an integer value for a specified key path.
 *
 * @param keyPath The key path.
 */
-(NSInteger)integerForKeyPath:(NSString*)keyPath;

/**
 * Sets an integer value for a specified key path.
 *
 * @param value The value to set.
 * @param keyPath The key path.
 */
-(void)setInteger:(NSInteger)value forKeyPath:(NSString*)keyPath;

#pragma mark -
#pragma mark Unsigned NSNumber valueForKeyPath:/setValue:forKeyPath:
/** @name Unsigned Integer Key Paths */

/**
 * Retrieves an unsigned character value for a specified key path.
 *
 * @param keyPath The key path.
 */
-(unsigned char)unsignedCharForKeyPath:(NSString*)keyPath;

/**
 * Sets an unsigned character value for a specified key path.
 *
 * @param value The value to set.
 * @param keyPath The key path.
 */
-(void)setUnsignedChar:(unsigned char)value forKeyPath:(NSString*)keyPath;

/**
 * Retrieves an `unsigned short` value for a specified key path.
 *
 * @param keyPath The key path.
 */
-(unsigned short)unsignedShortForKeyPath:(NSString*)keyPath;

/**
 * Sets an `unsigned short` value for a specified key path.
 *
 * @param value The value to set.
 * @param keyPath The key path.
 */
-(void)setUnsignedShort:(unsigned short)value forKeyPath:(NSString*)keyPath;

/**
 * Retrieves an `unsigned int` value for a specified key path.
 *
 * @param keyPath The key path.
 */
-(unsigned unsigned int)unsignedIntForKeyPath:(NSString*)keyPath;

/**
 * Sets an `unsigned int` value for a specified key path.
 *
 * @param value The value to set.
 * @param keyPath The key path.
 */
-(void)setUnsignedInt:(unsigned int)value forKeyPath:(NSString*)keyPath;

/**
 * Retrieves an unsigned integer value for a specified key path.
 *
 * @param keyPath The key path.
 */
-(NSUInteger)unsignedIntegerForKeyPath:(NSString*)keyPath;

/**
 * Sets an unsigned integer value for a specified key path.
 *
 * @param value The value to set.
 * @param keyPath The key path.
 */
-(void)setUnsignedInteger:(NSUInteger)value forKeyPath:(NSString*)keyPath;

/**
 * Retrieves an `unsigned long` value for a specified key path.
 *
 * @param keyPath The key path.
 */
-(unsigned long)unsignedLongForKeyPath:(NSString*)keyPath;

/**
 * Sets an `unsigned long` value for a specified key path.
 *
 * @param value The value to set.
 * @param keyPath The key path.
 */
-(void)setUnsignedLong:(unsigned long)value forKeyPath:(NSString*)keyPath;

/**
 * Retrieves an `unsigned long long` value for a specified key path.
 *
 * @param keyPath The key path.
 */
-(unsigned long long)unsignedLongLongForKeyPath:(NSString*)keyPath;

/**
 * Sets an `unsigned long long` value for a specified key path.
 *
 * @param value The value to set.
 * @param keyPath The key path.
 */
-(void)setUnsignedLongLong:(unsigned long long)value forKeyPath:(NSString*)keyPath;

#pragma mark -
#pragma mark NSValue valueForKeyPath:/setValue:forKeyPath:
/** @name NSValue Key Paths */

/**
 * Retrieves an `NSSize` value for a specified key path.
 *
 * @param keyPath The key path.
 */
-(NSSize)sizeForKeyPath:(NSString*)keyPath;

/**
 * Sets an `NSSize` value for a specified key path.
 *
 * @param value The value to set.
 * @param keyPath The key path.
 */
-(void)setSize:(NSSize)value forKeyPath:(NSString*)keyPath;

/**
 * Retrieves an `NSRange` value for a specified key path.
 *
 * @param keyPath The key path.
 */
-(NSRange)rangeForKeyPath:(NSString*)keyPath;

/**
 * Sets an `NSRange` value for a specified key path.
 *
 * @param value The value to set.
 * @param keyPath The key path.
 */
-(void)setRange:(NSRange)value forKeyPath:(NSString*)keyPath;

/**
 * Retrieves an `NSRect` value for a specified key path.
 *
 * @param keyPath The key path.
 */
-(NSRect)rectForKeyPath:(NSString*)keyPath;

/**
 * Sets an `NSRect` value for a specified key path.
 *
 * @param value The value to set.
 * @param keyPath The key path.
 */
-(void)setRect:(NSRect)value forKeyPath:(NSString*)keyPath;

/**
 * Retrieves an `NSPoint` value for a specified key path.
 *
 * @param keyPath The key path.
 */
-(NSPoint)pointForKeyPath:(NSString*)keyPath;

/**
 * Sets an `NSPoint` value for a specified key path.
 *
 * @param value The value to set.
 * @param keyPath The key path.
 */
-(void)setPoint:(NSPoint)value forKeyPath:(NSString*)keyPath;

/**
 * Retrieves an `CATransform3D` value for a specified key path.
 *
 * @param keyPath The key path.
 */
-(CATransform3D)CATransform3DForKeyPath:(NSString*)keyPath;

/**
 * Sets an `CATransform3D` value for a specified key path.
 *
 * @param value The value to set.
 * @param keyPath The key path.
 */
-(void)setCATransform3D:(CATransform3D)value forKeyPath:(NSString*)keyPath;

@end

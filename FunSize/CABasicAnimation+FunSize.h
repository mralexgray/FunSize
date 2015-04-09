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

@import QuartzCore;

@interface CABasicAnimation (FunSize)

#pragma mark - NSNumber Getters
/** @name Number Getters */

/**	Returns the animation's `-fromValue` as an `int` value.	*/
-(int)fromInt;

/**	Returns the animation's `-toValue` as an `int` value.	*/
-(int)toInt;

/**	Returns the animation's `-fromValue` as a `float` value.	*/
-(float)fromFloat;

/**	Returns the animation's `-toValue` as a `float` value.	*/
-(float)toFloat;

/**	Returns the animation's `-fromValue` as a `double` value.	*/
-(double)fromDouble;

/**	Returns the animation's `-toValue` as a `double` value.	*/
-(double)toDouble;

#pragma mark - NSNumber Setters
/** @name Number Setters */

/**	Sets the animation's `-fromValue` to an `int` value.
 *
 * @param from The new from value.	*/
-(void)setFromInt:(int)from;

/**	Sets the animation's `-toValue` to an `int` value.
 *
 * @param to The new to value.	*/
-(void)setToInt:(int)to;

/**	Sets the animation's `-fromValue` to a `float` value.
 *
 * @param from The new from value.	*/
-(void)setFromFloat:(float)from;

/**	Sets the animation's `-toValue` to a `float` value.
 *
 * @param to The new to value.	*/
-(void)setToFloat:(float)to;

/**	Sets the animation's `-fromValue` to a `double` value.
 *
 * @param from The new from value.	*/
-(void)setFromDouble:(double)from;

/**	Sets the animation's `-toValue` to a `double` value.
 *
 * @param to The new to value.	*/
-(void)setToDouble:(double)to;

#pragma mark - NSValue Getters
/** @name Structure Getters */

/**	Returns the animation's `-fromValue` as an `NSPoint` value.	*/
-(CGPoint)fromPoint;

/**	Returns the animation's `-toValue` as an `NSPoint` value.	*/
-(CGPoint)toPoint;

/**	Returns the animation's `-fromValue` as a `CGPoint` value.	*/
-(CGPoint)fromCGPoint;

/**	Returns the animation's `-toValue` as a `CGPoint` value.	*/
-(CGPoint)toCGPoint;

/**	Returns the animation's `-fromValue` as an `NSRect` value.	*/
-(CGRect)fromRect;

/**	Returns the animation's `-toValue` as an `NSRect` value.	*/
-(CGRect)toRect;

/**	Returns the animation's `-fromValue` as a `CGRect` value.	*/
-(CGRect)fromCGRect;

/**	Returns the animation's `-toValue` as a `CGRect` value.	*/
-(CGRect)toCGRect;

/**	Returns the animation's `-fromValue` as an `CATransform3D` value.	*/
-(CATransform3D)fromTransform;

/**	Returns the animation's `-toValue` as a `CATransform3D` value.	*/
-(CATransform3D)toTransform;

#pragma mark - NSValue Setters
/** @name Structure Setters */

/**	Sets the animation's `-fromValue` to an `NSPoint` value.
 *
 * @param from The new from value.	*/
-(void)setFromPoint:(CGPoint)from;

/**	Sets the animation's `-toValue` to an `NSPoint` value.
 *
 * @param to The new to value.	*/
-(void)setToPoint:(CGPoint)to;

/**	Sets the animation's `-fromValue` to a `CGPoint` value.
 *
 * @param from The new from value.	*/
-(void)setFromCGPoint:(CGPoint)from;

/**	Sets the animation's `-toValue` to a `CGPoint` value.
 *
 * @param to The new to value.	*/
-(void)setToCGPoint:(CGPoint)to;

/**	Sets the animation's `-fromValue` to an `NSRect` value.
 *
 * @param from The new from value.	*/
-(void)setFromRect:(CGRect)from;

/**	Sets the animation's `-toValue` to an `NSRect` value.
 *
 * @param to The new to value.	*/
-(void)setToRect:(CGRect)to;

/**	Sets the animation's `-fromValue` to a `CGRect` value.
 *
 * @param from The new from value.	*/
-(void)setFromCGRect:(CGRect)from;

/**	Sets the animation's `-toValue` to a `CGRect` value.
 *
 * @param to The new to value.	*/
-(void)setToCGRect:(CGRect)to;

/**	Sets the animation's `-fromValue` to an `CATransform3D` value.
 *
 * @param from The new from value.	*/
-(void)setFromTransform:(CATransform3D)from;

/**	Sets the animation's `-toValue` to a `CATransform3D` value.
 *
 * @param to The new to value.	*/
-(void)setToTransform:(CATransform3D)to;

#pragma mark - Easing
/** @name Easing */

/**	Sets the animation's timing function to the specified name.
 *
 * @param timingFunctionName The name of the timing function to use.	*/
-(void)setTiming:(NSString*)timingFunctionName;

@end

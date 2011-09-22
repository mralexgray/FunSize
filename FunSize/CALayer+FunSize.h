/* Copyright (c) 2011, Nate Stedman <natesm@gmail.com>
 * 
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH RARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#import <Cocoa/Cocoa.h>

@interface CALayer (FunSize)

#pragma mark -
#pragma mark Recursive Sublayer Operations
/** @name Recursive Sublayer Operations */

/**
 * Recursively executes a block on this layer and its sublayers (and their sublayers, etc.).
 *
 * @param block The block, which will receive each sublayer as a parameter.
 */
-(void)sublayersBlock:(void (^)(CALayer* layer))block;

/**
 * Recursively executes a block on this layer and its sublayers (and their sublayers, etc.). The block can abort the 
 * recursion and iteration by returning `NO`.
 *
 * @param block The block, which will receive each sublayer as a parameter.
 */
-(BOOL)sublayersBlockWithAbort:(BOOL (^)(CALayer* layer))block;

/**
 * Recursively executes a block on this layer's sublayers (and their sublayers, etc.).
 *
 * @param block The block, which will receive each sublayer as a parameter.
 */
-(void)sublayersBlockSkippingSelf:(void (^)(CALayer* layer))block;

/**
 * Recursively executes a block on this layer's sublayers (and their sublayers, etc.). The block can abort the 
 * recursion and iteration by returning `NO`.
 *
 * @param block The block, which will receive each sublayer as a parameter.
 */
-(BOOL)sublayersBlockWithAbortSkippingSelf:(BOOL (^)(CALayer* layer))block;

#pragma mark -
#pragma mark Superlayer Actions
/** @name Superlayer Actions */

/**
 * Executes a block on this layer and its superlayers.
 *
 * @param block The block, which will receive each layer as a parameter.
 */
-(void)superlayerBlock:(void (^)(CALayer* layer))block;

/**
 * Executes a block on this layer and its superlayers. The block can stop the upward recursion by returning `NO`.
 *
 * @param block The block, which will receive each layer as a parameter.
 */
-(BOOL)superlayerBlockWithAbort:(BOOL (^)(CALayer* layer))block;

/**
 * Executes a block on this layer's superlayers.
 *
 * @param block The block, which will receive each layer as a parameter.
 */
-(void)superlayerBlockSkippingSelf:(void (^)(CALayer* layer))block;

/**
 * Executes a block on this layer's superlayers. The block can stop the upward recursion by returning `NO`.
 *
 * @param block The block, which will receive each layer as a parameter.
 */
-(BOOL)superlayerBlockWithAbortSkippingSelf:(BOOL (^)(CALayer* layer))block;

/**
 * Finds a superlayer of the layer with the specified class. If the layer is of the specified class, it will be
 * returned.
 *
 * @returns The superlayer, or `nil` if no superlayer with that class exists.
 *
 * @param klass The class to find.
 */
-(CALayer*)superlayerOfClass:(Class)klass;

/**
 * Returns an array of the layer's superlayers, with the immediate superlayer as the first element.
 */
-(NSArray*)superlayers;

#pragma mark -
#pragma mark Animations
/** @name Animations */

/**
 * Adds an animation and returns the copied version of it.
 *
 * `-addAnimation:forKey:` copies the animation when it is added. This message returns that copy so that it can be
 * easily used in later code.
 *
 * @param animation The animation to add.
 * @param key The key to animate.
 */
-(CAAnimation*)addAndReturnAnimation:(CAAnimation*)animation forKey:(NSString*)key;

/**
 * Animates a key of the layer.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param fromValue The starting value.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 */
-(void)animate:(NSString*)key from:(id)fromValue to:(id)toValue time:(NSTimeInterval)seconds;

/**
 * Animates a key of the layer with custom easing.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param fromValue The starting value.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 * @param easing The easing function to use. This can be an instance of `CAMediaTimingFunction` or one of the constants
 * that can be used to construct an instance of that class.
 */
-(void)animate:(NSString*)key from:(id)fromValue to:(id)toValue time:(NSTimeInterval)seconds eased:(id)easing;

/**
 * Animates a key of the layer. The current value is used as the starting value.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 */
-(void)animate:(NSString*)key to:(id)toValue time:(NSTimeInterval)seconds;

/**
 * Animates a key of the layer with custom easing. The current value is used as the starting value.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 * @param easing The easing function to use. This can be an instance of `CAMediaTimingFunction` or one of the constants
 * that can be used to construct an instance of that class.
 */
-(void)animate:(NSString*)key to:(id)toValue time:(NSTimeInterval)seconds eased:(id)easing;

/**
 * Animates a key of the layer.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param fromValue The starting value.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 * @param block A block to execute upon completion of the animation. The block will recieve the animation as a
 * parameter.
 */
-(void)animate:(NSString*)key
          from:(id)fromValue
            to:(id)toValue
          time:(NSTimeInterval)seconds
    completion:(void (^)())block;

/**
 * Animates a key of the layer with custom easing.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param fromValue The starting value.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 * @param easing The easing function to use. This can be an instance of `CAMediaTimingFunction` or one of the constants
 * that can be used to construct an instance of that class.
 * @param block A block to execute upon completion of the animation. The block will recieve the animation as a
 * parameter.
 */
-(void)animate:(NSString*)key
          from:(id)fromValue
            to:(id)toValue
          time:(NSTimeInterval)seconds
         eased:(id)easing
    completion:(void (^)())block;

/**
 * Animates a key of the layer. The current value is used as the starting value.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 * @param block A block to execute upon completion of the animation. The block will recieve the animation as a
 * parameter.
 */
-(void)animate:(NSString*)key
            to:(id)toValue
          time:(NSTimeInterval)seconds
    completion:(void (^)())block;

/**
 * Animates a key of the layer with custom easing. The current value is used as the starting value.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 * @param easing The easing function to use. This can be an instance of `CAMediaTimingFunction` or one of the constants
 * that can be used to construct an instance of that class.
 * @param block A block to execute upon completion of the animation. The block will recieve the animation as a
 * parameter.
 */
-(void)animate:(NSString*)key
            to:(id)toValue
          time:(NSTimeInterval)seconds
         eased:(id)easing
    completion:(void (^)())block;

#pragma mark -
#pragma mark Numbers
/** @name Animation with Numbers */

/**
 * Animates a key of the layer from one integer value to another.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param fromValue The starting value.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 */
-(void)animate:(NSString*)key fromInt:(int)fromValue to:(int)toValue time:(NSTimeInterval)seconds;

/**
 * Animates a key of the layer from one integer value to another with custom easing.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param fromValue The starting value.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 * @param easing The easing function to use. This can be an instance of `CAMediaTimingFunction` or one of the constants
 * that can be used to construct an instance of that class.
 */
-(void)animate:(NSString*)key
       fromInt:(int)fromValue
            to:(int)toValue
          time:(NSTimeInterval)seconds
         eased:(id)easing;

/**
 * Animates a key of the layer to an integer value.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 */
-(void)animate:(NSString*)key toInt:(int)toValue time:(NSTimeInterval)seconds;

/**
 * Animates a key of the layer to an integer value with custom easing.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 * @param easing The easing function to use. This can be an instance of `CAMediaTimingFunction` or one of the constants
 * that can be used to construct an instance of that class.
 */
-(void)animate:(NSString*)key toInt:(int)toValue time:(NSTimeInterval)seconds eased:(id)easing;

/**
 * Animates a key of the layer from one `float` value to another.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param fromValue The starting value.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 */
-(void)animate:(NSString*)key fromFloat:(float)fromValue to:(float)toValue time:(NSTimeInterval)seconds;

/**
 * Animates a key of the layer from one `float` value to another with custom easing.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param fromValue The starting value.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 * @param easing The easing function to use. This can be an instance of `CAMediaTimingFunction` or one of the constants
 * that can be used to construct an instance of that class.
 */
-(void)animate:(NSString*)key
     fromFloat:(float)fromValue
            to:(float)toValue
          time:(NSTimeInterval)seconds
         eased:(id)easing;

/**
 * Animates a key of the layer to a `float` value.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 */
-(void)animate:(NSString*)key toFloat:(float)toValue time:(NSTimeInterval)seconds;

/**
 * Animates a key of the layer to a `float` value with custom easing.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 * @param easing The easing function to use. This can be an instance of `CAMediaTimingFunction` or one of the constants
 * that can be used to construct an instance of that class.
 */
-(void)animate:(NSString*)key toFloat:(float)toValue time:(NSTimeInterval)seconds eased:(id)easing;

/**
 * Animates a key of the layer from one `double` value to another.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param fromValue The starting value.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 */
-(void)animate:(NSString*)key fromDouble:(double)fromValue to:(double)toValue time:(NSTimeInterval)seconds;

/**
 * Animates a key of the layer from one `double` value to another with custom easing.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param fromValue The starting value.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 * @param easing The easing function to use. This can be an instance of `CAMediaTimingFunction` or one of the constants
 * that can be used to construct an instance of that class.
 */
-(void)animate:(NSString*)key
    fromDouble:(double)fromValue
            to:(double)toValue
          time:(NSTimeInterval)seconds
         eased:(id)easing;

/**
 * Animates a key of the layer to a `double` value.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 */
-(void)animate:(NSString*)key toDouble:(double)toValue time:(NSTimeInterval)seconds;

/**
 * Animates a key of the layer to a `double` value with custom easing.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 * @param easing The easing function to use. This can be an instance of `CAMediaTimingFunction` or one of the constants
 * that can be used to construct an instance of that class.
 */
-(void)animate:(NSString*)key toDouble:(double)toValue time:(NSTimeInterval)seconds eased:(id)easing;

/**
 * Animates a key of the layer from one integer value to another.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param fromValue The starting value.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 * @param block A block to execute upon completion of the animation. The block will recieve the animation as a
 * parameter.
 */
-(void)animate:(NSString*)key
       fromInt:(int)fromValue
            to:(int)toValue
          time:(NSTimeInterval)seconds
    completion:(void (^)())block;

/**
 * Animates a key of the layer from one integer value to another with custom easing.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param fromValue The starting value.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 * @param easing The easing function to use. This can be an instance of `CAMediaTimingFunction` or one of the constants
 * that can be used to construct an instance of that class.
 * @param block A block to execute upon completion of the animation. The block will recieve the animation as a
 * parameter.
 */
-(void)animate:(NSString*)key
       fromInt:(int)fromValue
            to:(int)toValue
          time:(NSTimeInterval)seconds
         eased:(id)easing
    completion:(void (^)())block;

/**
 * Animates a key of the layer to an integer value.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 * @param block A block to execute upon completion of the animation. The block will recieve the animation as a
 * parameter.
 */
-(void)animate:(NSString*)key
         toInt:(int)toValue
          time:(NSTimeInterval)seconds
    completion:(void (^)())block;

/**
 * Animates a key of the layer to an integer value with custom easing.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 * @param easing The easing function to use. This can be an instance of `CAMediaTimingFunction` or one of the constants
 * that can be used to construct an instance of that class.
 * @param block A block to execute upon completion of the animation. The block will recieve the animation as a
 * parameter.
 */
-(void)animate:(NSString*)key
         toInt:(int)toValue
          time:(NSTimeInterval)seconds
         eased:(id)easing
    completion:(void (^)())block;

/**
 * Animates a key of the layer from one `float` value to another.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param fromValue The starting value.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 * @param block A block to execute upon completion of the animation. The block will recieve the animation as a
 * parameter.
 */
-(void)animate:(NSString*)key
     fromFloat:(float)fromValue
            to:(float)toValue
          time:(NSTimeInterval)seconds
    completion:(void (^)())block;

/**
 * Animates a key of the layer from one `float` value to another with custom easing.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param fromValue The starting value.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 * @param easing The easing function to use. This can be an instance of `CAMediaTimingFunction` or one of the constants
 * that can be used to construct an instance of that class.
 * @param block A block to execute upon completion of the animation. The block will recieve the animation as a
 * parameter.
 */
-(void)animate:(NSString*)key
     fromFloat:(float)fromValue
            to:(float)toValue
          time:(NSTimeInterval)seconds
         eased:(id)easing
    completion:(void (^)())block;

/**
 * Animates a key of the layer to a `float` value.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 * @param block A block to execute upon completion of the animation. The block will recieve the animation as a
 * parameter.
 */
-(void)animate:(NSString*)key
       toFloat:(float)toValue
          time:(NSTimeInterval)seconds
    completion:(void (^)())block;

/**
 * Animates a key of the layer to a `float` value with custom easing.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 * @param easing The easing function to use. This can be an instance of `CAMediaTimingFunction` or one of the constants
 * that can be used to construct an instance of that class.
 * @param block A block to execute upon completion of the animation. The block will recieve the animation as a
 * parameter.
 */
-(void)animate:(NSString*)key
       toFloat:(float)toValue
          time:(NSTimeInterval)seconds
         eased:(id)easing
    completion:(void (^)())block;

/**
 * Animates a key of the layer from one `double` value to another.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param fromValue The starting value.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 * @param block A block to execute upon completion of the animation. The block will recieve the animation as a
 * parameter.
 */
-(void)animate:(NSString*)key
    fromDouble:(double)fromValue
            to:(double)toValue
          time:(NSTimeInterval)seconds
    completion:(void (^)())block;

/**
 * Animates a key of the layer from one `double` value to another with custom easing.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param fromValue The starting value.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 * @param easing The easing function to use. This can be an instance of `CAMediaTimingFunction` or one of the constants
 * that can be used to construct an instance of that class.
 * @param block A block to execute upon completion of the animation. The block will recieve the animation as a
 * parameter.
 */
-(void)animate:(NSString*)key
    fromDouble:(double)fromValue
            to:(double)toValue
          time:(NSTimeInterval)seconds
         eased:(id)easing
    completion:(void (^)())block;

/**
 * Animates a key of the layer to a `double` value.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 * @param block A block to execute upon completion of the animation. The block will recieve the animation as a
 * parameter.
 */
-(void)animate:(NSString*)key
      toDouble:(double)toValue
          time:(NSTimeInterval)seconds
    completion:(void (^)())block;

/**
 * Animates a key of the layer to a `double` value with custom easing.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 * @param easing The easing function to use. This can be an instance of `CAMediaTimingFunction` or one of the constants
 * that can be used to construct an instance of that class.
 * @param block A block to execute upon completion of the animation. The block will recieve the animation as a
 * parameter.
 */
-(void)animate:(NSString*)key
      toDouble:(double)toValue
          time:(NSTimeInterval)seconds
         eased:(id)easing
    completion:(void (^)())block;


#pragma mark -
#pragma mark Rects
/** @name Animation with Rects */

/**
 * Animates a key of the layer from one `NSRect` value to another.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param fromValue The starting value.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 */
-(void)animate:(NSString*)key fromRect:(NSRect)fromValue to:(NSRect)toValue time:(NSTimeInterval)seconds;

/**
 * Animates a key of the layer from one `NSRect` value to another with custom easing.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param fromValue The starting value.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 * @param easing The easing function to use. This can be an instance of `CAMediaTimingFunction` or one of the constants
 * that can be used to construct an instance of that class.
 */
-(void)animate:(NSString*)key
      fromRect:(NSRect)fromValue
            to:(NSRect)toValue
          time:(NSTimeInterval)seconds
         eased:(id)easing;

/**
 * Animates a key of the layer to an `NSRect` value.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 */
-(void)animate:(NSString*)key toRect:(NSRect)toValue time:(NSTimeInterval)seconds;

/**
 * Animates a key of the layer to an `NSRect` value with custom easing.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 * @param easing The easing function to use. This can be an instance of `CAMediaTimingFunction` or one of the constants
 * that can be used to construct an instance of that class.
 */
-(void)animate:(NSString*)key toRect:(NSRect)toValue time:(NSTimeInterval)seconds eased:(id)easing;

/**
 * Animates a key of the layer from one `CGRect` value to another.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param fromValue The starting value.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 */
-(void)animate:(NSString*)key fromCGRect:(CGRect)fromValue to:(CGRect)toValue time:(NSTimeInterval)seconds;

/**
 * Animates a key of the layer from one `CGRect` value to another with custom easing.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param fromValue The starting value.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 * @param easing The easing function to use. This can be an instance of `CAMediaTimingFunction` or one of the constants
 * that can be used to construct an instance of that class.
 */
-(void)animate:(NSString*)key
    fromCGRect:(CGRect)fromValue
            to:(CGRect)toValue
          time:(NSTimeInterval)seconds
         eased:(id)easing;

/**
 * Animates a key of the layer to a `CGRect` value.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 */
-(void)animate:(NSString*)key toCGRect:(CGRect)toValue time:(NSTimeInterval)seconds;

/**
 * Animates a key of the layer to a `CGRect` value with custom easing.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 * @param easing The easing function to use. This can be an instance of `CAMediaTimingFunction` or one of the constants
 * that can be used to construct an instance of that class.
 */
-(void)animate:(NSString*)key
      toCGRect:(CGRect)toValue
          time:(NSTimeInterval)seconds
         eased:(id)easing;

/**
 * Animates a key of the layer from one `NSRect` value to another.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param fromValue The starting value.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 * @param block A block to execute upon completion of the animation. The block will recieve the animation as a
 * parameter.
 */
-(void)animate:(NSString*)key
      fromRect:(NSRect)fromValue
            to:(NSRect)toValue
          time:(NSTimeInterval)seconds
    completion:(void (^)())block;

/**
 * Animates a key of the layer from one `NSRect` value to another with custom easing.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param fromValue The starting value.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 * @param easing The easing function to use. This can be an instance of `CAMediaTimingFunction` or one of the constants
 * that can be used to construct an instance of that class.
 * @param block A block to execute upon completion of the animation. The block will recieve the animation as a
 * parameter.
 */
-(void)animate:(NSString*)key
      fromRect:(NSRect)fromValue
            to:(NSRect)toValue
          time:(NSTimeInterval)seconds
         eased:(id)easing
    completion:(void (^)())block;

/**
 * Animates a key of the layer to an `NSRect` value.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 * @param block A block to execute upon completion of the animation. The block will recieve the animation as a
 * parameter.
 */
-(void)animate:(NSString*)key
        toRect:(NSRect)toValue
          time:(NSTimeInterval)seconds
    completion:(void (^)())block;

/**
 * Animates a key of the layer to an `NSRect` value with custom easing.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 * @param easing The easing function to use. This can be an instance of `CAMediaTimingFunction` or one of the constants
 * that can be used to construct an instance of that class.
 * @param block A block to execute upon completion of the animation. The block will recieve the animation as a
 * parameter.
 */
-(void)animate:(NSString*)key
        toRect:(NSRect)toValue
          time:(NSTimeInterval)seconds
         eased:(id)easing
    completion:(void (^)())block;

/**
 * Animates a key of the layer from one `CGRect` value to another.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param fromValue The starting value.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 * @param block A block to execute upon completion of the animation. The block will recieve the animation as a
 * parameter.
 */
-(void)animate:(NSString*)key
    fromCGRect:(CGRect)fromValue
            to:(CGRect)toValue
          time:(NSTimeInterval)seconds
    completion:(void (^)())block;

/**
 * Animates a key of the layer from one `CGRect` value to another with custom easing.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param fromValue The starting value.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 * @param easing The easing function to use. This can be an instance of `CAMediaTimingFunction` or one of the constants
 * that can be used to construct an instance of that class.
 * @param block A block to execute upon completion of the animation. The block will recieve the animation as a
 * parameter.
 */
-(void)animate:(NSString*)key
    fromCGRect:(CGRect)fromValue
            to:(CGRect)toValue
          time:(NSTimeInterval)seconds
         eased:(id)easing
    completion:(void (^)())block;

/**
 * Animates a key of the layer to a `CGRect` value.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 * @param block A block to execute upon completion of the animation. The block will recieve the animation as a
 * parameter.
 */
-(void)animate:(NSString*)key
      toCGRect:(CGRect)toValue
          time:(NSTimeInterval)seconds
    completion:(void (^)())block;

/**
 * Animates a key of the layer to a `CGRect` value with custom easing.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 * @param easing The easing function to use. This can be an instance of `CAMediaTimingFunction` or one of the constants
 * that can be used to construct an instance of that class.
 * @param block A block to execute upon completion of the animation. The block will recieve the animation as a
 * parameter.
 */
-(void)animate:(NSString*)key
      toCGRect:(CGRect)toValue
          time:(NSTimeInterval)seconds
         eased:(id)easing
    completion:(void (^)())block;

#pragma mark -
#pragma mark Points
/** @name Animation with Points */

/**
 * Animates a key of the layer from one `NSPoint` value to another.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param fromValue The starting value.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 */
-(void)animate:(NSString*)key fromPoint:(NSPoint)fromValue to:(NSPoint)toValue time:(NSTimeInterval)seconds;

/**
 * Animates a key of the layer from one `NSPoint` value to another with custom easing.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param fromValue The starting value.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 * @param easing The easing function to use. This can be an instance of `CAMediaTimingFunction` or one of the constants
 * that can be used to construct an instance of that class.
 */
-(void)animate:(NSString*)key
     fromPoint:(NSPoint)fromValue
            to:(NSPoint)toValue
          time:(NSTimeInterval)seconds
         eased:(id)easing;

/**
 * Animates a key of the layer to an `NSPoint` value.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 */
-(void)animate:(NSString*)key toPoint:(NSPoint)toValue time:(NSTimeInterval)seconds;

/**
 * Animates a key of the layer to an `NSPoint` value with custom easing.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 * @param easing The easing function to use. This can be an instance of `CAMediaTimingFunction` or one of the constants
 * that can be used to construct an instance of that class.
 */
-(void)animate:(NSString*)key toPoint:(NSPoint)toValue time:(NSTimeInterval)seconds eased:(id)easing;

/**
 * Animates a key of the layer from one `CGPoint` value to another.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param fromValue The starting value.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 */
-(void)animate:(NSString*)key fromCGPoint:(CGPoint)fromValue to:(CGPoint)toValue time:(NSTimeInterval)seconds;

/**
 * Animates a key of the layer from one `CGPoint` value to another with custom easing.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param fromValue The starting value.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 * @param easing The easing function to use. This can be an instance of `CAMediaTimingFunction` or one of the constants
 * that can be used to construct an instance of that class.
 */
-(void)animate:(NSString*)key
   fromCGPoint:(CGPoint)fromValue
            to:(CGPoint)toValue
          time:(NSTimeInterval)seconds
         eased:(id)easing;

/**
 * Animates a key of the layer to a `CGPoint` value.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 */
-(void)animate:(NSString*)key toCGPoint:(CGPoint)toValue time:(NSTimeInterval)seconds;

/**
 * Animates a key of the layer to a `CGPoint` value with custom easing.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 * @param easing The easing function to use. This can be an instance of `CAMediaTimingFunction` or one of the constants
 * that can be used to construct an instance of that class.
 */
-(void)animate:(NSString*)key toCGPoint:(CGPoint)toValue time:(NSTimeInterval)seconds eased:(id)easing;

/**
 * Animates a key of the layer from one `NSPoint` value to another.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param fromValue The starting value.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 * @param block A block to execute upon completion of the animation. The block will recieve the animation as a
 * parameter.
 */
-(void)animate:(NSString*)key
     fromPoint:(NSPoint)fromValue
            to:(NSPoint)toValue
          time:(NSTimeInterval)seconds
    completion:(void (^)())block;

/**
 * Animates a key of the layer from one `NSPoint` value to another with custom easing.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param fromValue The starting value.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 * @param easing The easing function to use. This can be an instance of `CAMediaTimingFunction` or one of the constants
 * that can be used to construct an instance of that class.
 * @param block A block to execute upon completion of the animation. The block will recieve the animation as a
 * parameter.
 */
-(void)animate:(NSString*)key
     fromPoint:(NSPoint)fromValue
            to:(NSPoint)toValue
          time:(NSTimeInterval)seconds
         eased:(id)easing
    completion:(void (^)())block;

/**
 * Animates a key of the layer to an `NSPoint` value.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 * @param block A block to execute upon completion of the animation. The block will recieve the animation as a
 * parameter.
 */
-(void)animate:(NSString*)key
       toPoint:(NSPoint)toValue
          time:(NSTimeInterval)seconds
    completion:(void (^)())block;

/**
 * Animates a key of the layer to an `NSPoint` value with custom easing.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 * @param easing The easing function to use. This can be an instance of `CAMediaTimingFunction` or one of the constants
 * that can be used to construct an instance of that class.
 * @param block A block to execute upon completion of the animation. The block will recieve the animation as a
 * parameter.
 */
-(void)animate:(NSString*)key
       toPoint:(NSPoint)toValue
          time:(NSTimeInterval)seconds
         eased:(id)easing
    completion:(void (^)())block;

/**
 * Animates a key of the layer from one `CGPoint` value to another.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param fromValue The starting value.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 * @param block A block to execute upon completion of the animation. The block will recieve the animation as a
 * parameter.
 */
-(void)animate:(NSString*)key
   fromCGPoint:(CGPoint)fromValue
            to:(CGPoint)toValue
          time:(NSTimeInterval)seconds
    completion:(void (^)())block;

/**
 * Animates a key of the layer from one `CGPoint` value to another with custom easing.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param fromValue The starting value.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 * @param easing The easing function to use. This can be an instance of `CAMediaTimingFunction` or one of the constants
 * that can be used to construct an instance of that class.
 * @param block A block to execute upon completion of the animation. The block will recieve the animation as a
 * parameter.
 */
-(void)animate:(NSString*)key
   fromCGPoint:(CGPoint)fromValue
            to:(CGPoint)toValue
          time:(NSTimeInterval)seconds
         eased:(id)easing
    completion:(void (^)())block;

/**
 * Animates a key of the layer to a `CGPoint` value.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 * @param block A block to execute upon completion of the animation. The block will recieve the animation as a
 * parameter.
 */
-(void)animate:(NSString*)key
     toCGPoint:(CGPoint)toValue
          time:(NSTimeInterval)seconds
    completion:(void (^)())block;

/**
 * Animates a key of the layer to a `CGPoint` value with custom easing.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 * @param easing The easing function to use. This can be an instance of `CAMediaTimingFunction` or one of the constants
 * that can be used to construct an instance of that class.
 * @param block A block to execute upon completion of the animation. The block will recieve the animation as a
 * parameter.
 */
-(void)animate:(NSString*)key
     toCGPoint:(CGPoint)toValue
          time:(NSTimeInterval)seconds
         eased:(id)easing
    completion:(void (^)())block;

#pragma mark -
#pragma mark Sizes
/** @name Animation with Sizes */

/**
 * Animates a key of the layer from one `NSSize` value to another.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param fromValue The starting value.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 */
-(void)animate:(NSString*)key fromSize:(NSSize)fromValue to:(NSSize)toValue time:(NSTimeInterval)seconds;

/**
 * Animates a key of the layer from one `NSSize` value to another with custom easing.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param fromValue The starting value.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 * @param easing The easing function to use. This can be an instance of `CAMediaTimingFunction` or one of the constants
 * that can be used to construct an instance of that class.
 */
-(void)animate:(NSString*)key
      fromSize:(NSSize)fromValue
            to:(NSSize)toValue
          time:(NSTimeInterval)seconds
         eased:(id)easing;

/**
 * Animates a key of the layer to an `NSSize` value.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 */
-(void)animate:(NSString*)key toSize:(NSSize)toValue time:(NSTimeInterval)seconds;

/**
 * Animates a key of the layer to an `NSSize` value with custom easing.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 * @param easing The easing function to use. This can be an instance of `CAMediaTimingFunction` or one of the constants
 * that can be used to construct an instance of that class.
 */
-(void)animate:(NSString*)key toSize:(NSSize)toValue time:(NSTimeInterval)seconds eased:(id)easing;

/**
 * Animates a key of the layer from one `CGSize` value to another.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param fromValue The starting value.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 */
-(void)animate:(NSString*)key fromCGSize:(CGSize)fromValue to:(CGSize)toValue time:(NSTimeInterval)seconds;

/**
 * Animates a key of the layer from one `CGSize` value to another with custom easing.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param fromValue The starting value.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 * @param easing The easing function to use. This can be an instance of `CAMediaTimingFunction` or one of the constants
 * that can be used to construct an instance of that class.
 */
-(void)animate:(NSString*)key
    fromCGSize:(CGSize)fromValue
            to:(CGSize)toValue
          time:(NSTimeInterval)seconds
         eased:(id)easing;

/**
 * Animates a key of the layer to a `CGSize` value.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 */
-(void)animate:(NSString*)key toCGSize:(CGSize)toValue time:(NSTimeInterval)seconds;

/**
 * Animates a key of the layer to a `CGSize` value with custom easing.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 * @param easing The easing function to use. This can be an instance of `CAMediaTimingFunction` or one of the constants
 * that can be used to construct an instance of that class.
 */
-(void)animate:(NSString*)key toCGSize:(CGSize)toValue time:(NSTimeInterval)seconds eased:(id)easing;

/**
 * Animates a key of the layer from one `NSSize` value to another.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param fromValue The starting value.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 * @param block A block to execute upon completion of the animation. The block will recieve the animation as a
 * parameter.
 */
-(void)animate:(NSString*)key
      fromSize:(NSSize)fromValue
            to:(NSSize)toValue
          time:(NSTimeInterval)seconds
    completion:(void (^)())block;

/**
 * Animates a key of the layer from one `NSSize` value to another with custom easing.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param fromValue The starting value.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 * @param easing The easing function to use. This can be an instance of `CAMediaTimingFunction` or one of the constants
 * that can be used to construct an instance of that class.
 * @param block A block to execute upon completion of the animation. The block will recieve the animation as a
 * parameter.
 */
-(void)animate:(NSString*)key
      fromSize:(NSSize)fromValue
            to:(NSSize)toValue
          time:(NSTimeInterval)seconds
         eased:(id)easing
    completion:(void (^)())block;

/**
 * Animates a key of the layer to an `NSSize` value.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 * @param block A block to execute upon completion of the animation. The block will recieve the animation as a
 * parameter.
 */
-(void)animate:(NSString*)key
        toSize:(NSSize)toValue
          time:(NSTimeInterval)seconds
    completion:(void (^)())block;

/**
 * Animates a key of the layer to an `NSSize` value with custom easing.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 * @param easing The easing function to use. This can be an instance of `CAMediaTimingFunction` or one of the constants
 * that can be used to construct an instance of that class.
 * @param block A block to execute upon completion of the animation. The block will recieve the animation as a
 * parameter.
 */
-(void)animate:(NSString*)key
        toSize:(NSSize)toValue
          time:(NSTimeInterval)seconds
         eased:(id)easing
    completion:(void (^)())block;

/**
 * Animates a key of the layer from one `CGSize` value to another.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param fromValue The starting value.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 * @param block A block to execute upon completion of the animation. The block will recieve the animation as a
 * parameter.
 */
-(void)animate:(NSString*)key
    fromCGSize:(CGSize)fromValue
            to:(CGSize)toValue
          time:(NSTimeInterval)seconds
    completion:(void (^)())block;

/**
 * Animates a key of the layer from one `CGSize` value to another with custom easing.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param fromValue The starting value.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 * @param easing The easing function to use. This can be an instance of `CAMediaTimingFunction` or one of the constants
 * that can be used to construct an instance of that class.
 * @param block A block to execute upon completion of the animation. The block will recieve the animation as a
 * parameter.
 */
-(void)animate:(NSString*)key
    fromCGSize:(CGSize)fromValue
            to:(CGSize)toValue
          time:(NSTimeInterval)seconds
         eased:(id)easing
    completion:(void (^)())block;

/**
 * Animates a key of the layer to a `CGSize` value.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 * @param block A block to execute upon completion of the animation. The block will recieve the animation as a
 * parameter.
 */
-(void)animate:(NSString*)key
      toCGSize:(CGSize)toValue
          time:(NSTimeInterval)seconds
    completion:(void (^)())block;

/**
 * Animates a key of the layer to a `CGSize` value with custom easing.
 *
 * `CABasicAnimation` is used for the animation.
 *
 * @param key The key to animate.
 * @param toValue The ending value.
 * @param seconds The number of seconds the animation should take.
 * @param easing The easing function to use. This can be an instance of `CAMediaTimingFunction` or one of the constants
 * that can be used to construct an instance of that class.
 * @param block A block to execute upon completion of the animation. The block will recieve the animation as a
 * parameter.
 */
-(void)animate:(NSString*)key
      toCGSize:(CGSize)toValue
          time:(NSTimeInterval)seconds
         eased:(id)easing
    completion:(void (^)())block;

#pragma mark -
#pragma mark Hit Testing
/** @name Hit Testing */

/**
 * Performs a hit test, then moves up the layer tree until it finds a layer of the specified class. If such a layer is
 * not found, returns `nil`.
 *
 * @param point The point to hit test.
 * @param klass The layer class to search for.
 */
-(CALayer*)hitTest:(CGPoint)point forClass:(Class)klass;

@end

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

#import <Quartz/Quartz.h>

#import "CALayer+FunSize.h"

typedef void (^FSBlockBasicAnimationHelperBlock)();

@interface FSBlockBasicAnimationHelper : NSObject
{
    FSBlockBasicAnimationHelperBlock block;
}

+(FSBlockBasicAnimationHelper*)helperWithBlock:(FSBlockBasicAnimationHelperBlock)blk;

@end

@implementation FSBlockBasicAnimationHelper

+(FSBlockBasicAnimationHelper*)helperWithBlock:(FSBlockBasicAnimationHelperBlock)blk
{
    FSBlockBasicAnimationHelper* helper = [[super alloc] init];
    helper->block = Block_copy(blk);
    
    return helper;
}

-(void)dealloc
{
    Block_release(block);
    [super dealloc];
}

-(void)finalize
{
    Block_release(block);
    [super finalize];
}

-(void)animationDidStop:(CAAnimation*)anim finished:(BOOL)flag
{
    if (flag)
    {
        block();
    }
    
    [self release];
}

@end

@implementation CALayer (FunSize)

#pragma mark Recursive Sublayer Actions
-(void)sublayersBlock:(void (^)(CALayer*))block
{
    // run the block on the root layer
    block(self);
    
    // recurse on the child layers
    for (CALayer* layer in [self sublayers])
        [layer sublayersBlock:block];
}

-(BOOL)sublayersBlockWithAbort:(BOOL (^)(CALayer*))block
{
    if (block(self)) return YES;
    
    for (CALayer* layer in [self sublayers])
        if ([layer sublayersBlockWithAbort:block])
            return YES;
    
    return NO;
}

-(void)sublayersBlockSkippingSelf:(void (^)(CALayer*))block
{
    for (CALayer* layer in [self sublayers])
    {
        block(layer);
        [layer sublayersBlockSkippingSelf:block];
    }
}

-(BOOL)sublayersBlockWithAbortSkippingSelf:(BOOL (^)(CALayer*))block
{
    for (CALayer* layer in [self sublayers])
    {
        block(layer);
        if ([layer sublayersBlockWithAbortSkippingSelf:block])
            return YES;
    }
    
    return NO;
}

#pragma mark Superlayer Actions
-(void)superlayerBlock:(void (^)(CALayer*))block
{
    for (CALayer* layer = self; layer != nil; layer = [layer superlayer])
    {
        block(layer);
    }
}

-(BOOL)superlayerBlockWithAbort:(BOOL (^)(CALayer*))block
{
    for (CALayer* layer = self; layer != nil; layer = [layer superlayer])
    {
        if (!block(layer)) return YES;
    }
    
    return NO;
}

-(void)superlayerBlockSkippingSelf:(void (^)(CALayer*))block
{
    for (CALayer* layer = [self superlayer]; layer != nil; layer = [layer superlayer])
    {
        block(layer);
    }
}

-(BOOL)superlayerBlockWithAbortSkippingSelf:(BOOL (^)(CALayer*))block
{
    for (CALayer* layer = [self superlayer]; layer != nil; layer = [layer superlayer])
    {
        if (!block(layer)) return YES;
    }
    
    return NO;
}

-(CALayer*)superlayerOfClass:(Class)klass
{
    for (CALayer* layer = self; layer != nil; layer = [layer superlayer])
        if ([layer isKindOfClass:klass])
            return layer;
    
    return nil;
}

-(NSArray*)superlayers
{
    if (![self superlayer])
        return @[self];//[NSArray array];
    
    NSMutableArray* array = [NSMutableArray array];
    
    [self superlayerBlockSkippingSelf:^(CALayer* layer) {
        [array addObject:layer];
    }];
    
    return array;
}

#pragma mark Hit Testing
-(CALayer*)hitTest:(CGPoint)point forClass:(Class)klass
{
    CALayer* layer = [self hitTest:point];
    
    while (layer != nil && ![layer isKindOfClass:klass])
    {
        layer = [layer superlayer];
    }
    
    return layer;
}

#pragma mark Animations
-(CAAnimation*)addAndReturnAnimation:(CAAnimation*)animation forKey:(NSString*)key
{
    [self addAnimation:animation forKey:key];
    return [self animationForKey:key];
}

-(void)animate:(NSString*)key from:(id)fromValue to:(id)toValue time:(NSTimeInterval)seconds
{
    [self animate:key from:fromValue to:toValue time:seconds eased:kCAMediaTimingFunctionDefault];
}

-(void)animate:(NSString*)key from:(id)fromValue to:(id)toValue time:(NSTimeInterval)seconds eased:(id)easing
{
    [self animate:key from:fromValue to:toValue time:seconds eased:easing completion:nil];
}

-(void)animate:(NSString*)key to:(id)toValue time:(NSTimeInterval)seconds
{
    [self animate:key from:[self valueForKey:key] to:toValue time:seconds];
}

-(void)animate:(NSString*)key to:(id)toValue time:(NSTimeInterval)seconds eased:(id)easing
{
    [self animate:key from:[self valueForKey:key] to:toValue time:seconds eased:easing];
}

-(void)animate:(NSString*)key
          from:(id)fromValue
            to:(id)toValue
          time:(NSTimeInterval)seconds
    completion:(void (^)())block
{
    [self animate:key
             from:fromValue
               to:toValue
             time:seconds
            eased:kCAMediaTimingFunctionDefault
       completion:block];
}

-(void)animate:(NSString*)key
          from:(id)fromValue
            to:(id)toValue
          time:(NSTimeInterval)seconds
         eased:(id)easing
    completion:(void (^)())block
{
    // negative time won't work
    if (seconds < 0.0)
    {
        NSLog(@"Tried to animate key %@ of layer %@ with negative time %f", key, self, seconds);
        return;
    }
    
    // premptively set the to value
    [CATransaction begin];
    [CATransaction setValue:(id)kCFBooleanTrue forKey:kCATransactionDisableActions];
    [self setValue:toValue forKeyPath:key];
    [CATransaction commit];
    
    // create the animation
    CABasicAnimation* animation = [CABasicAnimation animationWithKeyPath:key];
    
    // set the animation's values
    [animation setFromValue:fromValue];
    [animation setToValue:toValue];
    
    // set the animation's duration
    [animation setDuration:seconds];
    
    // set the easing function
    if ([easing isKindOfClass:[NSString class]])
        [animation setTimingFunction:[CAMediaTimingFunction functionWithName:easing]];
    else
        [animation setTimingFunction:easing];
    
    if (block)
    {
        // set the animation's delegate
        [animation setDelegate:[FSBlockBasicAnimationHelper helperWithBlock:block]];
    }
    
    // add the animation
    [self addAnimation:animation forKey:key]; 
}

-(void)animate:(NSString*)key
            to:(id)toValue
          time:(NSTimeInterval)seconds
    completion:(void (^)())block
{
    [self animate:key from:[[self presentationLayer] valueForKey:key] to:toValue time:seconds completion:block];
}

-(void)animate:(NSString*)key
            to:(id)toValue
          time:(NSTimeInterval)seconds
         eased:(id)easing
    completion:(void (^)())block
{
    [self animate:key
             from:[[self presentationLayer] valueForKey:key]
               to:toValue
             time:seconds
            eased:easing
       completion:block];
}

#pragma mark Numbers
-(void)animate:(NSString*)key fromInt:(int)fromValue to:(int)toValue time:(NSTimeInterval)seconds
{
    [self animate:key
             from:[NSNumber numberWithInt:fromValue]
               to:[NSNumber numberWithInt:toValue]
             time:seconds];
}

-(void)animate:(NSString*)key
       fromInt:(int)fromValue
            to:(int)toValue
          time:(NSTimeInterval)seconds
         eased:(id)easing
{
    [self animate:key
             from:[NSNumber numberWithInt:fromValue]
               to:[NSNumber numberWithInt:toValue]
             time:seconds
            eased:easing];
}

-(void)animate:(NSString*)key toInt:(int)toValue time:(NSTimeInterval)seconds
{
    [self animate:key to:[NSNumber numberWithInt:toValue] time:seconds];
}

-(void)animate:(NSString*)key toInt:(int)toValue time:(NSTimeInterval)seconds eased:(id)easing
{
    [self animate:key to:[NSNumber numberWithInt:toValue] time:seconds eased:easing];
}

-(void)animate:(NSString*)key fromFloat:(float)fromValue to:(float)toValue time:(NSTimeInterval)seconds
{
    [self animate:key
             from:[NSNumber numberWithFloat:fromValue]
               to:[NSNumber numberWithFloat:toValue]
             time:seconds];
}

-(void)animate:(NSString*)key
     fromFloat:(float)fromValue
            to:(float)toValue
          time:(NSTimeInterval)seconds
         eased:(id)easing
{
    [self animate:key
             from:[NSNumber numberWithFloat:fromValue]
               to:[NSNumber numberWithFloat:toValue]
             time:seconds
            eased:easing];
}

-(void)animate:(NSString*)key toFloat:(float)toValue time:(NSTimeInterval)seconds
{
    [self animate:key to:[NSNumber numberWithFloat:toValue] time:seconds];
}

-(void)animate:(NSString*)key toFloat:(float)toValue time:(NSTimeInterval)seconds eased:(id)easing
{
    [self animate:key to:[NSNumber numberWithFloat:toValue] time:seconds eased:easing];
}

-(void)animate:(NSString*)key fromDouble:(double)fromValue to:(double)toValue time:(NSTimeInterval)seconds
{
    [self animate:key
             from:[NSNumber numberWithDouble:fromValue]
               to:[NSNumber numberWithDouble:toValue]
             time:seconds];
}

-(void)animate:(NSString*)key
    fromDouble:(double)fromValue
            to:(double)toValue
          time:(NSTimeInterval)seconds
         eased:(id)easing
{
    [self animate:key
             from:[NSNumber numberWithDouble:fromValue]
               to:[NSNumber numberWithDouble:toValue]
             time:seconds
            eased:easing];
}

-(void)animate:(NSString*)key toDouble:(double)toValue time:(NSTimeInterval)seconds
{
    [self animate:key to:[NSNumber numberWithDouble:toValue] time:seconds];
}

-(void)animate:(NSString*)key toDouble:(double)toValue time:(NSTimeInterval)seconds eased:(id)easing
{
    [self animate:key to:[NSNumber numberWithDouble:toValue] time:seconds eased:easing];
}

-(void)animate:(NSString*)key
       fromInt:(int)fromValue to:(int)toValue
          time:(NSTimeInterval)seconds
    completion:(void (^)())block
{
    [self animate:key
             from:[NSNumber numberWithInt:fromValue]
               to:[NSNumber numberWithInt:toValue]
             time:seconds
       completion:block];
}

-(void)animate:(NSString*)key
       fromInt:(int)fromValue
            to:(int)toValue
          time:(NSTimeInterval)seconds
         eased:(id)easing
    completion:(void (^)())block
{
    [self animate:key
             from:[NSNumber numberWithInt:fromValue]
               to:[NSNumber numberWithInt:toValue]
             time:seconds
            eased:easing
       completion:block];
}

-(void)animate:(NSString*)key
         toInt:(int)toValue
          time:(NSTimeInterval)seconds
    completion:(void (^)())block
{
    [self animate:key to:[NSNumber numberWithInt:toValue] time:seconds];
}

-(void)animate:(NSString*)key
         toInt:(int)toValue
          time:(NSTimeInterval)seconds
         eased:(id)easing
    completion:(void (^)())block
{
    [self animate:key to:[NSNumber numberWithInt:toValue] time:seconds eased:easing completion:block];
}

-(void)animate:(NSString*)key
     fromFloat:(float)fromValue
            to:(float)toValue
          time:(NSTimeInterval)seconds
    completion:(void (^)())block
{
    [self animate:key
             from:[NSNumber numberWithFloat:fromValue]
               to:[NSNumber numberWithFloat:toValue]
             time:seconds
       completion:block];
}

-(void)animate:(NSString*)key
     fromFloat:(float)fromValue
            to:(float)toValue
          time:(NSTimeInterval)seconds
         eased:(id)easing
    completion:(void (^)())block
{
    [self animate:key
             from:[NSNumber numberWithFloat:fromValue]
               to:[NSNumber numberWithFloat:toValue]
             time:seconds
            eased:easing
       completion:block];
}

-(void)animate:(NSString*)key
       toFloat:(float)toValue
          time:(NSTimeInterval)seconds
    completion:(void (^)())block
{
    [self animate:key to:[NSNumber numberWithFloat:toValue] time:seconds completion:block];
}

-(void)animate:(NSString*)key
       toFloat:(float)toValue
          time:(NSTimeInterval)seconds
         eased:(id)easing
    completion:(void (^)())block
{
    [self animate:key to:[NSNumber numberWithFloat:toValue] time:seconds eased:easing completion:block];
}

-(void)animate:(NSString*)key
    fromDouble:(double)fromValue
            to:(double)toValue
          time:(NSTimeInterval)seconds
    completion:(void (^)())block
{
    [self animate:key
             from:[NSNumber numberWithDouble:fromValue]
               to:[NSNumber numberWithDouble:toValue]
             time:seconds
       completion:block];
}

-(void)animate:(NSString*)key
    fromDouble:(double)fromValue
            to:(double)toValue
          time:(NSTimeInterval)seconds
         eased:(id)easing
    completion:(void (^)())block
{
    [self animate:key
             from:[NSNumber numberWithDouble:fromValue]
               to:[NSNumber numberWithDouble:toValue]
             time:seconds
            eased:easing
       completion:block];
}

-(void)animate:(NSString*)key
      toDouble:(double)toValue
          time:(NSTimeInterval)seconds
    completion:(void (^)())block
{
    [self animate:key to:[NSNumber numberWithDouble:toValue] time:seconds completion:block];
}

-(void)animate:(NSString*)key
      toDouble:(double)toValue
          time:(NSTimeInterval)seconds
         eased:(id)easing
    completion:(void (^)())block
{
    [self animate:key to:[NSNumber numberWithDouble:toValue] time:seconds eased:easing completion:block];
}

#pragma mark Points
-(void)animate:(NSString*)key fromPoint:(NSPoint)fromValue to:(NSPoint)toValue time:(NSTimeInterval)seconds
{
    [self animate:key
             from:[NSValue valueWithPoint:fromValue]
               to:[NSValue valueWithPoint:toValue]
             time:seconds];
}

-(void)animate:(NSString*)key
     fromPoint:(NSPoint)fromValue
            to:(NSPoint)toValue
          time:(NSTimeInterval)seconds
         eased:(id)easing
{
    [self animate:key
             from:[NSValue valueWithPoint:fromValue]
               to:[NSValue valueWithPoint:toValue]
             time:seconds
            eased:easing];
}

-(void)animate:(NSString*)key toPoint:(NSPoint)toValue time:(NSTimeInterval)seconds
{
    [self animate:key to:[NSValue valueWithPoint:toValue] time:seconds];
}

-(void)animate:(NSString*)key toPoint:(NSPoint)toValue time:(NSTimeInterval)seconds eased:(id)easing
{
    [self animate:key to:[NSValue valueWithPoint:toValue] time:seconds eased:easing];
}

-(void)animate:(NSString*)key fromCGPoint:(CGPoint)fromValue to:(CGPoint)toValue time:(NSTimeInterval)seconds
{
    [self animate:key
             from:[NSValue valueWithPoint:NSPointFromCGPoint(fromValue)]
               to:[NSValue valueWithPoint:NSPointFromCGPoint(toValue)]
             time:seconds];
}

-(void)animate:(NSString*)key
   fromCGPoint:(CGPoint)fromValue
            to:(CGPoint)toValue
          time:(NSTimeInterval)seconds
         eased:(id)easing
{
    [self animate:key
             from:[NSValue valueWithPoint:NSPointFromCGPoint(fromValue)]
               to:[NSValue valueWithPoint:NSPointFromCGPoint(toValue)]
             time:seconds
            eased:easing];
}

-(void)animate:(NSString*)key toCGPoint:(CGPoint)toValue time:(NSTimeInterval)seconds
{
    [self animate:key to:[NSValue valueWithPoint:NSPointFromCGPoint(toValue)] time:seconds];
}

-(void)animate:(NSString*)key toCGPoint:(CGPoint)toValue time:(NSTimeInterval)seconds eased:(id)easing
{
    [self animate:key to:[NSValue valueWithPoint:NSPointFromCGPoint(toValue)] time:seconds eased:easing];
}

-(void)animate:(NSString*)key
     fromPoint:(NSPoint)fromValue
            to:(NSPoint)toValue
          time:(NSTimeInterval)seconds
    completion:(void (^)())block
{
    [self animate:key
             from:[NSValue valueWithPoint:fromValue]
               to:[NSValue valueWithPoint:toValue]
             time:seconds
       completion:block];
}

-(void)animate:(NSString*)key
     fromPoint:(NSPoint)fromValue
            to:(NSPoint)toValue
          time:(NSTimeInterval)seconds
         eased:(id)easing
    completion:(void (^)())block
{
    [self animate:key
             from:[NSValue valueWithPoint:fromValue]
               to:[NSValue valueWithPoint:toValue]
             time:seconds
            eased:easing
       completion:block];
}

-(void)animate:(NSString*)key
       toPoint:(NSPoint)toValue
          time:(NSTimeInterval)seconds
    completion:(void (^)())block
{
    [self animate:key to:[NSValue valueWithPoint:toValue] time:seconds completion:block];
}

-(void)animate:(NSString*)key
       toPoint:(NSPoint)toValue
          time:(NSTimeInterval)seconds
         eased:(id)easing
    completion:(void (^)())block
{
    [self animate:key to:[NSValue valueWithPoint:toValue] time:seconds eased:easing completion:block];
}

-(void)animate:(NSString*)key
   fromCGPoint:(CGPoint)fromValue
            to:(CGPoint)toValue
          time:(NSTimeInterval)seconds
    completion:(void (^)())block
{
    [self animate:key
             from:[NSValue valueWithPoint:NSPointFromCGPoint(fromValue)]
               to:[NSValue valueWithPoint:NSPointFromCGPoint(toValue)]
             time:seconds
       completion:block];
}

-(void)animate:(NSString*)key
   fromCGPoint:(CGPoint)fromValue
            to:(CGPoint)toValue
          time:(NSTimeInterval)seconds
         eased:(id)easing
    completion:(void (^)())block
{
    [self animate:key
             from:[NSValue valueWithPoint:NSPointFromCGPoint(fromValue)]
               to:[NSValue valueWithPoint:NSPointFromCGPoint(toValue)]
             time:seconds
            eased:easing
       completion:block];
}

-(void)animate:(NSString*)key
     toCGPoint:(CGPoint)toValue
          time:(NSTimeInterval)seconds
    completion:(void (^)())block
{
    [self animate:key to:[NSValue valueWithPoint:NSPointFromCGPoint(toValue)] time:seconds completion:block];
}

-(void)animate:(NSString*)key
     toCGPoint:(CGPoint)toValue
          time:(NSTimeInterval)seconds
         eased:(id)easing
    completion:(void (^)())block
{
    [self animate:key
               to:[NSValue valueWithPoint:NSPointFromCGPoint(toValue)]
             time:seconds
            eased:easing
       completion:block];
}

#pragma mark Sizes
-(void)animate:(NSString*)key fromSize:(NSSize)fromValue to:(NSSize)toValue time:(NSTimeInterval)seconds
{
    [self animate:key
             from:[NSValue valueWithSize:fromValue]
               to:[NSValue valueWithSize:toValue]
             time:seconds];
}

-(void)animate:(NSString*)key
      fromSize:(NSSize)fromValue
            to:(NSSize)toValue
          time:(NSTimeInterval)seconds
         eased:(id)easing
{
    [self animate:key
             from:[NSValue valueWithSize:fromValue]
               to:[NSValue valueWithSize:toValue]
             time:seconds
            eased:easing];
}

-(void)animate:(NSString*)key toSize:(NSSize)toValue time:(NSTimeInterval)seconds
{
    [self animate:key to:[NSValue valueWithSize:toValue] time:seconds];
}

-(void)animate:(NSString*)key toSize:(NSSize)toValue time:(NSTimeInterval)seconds eased:(id)easing
{
    [self animate:key to:[NSValue valueWithSize:toValue] time:seconds eased:easing];
}

-(void)animate:(NSString*)key fromCGSize:(CGSize)fromValue to:(CGSize)toValue time:(NSTimeInterval)seconds
{
    [self animate:key
             from:[NSValue valueWithSize:NSSizeFromCGSize(fromValue)]
               to:[NSValue valueWithSize:NSSizeFromCGSize(toValue)]
             time:seconds];
}

-(void)animate:(NSString*)key
    fromCGSize:(CGSize)fromValue
            to:(CGSize)toValue
          time:(NSTimeInterval)seconds
         eased:(id)easing
{
    [self animate:key
             from:[NSValue valueWithSize:NSSizeFromCGSize(fromValue)]
               to:[NSValue valueWithSize:NSSizeFromCGSize(toValue)]
             time:seconds
            eased:easing];
}

-(void)animate:(NSString*)key toCGSize:(CGSize)toValue time:(NSTimeInterval)seconds
{
    [self animate:key to:[NSValue valueWithSize:NSSizeFromCGSize(toValue)] time:seconds];
}

-(void)animate:(NSString*)key toCGSize:(CGSize)toValue time:(NSTimeInterval)seconds eased:(id)easing
{
    [self animate:key to:[NSValue valueWithSize:NSSizeFromCGSize(toValue)] time:seconds eased:easing];
}

-(void)animate:(NSString*)key
      fromSize:(NSSize)fromValue
            to:(NSSize)toValue
          time:(NSTimeInterval)seconds
    completion:(void (^)())block
{
    [self animate:key
             from:[NSValue valueWithSize:fromValue]
               to:[NSValue valueWithSize:toValue]
             time:seconds
       completion:block];
}

-(void)animate:(NSString*)key
      fromSize:(NSSize)fromValue
            to:(NSSize)toValue
          time:(NSTimeInterval)seconds
         eased:(id)easing
    completion:(void (^)())block
{
    [self animate:key
             from:[NSValue valueWithSize:fromValue]
               to:[NSValue valueWithSize:toValue]
             time:seconds
            eased:easing
       completion:block];
}

-(void)animate:(NSString*)key 
        toSize:(NSSize)toValue
          time:(NSTimeInterval)seconds
    completion:(void (^)())block
{
    [self animate:key to:[NSValue valueWithSize:toValue] time:seconds completion:block];
}

-(void)animate:(NSString*)key
        toSize:(NSSize)toValue
          time:(NSTimeInterval)seconds
         eased:(id)easing
    completion:(void (^)())block
{
    [self animate:key to:[NSValue valueWithSize:toValue] time:seconds eased:easing completion:block];
}

-(void)animate:(NSString*)key
    fromCGSize:(CGSize)fromValue
            to:(CGSize)toValue
          time:(NSTimeInterval)seconds
    completion:(void (^)())block
{
    [self animate:key
             from:[NSValue valueWithSize:NSSizeFromCGSize(fromValue)]
               to:[NSValue valueWithSize:NSSizeFromCGSize(toValue)]
             time:seconds
       completion:block];
}

-(void)animate:(NSString*)key
    fromCGSize:(CGSize)fromValue
            to:(CGSize)toValue
          time:(NSTimeInterval)seconds
         eased:(id)easing
    completion:(void (^)())block
{
    [self animate:key
             from:[NSValue valueWithSize:NSSizeFromCGSize(fromValue)]
               to:[NSValue valueWithSize:NSSizeFromCGSize(toValue)]
             time:seconds
            eased:easing
       completion:block];
}

-(void)animate:(NSString*)key
      toCGSize:(CGSize)toValue
          time:(NSTimeInterval)seconds
    completion:(void (^)())block
{
    [self animate:key to:[NSValue valueWithSize:NSSizeFromCGSize(toValue)] time:seconds completion:block];
}

-(void)animate:(NSString*)key
      toCGSize:(CGSize)toValue
          time:(NSTimeInterval)seconds
         eased:(id)easing
    completion:(void (^)())block
{
    [self animate:key
               to:[NSValue valueWithSize:NSSizeFromCGSize(toValue)]
             time:seconds
            eased:easing
       completion:block];
}

#pragma mark Rects
-(void)animate:(NSString*)key fromRect:(NSRect)fromValue to:(NSRect)toValue time:(NSTimeInterval)seconds
{
    [self animate:key
             from:[NSValue valueWithRect:fromValue]
               to:[NSValue valueWithRect:toValue]
             time:seconds];
}

-(void)animate:(NSString*)key
      fromRect:(NSRect)fromValue
            to:(NSRect)toValue
          time:(NSTimeInterval)seconds
         eased:(id)easing
{
    [self animate:key
             from:[NSValue valueWithRect:fromValue]
               to:[NSValue valueWithRect:toValue]
             time:seconds
            eased:easing];
}

-(void)animate:(NSString*)key toRect:(NSRect)toValue time:(NSTimeInterval)seconds
{
    [self animate:key to:[NSValue valueWithRect:toValue] time:seconds];
}

-(void)animate:(NSString*)key toRect:(NSRect)toValue time:(NSTimeInterval)seconds eased:(id)easing
{
    [self animate:key to:[NSValue valueWithRect:toValue] time:seconds eased:easing];
}

-(void)animate:(NSString*)key fromCGRect:(CGRect)fromValue to:(CGRect)toValue time:(NSTimeInterval)seconds
{
    [self animate:key
             from:[NSValue valueWithRect:NSRectFromCGRect(fromValue)]
               to:[NSValue valueWithRect:NSRectFromCGRect(toValue)]
             time:seconds];
}

-(void)animate:(NSString*)key
    fromCGRect:(CGRect)fromValue
            to:(CGRect)toValue
          time:(NSTimeInterval)seconds
         eased:(id)easing
{
    [self animate:key
             from:[NSValue valueWithRect:NSRectFromCGRect(fromValue)]
               to:[NSValue valueWithRect:NSRectFromCGRect(toValue)]
             time:seconds
            eased:easing];
}

-(void)animate:(NSString*)key toCGRect:(CGRect)toValue time:(NSTimeInterval)seconds
{
    [self animate:key to:[NSValue valueWithRect:NSRectFromCGRect(toValue)] time:seconds];
}

-(void)animate:(NSString*)key toCGRect:(CGRect)toValue time:(NSTimeInterval)seconds eased:(id)easing
{
    [self animate:key to:[NSValue valueWithRect:NSRectFromCGRect(toValue)] time:seconds eased:easing];
}

-(void)animate:(NSString*)key
      fromRect:(NSRect)fromValue
            to:(NSRect)toValue
          time:(NSTimeInterval)seconds
    completion:(void (^)())block
{
    [self animate:key
             from:[NSValue valueWithRect:fromValue]
               to:[NSValue valueWithRect:toValue]
             time:seconds
       completion:block];
}

-(void)animate:(NSString*)key
      fromRect:(NSRect)fromValue
            to:(NSRect)toValue
          time:(NSTimeInterval)seconds
         eased:(id)easing
    completion:(void (^)())block
{
    [self animate:key
             from:[NSValue valueWithRect:fromValue]
               to:[NSValue valueWithRect:toValue]
             time:seconds
            eased:easing
       completion:block];
}

-(void)animate:(NSString*)key
        toRect:(NSRect)toValue
          time:(NSTimeInterval)seconds
    completion:(void (^)())block
{
    [self animate:key to:[NSValue valueWithRect:toValue] time:seconds completion:block];
}

-(void)animate:(NSString*)key
        toRect:(NSRect)toValue
          time:(NSTimeInterval)seconds
         eased:(id)easing
    completion:(void (^)())block
{
    [self animate:key to:[NSValue valueWithRect:toValue] time:seconds eased:easing completion:block];
}

-(void)animate:(NSString*)key
    fromCGRect:(CGRect)fromValue
            to:(CGRect)toValue
          time:(NSTimeInterval)seconds
    completion:(void (^)())block
{
    [self animate:key
             from:[NSValue valueWithRect:NSRectFromCGRect(fromValue)]
               to:[NSValue valueWithRect:NSRectFromCGRect(toValue)]
             time:seconds
       completion:block];
}

-(void)animate:(NSString*)key
    fromCGRect:(CGRect)fromValue
            to:(CGRect)toValue
          time:(NSTimeInterval)seconds
         eased:(id)easing completion:(void (^)())block
{
    [self animate:key
             from:[NSValue valueWithRect:NSRectFromCGRect(fromValue)]
               to:[NSValue valueWithRect:NSRectFromCGRect(toValue)]
             time:seconds
            eased:easing
       completion:block];
}

-(void)animate:(NSString*)key
      toCGRect:(CGRect)toValue
          time:(NSTimeInterval)seconds
    completion:(void (^)())block
{
    [self animate:key to:[NSValue valueWithRect:NSRectFromCGRect(toValue)] time:seconds completion:block];
}

-(void)animate:(NSString*)key
      toCGRect:(CGRect)toValue
          time:(NSTimeInterval)seconds
         eased:(id)easing
    completion:(void (^)())block
{
    [self animate:key
               to:[NSValue valueWithRect:NSRectFromCGRect(toValue)]
             time:seconds
            eased:easing
       completion:block];
}

#pragma mark Transforms
-(void)animate:(NSString*)key
 fromTransform:(CATransform3D)fromValue
            to:(CATransform3D)toValue
          time:(NSTimeInterval)seconds
{
    [self animate:key
             from:[NSValue valueWithCATransform3D:fromValue]
               to:[NSValue valueWithCATransform3D:toValue]
             time:seconds];
}

-(void)animate:(NSString*)key
 fromTransform:(CATransform3D)fromValue
            to:(CATransform3D)toValue
          time:(NSTimeInterval)seconds
         eased:(id)easing
{
    [self animate:key
             from:[NSValue valueWithCATransform3D:fromValue]
               to:[NSValue valueWithCATransform3D:toValue]
             time:seconds
            eased:easing];
}

-(void)animate:(NSString*)key toTransform:(CATransform3D)toValue time:(NSTimeInterval)seconds
{
    [self animate:key to:[NSValue valueWithCATransform3D:toValue] time:seconds];
}

-(void)animate:(NSString*)key toTransform:(CATransform3D)toValue time:(NSTimeInterval)seconds eased:(id)easing
{
    [self animate:key to:[NSValue valueWithCATransform3D:toValue] time:seconds eased:easing];
}

-(void)animate:(NSString*)key
 fromTransform:(CATransform3D)fromValue
            to:(CATransform3D)toValue
          time:(NSTimeInterval)seconds
    completion:(void (^)())block
{
    [self animate:key
             from:[NSValue valueWithCATransform3D:fromValue]
               to:[NSValue valueWithCATransform3D:toValue]
             time:seconds
       completion:block];
}

-(void)animate:(NSString*)key
 fromTransform:(CATransform3D)fromValue
            to:(CATransform3D)toValue
          time:(NSTimeInterval)seconds
         eased:(id)easing
    completion:(void (^)())block
{
    [self animate:key
             from:[NSValue valueWithCATransform3D:fromValue]
               to:[NSValue valueWithCATransform3D:toValue]
             time:seconds
            eased:easing
       completion:block];
}

-(void)animate:(NSString*)key
   toTransform:(CATransform3D)toValue
          time:(NSTimeInterval)seconds
    completion:(void (^)())block
{
    [self animate:key to:[NSValue valueWithCATransform3D:toValue] time:seconds completion:block];
}

-(void)animate:(NSString*)key
   toTransform:(CATransform3D)toValue
          time:(NSTimeInterval)seconds
         eased:(id)easing
    completion:(void (^)())block
{
    [self animate:key to:[NSValue valueWithCATransform3D:toValue] time:seconds eased:easing completion:block];
}

@end

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

#import "CABasicAnimation+FunSize.h"

@implementation CABasicAnimation (FunSize)

#pragma mark Number Getters
-(int)fromInt
{
    return [[self fromValue] intValue];
}

-(float)fromFloat
{
    return [[self fromValue] floatValue];
}

-(double)fromDouble
{
    return [[self fromValue] doubleValue];
}

-(int)toInt
{
    return [[self toValue] intValue];
}

-(float)toFloat
{
    return [[self toValue] floatValue];
}

-(double)toDouble
{
    return [[self toValue] doubleValue];
}

#pragma mark Number Setters
-(void)setFromInt:(int)from
{
    [self setFromValue:[NSNumber numberWithInt:from]];
}

-(void)setToInt:(int)to
{
    [self setToValue:[NSNumber numberWithInt:to]];
}

-(void)setFromFloat:(float)from
{
    [self setFromValue:[NSNumber numberWithFloat:from]];
}

-(void)setToFloat:(float)to
{
    [self setToValue:[NSNumber numberWithFloat:to]];
}

-(void)setFromDouble:(double)from
{
    [self setFromValue:[NSNumber numberWithDouble:from]];
}

-(void)setToDouble:(double)to
{
    [self setToValue:[NSNumber numberWithDouble:to]];
}

#pragma mark Point Getters
-(NSPoint)fromPoint
{
    return [[self fromValue] pointValue];
}

-(CGPoint)fromCGPoint
{
    return [[self fromValue] pointValue];
}

-(NSPoint)toPoint
{
    return [[self toValue] pointValue];
}

-(CGPoint)toCGPoint
{
    return [[self toValue] pointValue];
}

#pragma mark Point Setters
-(void)setFromPoint:(NSPoint)from
{
    [self setFromValue:[NSValue valueWithPoint:from]];
}

-(void)setToPoint:(NSPoint)to
{
    [self setToValue:[NSValue valueWithPoint:to]];
}

-(void)setFromCGPoint:(CGPoint)from
{
    [self setFromValue:[NSValue valueWithPoint:from]];
}

-(void)setToCGPoint:(CGPoint)to
{
    [self setToValue:[NSValue valueWithPoint:to]];
}

#pragma mark Rect Getters
-(NSRect)fromRect
{
    return [[self fromValue] rectValue];
}

-(CGRect)fromCGRect
{
    return [[self fromValue] rectValue];
}

-(NSRect)toRect
{
    return [[self toValue] rectValue];
}

-(CGRect)toCGRect
{
    return [[self toValue] rectValue];
}

#pragma mark Rect Setters
-(void)setFromRect:(NSRect)from
{
    [self setFromValue:[NSValue valueWithRect:from]];
}

-(void)setToRect:(NSRect)to
{
    [self setToValue:[NSValue valueWithRect:to]];
}

-(void)setFromCGRect:(CGRect)from
{
    [self setFromValue:[NSValue valueWithRect:from]];
}

-(void)setToCGRect:(CGRect)to
{
    [self setToValue:[NSValue valueWithRect:to]];
}

#pragma mark Transform Getters
-(CATransform3D)fromTransform
{
    return [[self fromValue] CATransform3DValue];
}

-(CATransform3D)toTransform
{
    return [[self toValue] CATransform3DValue];
}

#pragma mark Transform Setters
-(void)setFromTransform:(CATransform3D)from
{
    [self setFromValue:[NSValue valueWithCATransform3D:from]];
}

-(void)setToTransform:(CATransform3D)to
{
    [self setToValue:[NSValue valueWithCATransform3D:to]];
}

#pragma mark Timing
-(void)setTiming:(NSString*)timingFunctionName
{
    [self setTimingFunction:[CAMediaTimingFunction functionWithName:timingFunctionName]];
}

@end

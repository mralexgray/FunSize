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

#import "CAKeyframeAnimation+FunSize.h"

@implementation CAKeyframeAnimation (FunSize)

+(CAKeyframeAnimation*)animationWithKeyframes:(NSUInteger)count function:(id (^)(double))block
{
    NSMutableArray* values = [NSMutableArray arrayWithCapacity:count];
    
    for (NSUInteger i = 0; i < count; i++)
    {
        [values addObject:block(((double)i) / (count - 1))];
    }
    
    CAKeyframeAnimation* anim = [CAKeyframeAnimation animation];
    [anim setValues:values];
    
    return anim;
}

+(CAKeyframeAnimation*)animationWithKeyframes:(NSUInteger)count doubleFunction:(double (^)(double))block
{
    NSMutableArray* values = [NSMutableArray arrayWithCapacity:count];
    
    for (NSUInteger i = 0; i < count; i++)
    {
        [values addObject:[NSNumber numberWithDouble:block(((double)i) / (count - 1))]];
    }
    
    CAKeyframeAnimation* anim = [CAKeyframeAnimation animation];
    [anim setValues:values];
    
    return anim;
}

+(CAKeyframeAnimation*)animationWithKeyframes:(NSUInteger)count rectFunction:(CGRect (^)(double))block
{
    NSMutableArray* values = [NSMutableArray arrayWithCapacity:count];
    
    for (NSUInteger i = 0; i < count; i++)
    {
        [values addObject:[NSValue valueWithRect:NSRectFromCGRect(block(((double)i) / (count - 1)))]];
    }
    
    CAKeyframeAnimation* anim = [CAKeyframeAnimation animation];
    [anim setValues:values];
    
    return anim;
}

+(CAKeyframeAnimation*)animationWithKeyframes:(NSUInteger)count transformFunction:(CATransform3D (^)(double))block
{
    NSMutableArray* values = [NSMutableArray arrayWithCapacity:count];
    
    for (NSUInteger i = 0; i < count; i++)
    {
        [values addObject:[NSValue valueWithCATransform3D:block(((double)i) / (count - 1))]];
    }
    
    CAKeyframeAnimation* anim = [CAKeyframeAnimation animation];
    [anim setValues:values];
    
    return anim;
}

@end

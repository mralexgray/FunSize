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

#import "NSGraphicsContext+FunSize.h"

@implementation NSGraphicsContext (FunSize)

+(void)drawInContext:(CGContextRef)ctx flipped:(BOOL)flipped actions:(void(^)())actions
{
    [self saveGraphicsState];
    
    NSGraphicsContext* context = [[self class] graphicsContextWithGraphicsPort:ctx flipped:flipped];
    [self setCurrentContext:context];
    
    actions();
    
    [self restoreGraphicsState];
}

+(void)state:(void(^)())actions
{
    [[self currentContext] state:actions];
}

-(void)state:(void(^)())actions
{
    [self saveGraphicsState];
    actions();
    [self restoreGraphicsState];
}

@end

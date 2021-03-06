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

#import "NSImage+FunSize.h"
#if !TARGET_OS_IPHONE

@implementation NSImage (FunSize)

-(CGImageRef)CGImage
{
    return [self CGImageForProposedRect:NULL context:nil hints:nil];
}
//#if MAC_OS_X_VERSION_MIN_REQUIRED < MAC_OS_X_VERSION_10_9
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wobjc-protocol-method-implementation"

-(void)drawInRect:(NSRect)rect
{
    [self drawInRect:rect
            fromRect:NSZeroRect
           operation:NSCompositeSourceOver
            fraction:1.0
      respectFlipped:YES
               hints:nil];
}
//#endif
#pragma clang diagnostic pop

-(void)drawInRect:(NSRect)rect fraction:(CGFloat)fraction
{
    [self drawInRect:rect
            fromRect:NSZeroRect
           operation:NSCompositeSourceOver
            fraction:fraction
      respectFlipped:YES
               hints:nil];
}

@end
#endif
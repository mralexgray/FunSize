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

#import "NSColor+FunSize.h"


@implementation NSColor (FunSize)

+(NSColor*)colorWithHex:(NSString*)hex
{
    // determine the component length
    NSUInteger length = [hex length];
    NSUInteger componentLength;
    
    if (length == 3 || length == 4)
        componentLength = 1;
    else if (length == 6 || length == 8)
        componentLength = 2;
    else
        return [self whiteColor];
    
    // scan for the components
    CGFloat components[4];
    components[3] = 1.0;
    for (int i = 0; i < length / componentLength; i++)
    {
        // where to scan?
        NSRange range = NSMakeRange(i * componentLength, componentLength);
        
        // scan the value
        unsigned int value;
        NSScanner* scan = [NSScanner scannerWithString:[hex substringWithRange:range]];
        [scan scanHexInt:&value];
        
        // scale the value to 255
        if (componentLength == 1)
            value += value * 15;
        
        // set the color component
        components[i] = (CGFloat)value / 255.0;
    }
    
    // create the color
    return [self colorWithCalibratedRed:components[0]
                                  green:components[1]
                                   blue:components[2]
                                  alpha:components[3]];
}

//+(NSColor*)colorWithCGColor:(CGColorRef)color
//{
//    return [self colorWithCIColor:[CIColor colorWithCGColor:color]];
//}

@end

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

#import "NSString+FunSize.h"

@implementation NSString (FunSize)

-(NSString*)stringByURLEncoding
{
//    id result =
	 	return CFBridgingRelease(CFURLCreateStringByAddingPercentEscapes(kCFAllocatorDefault,
                                                                          (CFStringRef)self,
                                                                          NULL,
                                                                          CFSTR("!*'();:@&=+$,/?%#[]"),
                                                                          kCFStringEncodingUTF8));
//    return [result autorelease];
}
#if MAC_ONLY

-(NSSize)sizeWithSize:(NSSize)size attributes:(NSDictionary*)attributes
{
    NSAttributedString* string = [[NSAttributedString alloc] initWithString:self attributes:attributes];
    CTFramesetterRef framesetter = CTFramesetterCreateWithAttributedString((__bridge CFAttributedStringRef)string);
    
    CFRange fitRange;
    CGSize s = CTFramesetterSuggestFrameSizeWithConstraints(framesetter,
                                                            CFRangeMake(0, 0),
                                                            NULL,
                                                            NSSizeToCGSize(size),
                                                            &fitRange);
    CFRelease(framesetter);
//    [string release];
    return s;
}
#endif

@end

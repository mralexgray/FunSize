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

@interface NSColor (FunSize)

/**
 * Creates a color with a hex string.
 *
 * @param hex The hex string. The string must be of length 3, 4, 6, or 8. Strings of length 3 and 6 have an implicit
 * alpha component of 100%. If the string is of any other length, white will be returned. Note that the "#" prefix
 * from HTML/CSS should be omitted.
 */
+(NSColor*)colorWithHex:(NSString*)hex;

+(NSColor*)colorWithCGColor:(CGColorRef)color;

@end

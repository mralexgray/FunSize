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

#import <AppKit/AppKit.h>

@interface NSGradient (FunSize)

/**	Creates a gradient with two colors.
 *
 * @param start The starting color.
 * @param end The ending hex color.	*/
+(NSGradient*)gradientFrom:(NSColor*)start to:(NSColor*)end;

/**	Creates a gradient with hex values, as shown in NSColor(FunSize).
 *
 * @see NSColor(FunSize)
 *
 * @param start The starting hex value.
 * @param end The ending hex value.	*/
+(NSGradient*)gradientFromHex:(NSString*)start to:(NSString*)end;

/**	Initializes a gradient with hex values, as shown in NSColor(FunSize).
 *
 * @see NSColor(FunSize)
 *
 * @param start The starting hex value.
 * @param end The ending hex value.	*/
-(id)initWithStartingHex:(NSString*)start endingHex:(NSString*)end;

/**	Creates a gradient with hex values and an alpha component.
 *
 * @see NSColor(FunSize)
 *
 * @param start The starting hex value.
 * @param startAlpha The starting alpha value.
 * @param end The ending hex value.
 * @param endAlpha The ending alpha value.	*/
+(NSGradient*)gradientFromHex:(NSString*)start alpha:(CGFloat)startAlpha to:(NSString*)end alpha:(CGFloat)endAlpha;

/**	Initializes a gradient with hex values and an alpha component.
 *
 * @see NSColor(FunSize)
 *
 * @param start The starting hex value.
 * @param startAlpha The starting alpha value.
 * @param end The ending hex value.
 * @param endAlpha The ending alpha value.	*/
-(id)initWithStartingHex:(NSString*)start alpha:(CGFloat)startAlpha endingHex:(NSString*)end alpha:(CGFloat)endAlpha;

@end

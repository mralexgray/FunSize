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

#if !TARGET_OS_IPHONE

#import <AppKit/AppKit.h>

@interface NSShadow (FunSize)

/**	Returns an "inset" shadow, ideal for rendering text. The shadow has a offset of (0, 1) and a radius of 0.
 *
 * @param color The color to use for the shadow, typically a partially transparent white or black.	*/
+(NSShadow*)shadowInsetUpWithColor:(NSColor*)color;

/**	Returns an "inset" shadow, ideal for rendering text. The shadow has a offset of (0, -1) and a radius of 0.
 *
 * @param color The color to use for the shadow, typically a partially transparent white or black.	*/
+(NSShadow*)shadowInsetDownWithColor:(NSColor*)color;

/**	Returns a shadow with the specified color, offset, and radius
 *
 * @param color The color of the shadow
 * @param offset The shadow's offset.
 * @param radius The radius of shadow.	*/
+(NSShadow*)shadowWithColor:(NSColor*)color offset:(NSSize)offset radius:(CGFloat)radius;

/**	Returns a shadow with the specified hex color, offset, and radius
 *
 * @param hex A hexadecimal color string.
 * @param offset The shadow's offset.
 * @param radius The radius of shadow.	*/
+(NSShadow*)shadowWithHex:(NSString*)hex offset:(NSSize)offset radius:(CGFloat)radius;

@end
#endif

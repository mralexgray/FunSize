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

#import "NSShadow+FunSize.h"

@implementation NSShadow (NSShadow_FunSize)

+(NSShadow*)insetUpWithColor:(NSColor*)color
{
    NSShadow* shadow = [[self alloc] init];
    [shadow setShadowBlurRadius:0];
    [shadow setShadowColor:color];
    [shadow setShadowOffset:NSMakeSize(0, 1)];
    
    return [shadow autorelease];
}

+(NSShadow*)insetDownWithColor:(NSColor*)color
{
    NSShadow* shadow = [[self alloc] init];
    [shadow setShadowBlurRadius:0];
    [shadow setShadowColor:color];
    [shadow setShadowOffset:NSMakeSize(0, -1)];
    
    return [shadow autorelease];
}

@end

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

#import "NSEvent+FunSize.h"
#if !TARGET_OS_IPHONE

@implementation NSEvent (FunSize)

-(BOOL)isKeyEvent
{
    return ([self type] == NSKeyDown ||
            [self type] == NSKeyUp ||
            [self type] == NSFlagsChanged);
}

-(BOOL)isMouseEvent
{
    return ([self type] == NSLeftMouseDown ||
            [self type] == NSLeftMouseUp ||
            [self type] == NSLeftMouseDragged ||
            [self type] == NSRightMouseDown ||
            [self type] == NSRightMouseUp ||
            [self type] == NSRightMouseDragged ||
            [self type] == NSOtherMouseDown ||
            [self type] == NSOtherMouseUp ||
            [self type] == NSOtherMouseDragged);
}

-(BOOL)isMouseDownEvent
{
    return ([self type] == NSLeftMouseDown ||
            [self type] == NSRightMouseDown ||
            [self type] == NSOtherMouseDown);
}

-(BOOL)isMouseUpEvent
{
    return ([self type] == NSLeftMouseUp ||
            [self type] == NSRightMouseUp ||
            [self type] == NSOtherMouseUp);
}

-(BOOL)isEnterExitEvent
{
    return ([self type] == NSMouseEntered ||
            [self type] == NSMouseExited ||
            [self type] == NSCursorUpdate);
}

-(BOOL)isOtherEvent
{
    return ![self isEnterExitEvent] && ![self isMouseEvent] && ![self isKeyEvent];
}

@end
#endif
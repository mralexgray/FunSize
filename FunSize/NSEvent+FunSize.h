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

@interface NSEvent (FunSize)

/** Returns whether or not the event is a key press, key release, or flags changed event. */
-(BOOL)isKeyEvent;

/** Returns whether or not the event is a mouse press, release, or drag. */
-(BOOL)isMouseEvent;

/** Returns whether or not the event is a mouse down event (for any button). */
-(BOOL)isMouseDownEvent;

/** Returns whether or not the event is a mouse up event (for any button). */
-(BOOL)isMouseUpEvent;

/** Returns whether or not the event is a mouse entered, mouse exited, or cursor update event. */
-(BOOL)isEnterExitEvent;

/** Returns whether or not the event is an "other" event. */
-(BOOL)isOtherEvent;

@end
#endif

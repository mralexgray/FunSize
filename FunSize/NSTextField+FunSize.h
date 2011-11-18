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

@interface NSTextField (FunSize)

#pragma mark -
#pragma mark Label Initializers
/** @name Label Initializers */

/**
 * Initializes a text field, formatted in "label" style, with the specified frame rect.
 */
-(id)initAsLabelWithFrame:(NSRect)frameRect;

/**
 * Initializes a text field, formatted in "selectable label" style, with the specified frame rect.
 */
-(id)initAsSelectableLabelWithFrame:(NSRect)frameRect;

#pragma mark -
#pragma mark Text Field Formatting
/** @name Text Field Formatting */

/**
 * Modifies the text field so that it appears and acts as a typical interactive
 * text field.
 */
-(void)formatAsField;

/**
 * Modifies the text field so that it appears and acts as a typical label.
 */
-(void)formatAsLabel;

/**
 * Modifies the text field so that it appears and acts as a typical label that
 * can be selected.
 */
-(void)formatAsSelectableLabel;

@end

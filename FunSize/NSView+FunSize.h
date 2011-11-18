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

@interface NSView (FunSize)

#pragma mark -
#pragma mark Recursive Subview Operations
/** @name Recursive Subview Operations */

/**
 * Recursively executes a block on this view and its subviews (and their subviews, etc.).
 *
 * @param block The block, which will receive each subview as a parameter.
 */
-(void)subviewsBlock:(void (^)(id view))block;

/**
 * Recursively executes a block on this view and its subviews (and their subviews, etc.). The block can abort the 
 * recursion and iteration by returning `NO`.
 *
 * @param block The block, which will receive each subview as a parameter.
 */
-(BOOL)subviewsBlockWithAbort:(BOOL (^)(id view))block;

/**
 * Recursively executes a block on this view's subviews (and their subviews, etc.).
 *
 * @param block The block, which will receive each subview as a parameter.
 */
-(void)subviewsBlockSkippingSelf:(void (^)(id view))block;

/**
 * Recursively executes a block on this view's subviews (and their subviews, etc.). The block can abort the 
 * recursion and iteration by returning `NO`.
 *
 * @param block The block, which will receive each subview as a parameter.
 */
-(BOOL)subviewsBlockWithAbortSkippingSelf:(BOOL (^)(id view))block;

/**
 * Returns whether or not the view is a subview of the specified view.
 *
 * @param superview The possible superview.
 */
-(BOOL)isSubviewOfView:(NSView*)superview;

#pragma mark -
#pragma mark Superview Operations
/** @name Superview Operations */

/**
 * Executes a block on this view and its superviews.
 *
 * @param block The block, which will receive each view as a parameter.
 */
-(void)superviewBlock:(void (^)(id view))block;

/**
 * Executes a block on this view and its superviews. The block can stop the upward recursion by returning `NO`.
 *
 * @param block The block, which will receive each view as a parameter.
 */
-(BOOL)superviewBlockWithAbort:(BOOL (^)(id view))block;

/**
 * Executes a block on this view's superviews.
 *
 * @param block The block, which will receive each view as a parameter.
 */
-(void)superviewBlockSkippingSelf:(void (^)(id view))block;

/**
 * Executes a block on this view's superviews. The block can stop the upward recursion by returning `NO`.
 *
 * @param block The block, which will receive each view as a parameter.
 */
-(BOOL)superviewBlockWithAbortSkippingSelf:(BOOL (^)(id view))block;

/**
 * Finds a superview of the view with the specified class. If the view is of the specified class, it will be returned.
 *
 * @returns The superview, or `nil` if no superview with that class exists.
 *
 * @param klass The class to find.
 */
-(id)superviewOfClass:(Class)klass;

/**
 * Returns whether or not the view is a superview of the specified view.
 *
 * @param superview The possible superview.
 */
-(BOOL)isSuperviewOfView:(NSView*)subview;

/**
 * Returns an array of the view's superviews, with the immediate superview as the first element.
 */
-(NSArray*)superviews;

#pragma mark -
#pragma mark Hit Testing
/** @name Hit Testing */

/**
 * Performs a hit test, then moves up the subview tree until it finds a view of the specified class. If such a view is
 * not found, returns `nil`.
 *
 * @param point The point to hit test.
 * @param klass The layer class to search for.
 */
-(id)hitTest:(NSPoint)point forClass:(Class)klass;

#pragma mark -
#pragma mark Bitmap Representations
/** @name Bitmap Representations */

/**
 * Returns a cached bitmap image representation for the entire view.
 */
-(NSBitmapImageRep*)cachedBitmapImageRep;

/**
 * Returns a cached bitmap image representation for the specified rect.
 *
 * @param rect The rect to cache.
 */
-(NSBitmapImageRep*)cachedBitmapImageRepForDisplayInRect:(NSRect)rect;

/**
 * Returns a cached image for the entire view.
 */
-(NSImage*)cachedBitmapImage;

/**
 * Returns a cached image for the specified rect.
 *
 * @param rect The rect to cache.
 */
-(NSImage*)cachedBitmapImageForDisplayInRect:(NSRect)rect;

@end

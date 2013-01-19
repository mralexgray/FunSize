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

#import "NSView+FunSize.h"

@implementation NSView (FunSize)

#pragma mark Recursive Subview Operations
-(void)subviewsBlock:(void (^)(id))block
{
    // run the block on the root view
    block(self);
    
    // recurse on the child views
    for (NSView* view in [self subviews])
        [view subviewsBlock:block];
}

-(BOOL)subviewsBlockWithAbort:(BOOL (^)(id))block
{
    if (block(self)) return YES;
    
    for (NSView* view in [self subviews])
        if ([view subviewsBlockWithAbort:block])
            return YES;
    
    return NO;
}

-(void)subviewsBlockSkippingSelf:(void (^)(id))block
{
    for (NSView* view in [self subviews])
    {
        block(view);
        [view subviewsBlockSkippingSelf:block];
    }
}

-(BOOL)subviewsBlockWithAbortSkippingSelf:(BOOL (^)(id))block
{
    for (NSView* view in [self subviews])
    {
        block(view);
        if ([view subviewsBlockWithAbortSkippingSelf:block])
            return YES;
    }
    
    return NO;
}

-(BOOL)isSubviewOfView:(NSView*)superview
{
    for (NSView* view = [self superview]; view != nil; view = [view superview])
        if (view == superview)
            return YES;
    return NO;
}

#pragma mark Superview Operations
-(void)superviewBlock:(void (^)(id))block
{
    for (NSView* view = self; view != nil; view = [view superview])
    {
        block(view);
    }
}

-(BOOL)superviewBlockWithAbort:(BOOL (^)(id))block
{
    for (NSView* view = self; view != nil; view = [view superview])
    {
        if (!block(view)) return YES;
    }
    
    return NO;
}

-(void)superviewBlockSkippingSelf:(void (^)(id))block
{
    for (NSView* view = [self superview]; view != nil; view = [view superview])
    {
        block(view);
    }
}

-(BOOL)superviewBlockWithAbortSkippingSelf:(BOOL (^)(id))block
{
    for (NSView* view = [self superview]; view != nil; view = [view superview])
    {
        if (!block(view)) return YES;
    }
    
    return NO;
}

-(id)superviewOfClass:(Class)klass
{
    for (NSView* view = self; view != nil; view = [view superview])
        if ([view isKindOfClass:klass])
            return view;
    
    return nil;
}

-(BOOL)isSuperviewOfView:(NSView*)subview
{
    for (NSView* view = subview; view != nil; view = [view superview])
        if (view == self)
            return YES;
    return NO;
}

-(NSArray*)superviews
{
    // if the view does not have a superview, return an empty array
    if (![self superview])
        return [NSArray array];
    
    NSMutableArray* array = [NSMutableArray array];
    [self superviewBlockSkippingSelf:^(NSView* view) {
        [array addObject:view];
    }];
    
    return array;
}

#pragma mark Hit Testing
-(id)hitTest:(NSPoint)point forClass:(Class)klass
{
    NSView* view = [self hitTest:point];
    
    while (view != nil && ![view isKindOfClass:klass])
    {
        view = [view superview];
    }
    
    return view;
}

#pragma mark Bitmap Representations
-(NSBitmapImageRep*)cachedBitmapImageRep
{
    return [self cachedBitmapImageRepForDisplayInRect:[self bounds]];
}

-(NSBitmapImageRep*)cachedBitmapImageRepForDisplayInRect:(NSRect)rect
{
    NSBitmapImageRep* rep = [self bitmapImageRepForCachingDisplayInRect:rect];
    [self cacheDisplayInRect:[self bounds] toBitmapImageRep:rep];
    
    return rep;
}

-(NSImage*)cachedBitmapImage
{
    return [self cachedBitmapImageForDisplayInRect:[self bounds]];
}

-(NSImage*)cachedBitmapImageForDisplayInRect:(NSRect)rect
{
    NSBitmapImageRep* rep = [self cachedBitmapImageRepForDisplayInRect:rect];
    NSImage* image = [[[NSImage alloc] initWithSize:rect.size] autorelease];
    [image addRepresentation:rep];
    return image;
}

@end

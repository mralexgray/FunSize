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

#import "NSSet+FunSize.h"

@implementation NSSet (FunSize)

-(BOOL)all:(BOOL(^)(id))block
{
    for (id item in self)
        if (!block(item))
            return NO;
    
    return YES;
}

-(BOOL)any:(BOOL(^)(id))block
{
    for (id item in self)
        if (block(item))
            return YES;
    
    return NO;
}

-(NSArray*)mapToArray:(id(^)(id))mapBlock
{
    NSMutableArray* mapped = [NSMutableArray arrayWithCapacity:[self count]];
    
    for (id item in self)
        [mapped addObject:mapBlock(item)];
    
    return mapped;
}

-(NSSet*)map:(id(^)(id))mapBlock
{
    NSMutableSet* mapped = [NSMutableSet setWithCapacity:[self count]];
    
    for (id item in self)
        [mapped addObject:mapBlock(item)];
    
    return mapped;
}

-(NSDictionary*)mapToDictionary:(id(^)(id))mapBlock
{
    NSMutableDictionary* dict = [NSMutableDictionary dictionaryWithCapacity:[self count]];
    
    for (id item in self)
        [dict setValue:mapBlock(item) forKey:item];
    
    return dict;
}

-(NSArray*)filterToArray:(BOOL(^)(id))filterBlock
{
    NSMutableArray* filtered = [NSMutableArray arrayWithCapacity:[self count]];
    
    for (id item in self)
        if (filterBlock(item))
            [filtered addObject:item];
    
    return filtered;
}

-(NSSet*)filter:(BOOL(^)(id))filterBlock
{
    NSMutableSet* filtered = [NSMutableSet setWithCapacity:[self count]];
    
    for (id item in self)
        if (filterBlock(item))
            [filtered addObject:item];
    
    return filtered;
}
@end

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

#import "NSArray+FunSize.h"

#define NSNULL(obj) (obj == nil ? [NSNull null] : obj)

@implementation NSArray (FunSize)

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

-(NSArray*)map:(id(^)(id))mapBlock
{
    NSMutableArray* mapped = [NSMutableArray arrayWithCapacity:[self count]];
    
    for (id item in self)
        [mapped addObject:NSNULL(mapBlock(item))];
    
    return mapped;
}

-(NSSet*)mapToSet:(id(^)(id))mapBlock
{
    NSMutableSet* mapped = [NSMutableSet setWithCapacity:[self count]];
    
    for (id item in self)
        [mapped addObject:NSNULL(mapBlock(item))];
    
    return mapped;
}

-(NSDictionary*)mapToDictionary:(id(^)(id))mapBlock
{
    NSMutableDictionary* dict = [NSMutableDictionary dictionaryWithCapacity:[self count]];
    
    for (id item in self)
        [dict setValue:NSNULL(mapBlock(item)) forKey:item];
    
    return dict;
}

-(NSDictionary*)mapToDictionaryKeys:(id(^)(id))mapBlock
{
    NSMutableDictionary* dict = [NSMutableDictionary dictionaryWithCapacity:[self count]];
    
    for (id item in self)
        [dict setValue:item forKey:NSNULL(mapBlock(item))];
    
    return dict;
}

-(NSArray*)filter:(BOOL(^)(id))filterBlock
{
    NSMutableArray* filtered = [NSMutableArray arrayWithCapacity:[self count]];
    
    for (id item in self)
        if (filterBlock(item))
            [filtered addObject:item];
    
    return filtered;
}

-(NSSet*)filterToSet:(BOOL(^)(id))filterBlock
{
    NSMutableSet* filtered = [NSMutableSet setWithCapacity:[self count]];
    
    for (id item in self)
        if (filterBlock(item))
            [filtered addObject:item];
    
    return filtered;
}

-(NSArray*)zip:(NSArray*)array
{
    NSMutableArray* zipped = [NSMutableArray arrayWithCapacity:[self count]];
    
    for (NSUInteger i = 0; i < [self count] && i < [array count]; i++)
    {
        [zipped addObject:[NSArray arrayWithObjects:[self objectAtIndex:i], [array objectAtIndex:i], nil]];
    }
    
    return zipped;
}

-(NSArray*)zipWith:(id(^)(id))zipWithBlock
{
    NSMutableArray* zipped = [NSMutableArray arrayWithCapacity:[self count]];
    
    for (id item in self)
    {
        [zipped addObject:[NSArray arrayWithObjects:item, NSNULL(zipWithBlock(item)), nil]];
    }
    
    return zipped;
}

-(NSArray*)subarrayUntil:(BOOL(^)(id))untilBlock
{
    NSMutableArray* subset = [NSMutableArray arrayWithCapacity:[self count]];
    
    for (id item in self)
    {
        if (untilBlock(item)) [subset addObject:item];
        else break;
    }
    
    return subset;
}

-(NSArray*)subarrayFrom:(BOOL(^)(id))fromBlock
{
    NSMutableArray* subset = [NSMutableArray arrayWithCapacity:[self count]];
    
    BOOL adding = NO;
    for (id item in self)
    {
        if (!adding && fromBlock(item))
            adding = YES;
        
        if (adding)
            [subset addObject:item];
    }
    
    return subset;
}

-(NSArray*)reversedArray
{
    NSMutableArray* array = [NSMutableArray arrayWithCapacity:[self count]];
    
    for (id obj in [self reverseObjectEnumerator])
    {
        [array addObject:obj];
    }
    
    return array;
}

-(NSArray*)arrayByRemovingObject:(id)object
{
    NSMutableArray* mutable = [NSMutableArray arrayWithArray:self];
    [mutable removeObject:object];
    return [NSArray arrayWithArray:mutable];
}

-(NSArray*)arrayByRemovingObjectsFromArray:(NSArray*)objects
{
    NSMutableArray* mutable = [NSMutableArray arrayWithArray:self];
    [mutable removeObjectsInArray:objects];
    return [NSArray arrayWithArray:mutable];
}

@end

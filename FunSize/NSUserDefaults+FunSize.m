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

#import "NSUserDefaults+FunSize.h"

@implementation NSUserDefaults (FunSize)

#pragma mark -
#pragma mark Rects
-(NSRect)rectForKey:(NSString*)defaultName
{
    return NSRectFromString([self stringForKey:defaultName]);
}

-(void)setRect:(NSRect)value forKey:(NSString*)defaultName
{
    [self setObject:NSStringFromRect(value) forKey:defaultName];
}

-(CGRect)CGRectForKey:(NSString*)defaultName
{
    return NSRectToCGRect(NSRectFromString([self stringForKey:defaultName]));
}

-(void)setCGRect:(CGRect)value forKey:(NSString*)defaultName
{
    [self setObject:NSStringFromRect(NSRectFromCGRect(value)) forKey:defaultName];
}

#pragma mark -
#pragma mark Points
-(NSPoint)pointForKey:(NSString*)defaultName
{
    return NSPointFromString([self stringForKey:defaultName]);
}

-(void)setPoint:(NSPoint)value forKey:(NSString*)defaultName
{
    [self setObject:NSStringFromPoint(value) forKey:defaultName];
}

-(CGPoint)CGPointForKey:(NSString*)defaultName
{
    return NSPointToCGPoint(NSPointFromString([self stringForKey:defaultName]));
}

-(void)setCGPoint:(CGPoint)value forKey:(NSString*)defaultName
{
    [self setObject:NSStringFromPoint(NSPointFromCGPoint(value)) forKey:defaultName];
}

#pragma mark -
#pragma mark Sizes
-(NSSize)sizeForKey:(NSString*)defaultName
{
    return NSSizeFromString([self stringForKey:defaultName]);
}

-(void)setSize:(NSSize)value forKey:(NSString*)defaultName
{
    [self setObject:NSStringFromSize(value) forKey:defaultName];
}

-(CGSize)CGSizeForKey:(NSString*)defaultName
{
    return NSSizeToCGSize(NSSizeFromString([self stringForKey:defaultName]));
}

-(void)setCGSize:(CGSize)value forKey:(NSString*)defaultName
{
    [self setObject:NSStringFromSize(NSSizeFromCGSize(value)) forKey:defaultName];
}

#pragma mark -
#pragma mark NSRange
-(NSRange)rangeForKey:(NSString*)defaultName
{
    return NSRangeFromString([self stringForKey:defaultName]);
}

-(void)setRange:(NSRange)value forKey:(NSString*)defaultName
{
    [self setObject:NSStringFromRange(value) forKey:defaultName];
}

#pragma mark -
#pragma mark Class-Level Shortcuts
+(NSArray*)arrayForKey:(NSString*)defaultName
{
    return [[self standardUserDefaults] arrayForKey:defaultName];
}

+(BOOL)boolForKey:(NSString*)defaultName
{
    return [[self standardUserDefaults] boolForKey:defaultName];
}

+(NSData*)dataForKey:(NSString*)defaultName
{
    return [[self standardUserDefaults] dataForKey:defaultName];
}

+(NSDictionary*)dictionaryForKey:(NSString*)defaultName
{
    return [[self standardUserDefaults] dictionaryForKey:defaultName];
}

+(float)floatForKey:(NSString*)defaultName;
{
    return [[self standardUserDefaults] floatForKey:defaultName];
}

+(NSInteger)integerForKey:(NSString*)defaultName
{
    return [[self standardUserDefaults] integerForKey:defaultName];
}

+(id)objectForKey:(NSString*)defaultName
{
    return [[self standardUserDefaults] objectForKey:defaultName];
}

+(NSArray*)stringArrayForKey:(NSString*)defaultName
{
    return [[self standardUserDefaults] stringArrayForKey:defaultName];
}

+(NSString*)stringForKey:(NSString*)defaultName
{
    return [[self standardUserDefaults] stringForKey:defaultName];
}

+(double)doubleForKey:(NSString*)defaultName
{
    return [[self standardUserDefaults] doubleForKey:defaultName];
}

+(NSURL*)URLForKey:(NSString*)defaultName
{
    return [[self standardUserDefaults] URLForKey:defaultName];
}


+(void)setBool:(BOOL)value forKey:(NSString*)defaultName
{
    [[self standardUserDefaults] setBool:value forKey:defaultName];
}

+(void)setFloat:(float)value forKey:(NSString*)defaultName
{
    [[self standardUserDefaults] setFloat:value forKey:defaultName];
}

+(void)setInteger:(NSInteger)value forKey:(NSString*)defaultName
{
    [[self standardUserDefaults] setInteger:value forKey:defaultName];
}

+(void)setObject:(id)value forKey:(NSString*)defaultName
{
    [[self standardUserDefaults] setObject:value forKey:defaultName];
}

+(void)setDouble:(double)value forKey:(NSString*)defaultName
{
    [[self standardUserDefaults] setDouble:value forKey:defaultName];
}

+(void)setURL:(NSURL*)url forKey:(NSString*)defaultName
{
    [[self standardUserDefaults] setURL:url forKey:defaultName];
}

#pragma mark -
#pragma mark Class-Level Shortcuts for Rects
+(NSRect)rectForKey:(NSString*)defaultName
{
    return NSRectFromString([[self standardUserDefaults] stringForKey:defaultName]);
}

+(void)setRect:(NSRect)value forKey:(NSString*)defaultName
{
    [[self standardUserDefaults] setObject:NSStringFromRect(value) forKey:defaultName];
}

+(CGRect)CGRectForKey:(NSString*)defaultName
{
    return NSRectToCGRect(NSRectFromString([[self standardUserDefaults] stringForKey:defaultName]));
}

+(void)setCGRect:(CGRect)value forKey:(NSString*)defaultName
{
    [[self standardUserDefaults] setObject:NSStringFromRect(NSRectFromCGRect(value)) forKey:defaultName];
}

#pragma mark -
#pragma mark Class-Level Shortcuts for Points
+(NSPoint)pointForKey:(NSString*)defaultName
{
    return NSPointFromString([[self standardUserDefaults] stringForKey:defaultName]);
}

+(void)setPoint:(NSPoint)value forKey:(NSString*)defaultName
{
    [[self standardUserDefaults] setObject:NSStringFromPoint(value) forKey:defaultName];
}

+(CGPoint)CGPointForKey:(NSString*)defaultName
{
    return NSPointToCGPoint(NSPointFromString([[self standardUserDefaults] stringForKey:defaultName]));
}

+(void)setCGPoint:(CGPoint)value forKey:(NSString*)defaultName
{
    [[self standardUserDefaults] setObject:NSStringFromPoint(NSPointFromCGPoint(value)) forKey:defaultName];
}

#pragma mark -
#pragma mark Class-Level Shortcuts for Sizes
+(NSSize)sizeForKey:(NSString*)defaultName
{
    return NSSizeFromString([[self standardUserDefaults] stringForKey:defaultName]);
}

+(void)setSize:(NSSize)value forKey:(NSString*)defaultName
{
    [[self standardUserDefaults] setObject:NSStringFromSize(value) forKey:defaultName];
}

+(CGSize)CGSizeForKey:(NSString*)defaultName
{
    return NSSizeToCGSize(NSSizeFromString([[self standardUserDefaults] stringForKey:defaultName]));
}

+(void)setCGSize:(CGSize)value forKey:(NSString*)defaultName
{
    [[self standardUserDefaults] setObject:NSStringFromSize(NSSizeFromCGSize(value)) forKey:defaultName];
}

#pragma mark -
#pragma mark Class-Level Shortcuts for NSRange
+(NSRange)rangeForKey:(NSString*)defaultName
{
    return NSRangeFromString([[self standardUserDefaults] stringForKey:defaultName]);
}

+(void)setRange:(NSRange)value forKey:(NSString*)defaultName
{
    [[self standardUserDefaults] setObject:NSStringFromRange(value) forKey:defaultName];
}

@end

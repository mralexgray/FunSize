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

@import ObjectiveC;

#import "NSObject+FunSize.h"

@implementation NSObject (FunSize)

#pragma mark Properties
-(void)iteratePropertiesWithBlock:(void (^)(NSString*))propertyBlock
{
    // get the property list
    unsigned int propertyCount;
    objc_property_t* properties = class_copyPropertyList([self class], &propertyCount);
    
    // iterate over the properties
    for (unsigned int i = 0; i < propertyCount; i++)
    {
        // get the name of the property
        const char* cPropertyName = property_getName(properties[i]);
        NSString* propertyName = [NSString stringWithCString:cPropertyName encoding:[NSString defaultCStringEncoding]];
        
        // execute the block
        propertyBlock(propertyName);
    }
    
    // clean up
    free(properties);
}

#pragma mark Floating Point NSNumber valueForKey:/setValue:forKey:
-(float)floatForKey:(NSString*)key
{
    return [[self valueForKey:key] floatValue];
}

-(void)setFloat:(float)value forKey:(NSString*)key
{
    [self setValue:[NSNumber numberWithFloat:value] forKey:key];
}

-(double)doubleForKey:(NSString*)key
{
    return [[self valueForKey:key] doubleValue];
}

-(void)setDouble:(double)value forKey:(NSString*)key
{
    [self setValue:[NSNumber numberWithDouble:value] forKey:key];
}

#pragma mark Signed NSNumber valueForKey:/setValue:forKey:
-(BOOL)boolForKey:(NSString*)key
{
    return [[self valueForKey:key] boolValue];
}

-(void)setBool:(BOOL)value forKey:(NSString*)key
{
    [self setValue:[NSNumber numberWithBool:value] forKey:key];
}

-(char)charForKey:(NSString*)key
{
    return [[self valueForKey:key] charValue];
}

-(void)setChar:(char)value forKey:(NSString*)key
{
    [self setValue:[NSNumber numberWithChar:value] forKey:key];
}

-(int)intForKey:(NSString*)key
{
    return [[self valueForKey:key] intValue];
}

-(void)setInt:(int)value forKey:(NSString*)key
{
    [self setValue:[NSNumber numberWithInt:value] forKey:key];
}

-(long)longForKey:(NSString*)key
{
    return [[self valueForKey:key] longValue];
}

-(void)setLong:(long)value forKey:(NSString*)key
{
    [self setValue:[NSNumber numberWithLong:value] forKey:key];
}

-(long long)longLongForKey:(NSString*)key
{
    return [[self valueForKey:key] longLongValue];
}

-(void)setLongLong:(long long)value forKey:(NSString*)key
{
    [self setValue:[NSNumber numberWithLongLong:value] forKey:key];
}

-(NSInteger)integerForKey:(NSString*)key
{
    return [[self valueForKey:key] integerValue];
}

-(void)setInteger:(NSInteger)value forKey:(NSString*)key
{
    [self setValue:[NSNumber numberWithInteger:value] forKey:key];
}

#pragma mark Unsigned NSNumber valueForKey:/setValue:forKey:
-(unsigned char)unsignedCharForKey:(NSString*)key
{
    return [[self valueForKey:key] unsignedCharValue];
}

-(void)setUnsignedChar:(unsigned char)value forKey:(NSString*)key;
{
    [self setValue:[NSNumber numberWithUnsignedChar:value] forKey:key];
}

-(unsigned short)unsignedShortForKey:(NSString*)key
{
    return [[self valueForKey:key] unsignedShortValue];
}

-(void)setUnsignedShort:(unsigned short)value forKey:(NSString*)key;
{
    [self setValue:[NSNumber numberWithUnsignedShort:value] forKey:key];
}

-(unsigned int)unsignedIntForKey:(NSString*)key
{
    return [[self valueForKey:key] unsignedIntValue];
}

-(void)setUnsignedInt:(unsigned int)value forKey:(NSString*)key;
{
    [self setValue:[NSNumber numberWithUnsignedInt:value] forKey:key];
}

-(NSUInteger)unsignedIntegerForKey:(NSString*)key
{
    return [[self valueForKey:key] unsignedIntegerValue];
}

-(void)setUnsignedInteger:(NSUInteger)value forKey:(NSString*)key
{
    [self setValue:[NSNumber numberWithUnsignedInteger:value] forKey:key];
}

-(unsigned long)unsignedLongForKey:(NSString*)key
{
    return [[self valueForKey:key] unsignedLongValue];
}

-(void)setUnsignedLong:(unsigned long)value forKey:(NSString*)key;
{
    [self setValue:[NSNumber numberWithUnsignedLong:value] forKey:key];
}

-(unsigned long long)unsignedLongLongForKey:(NSString*)key
{
    return [[self valueForKey:key] unsignedLongLongValue];
}

-(void)setUnsignedLongLong:(unsigned long long)value forKey:(NSString*)key;
{
    [self setValue:[NSNumber numberWithUnsignedLongLong:value] forKey:key];
}

#pragma mark NSValue valueForKey:/setValue:forKey:

-(CGSize)sizeForKey:(NSString*)key
{
    return [[self valueForKey:key] CGSizeValue];
}

-(void)setSize:(CGSize)value forKey:(NSString*)key
{
    [self setValue:[NSValue valueWithCGSize:value] forKey:key];
}

-(NSRange)rangeForKey:(NSString*)key
{
    return [[self valueForKey:key] rangeValue];
}

-(void)setRange:(NSRange)value forKey:(NSString*)key
{
    [self setValue:[NSValue valueWithRange:value] forKey:key];
}

-(CGRect)rectForKey:(NSString*)key
{
    return [[self valueForKey:key] CGRectValue];
}

-(void)setRect:(CGRect)value forKey:(NSString*)key
{
    [self setValue:[NSValue valueWithCGRect:value] forKey:key];
}

-(CGPoint)pointForKey:(NSString*)key
{
    return [[self valueForKey:key] CGPointValue];
}

-(void)setPoint:(CGPoint)value forKey:(NSString*)key
{
    [self setValue:[NSValue valueWithCGPoint:value] forKey:key];
}

-(CATransform3D)CATransform3DForKey:(NSString*)key
{
    return [[self valueForKey:key] CATransform3DValue];
}

-(void)setCATransform3D:(CATransform3D)value forKey:(NSString*)key
{
    [self setValue:[NSValue valueWithCATransform3D:value] forKey:key];
}

#pragma mark Floating Point NSNumber valueForKeyPath:/setValue:forKeyPath:
-(float)floatForKeyPath:(NSString*)key
{
    return [[self valueForKeyPath:key] floatValue];
}

-(void)setFloat:(float)value forKeyPath:(NSString*)key
{
    [self setValue:[NSNumber numberWithFloat:value] forKeyPath:key];
}

-(double)doubleForKeyPath:(NSString*)key
{
    return [[self valueForKeyPath:key] doubleValue];
}

-(void)setDouble:(double)value forKeyPath:(NSString*)key
{
    [self setValue:[NSNumber numberWithDouble:value] forKeyPath:key];
}

#pragma mark Signed NSNumber valueForKeyPath:/setValue:forKeyPath:
-(BOOL)boolForKeyPath:(NSString*)key
{
    return [[self valueForKeyPath:key] boolValue];
}

-(void)setBool:(BOOL)value forKeyPath:(NSString*)key
{
    [self setValue:[NSNumber numberWithBool:value] forKeyPath:key];
}

-(char)charForKeyPath:(NSString*)key
{
    return [[self valueForKeyPath:key] charValue];
}

-(void)setChar:(char)value forKeyPath:(NSString*)key
{
    [self setValue:[NSNumber numberWithChar:value] forKeyPath:key];
}

-(int)intForKeyPath:(NSString*)key
{
    return [[self valueForKeyPath:key] intValue];
}

-(void)setInt:(int)value forKeyPath:(NSString*)key
{
    [self setValue:[NSNumber numberWithInt:value] forKeyPath:key];
}

-(long)longForKeyPath:(NSString*)key
{
    return [[self valueForKeyPath:key] longValue];
}

-(void)setLong:(long)value forKeyPath:(NSString*)key
{
    [self setValue:[NSNumber numberWithLong:value] forKeyPath:key];
}

-(long long)longLongForKeyPath:(NSString*)key
{
    return [[self valueForKeyPath:key] longLongValue];
}

-(void)setLongLong:(long long)value forKeyPath:(NSString*)key
{
    [self setValue:[NSNumber numberWithLongLong:value] forKeyPath:key];
}

-(NSInteger)integerForKeyPath:(NSString*)key
{
    return [[self valueForKeyPath:key] integerValue];
}

-(void)setInteger:(NSInteger)value forKeyPath:(NSString*)key
{
    [self setValue:[NSNumber numberWithInteger:value] forKeyPath:key];
}

#pragma mark Unsigned NSNumber valueForKeyPath:/setValue:forKeyPath:
-(unsigned char)unsignedCharForKeyPath:(NSString*)key
{
    return [[self valueForKeyPath:key] unsignedCharValue];
}

-(void)setUnsignedChar:(unsigned char)value forKeyPath:(NSString*)key;
{
    [self setValue:[NSNumber numberWithUnsignedChar:value] forKeyPath:key];
}

-(unsigned short)unsignedShortForKeyPath:(NSString*)key
{
    return [[self valueForKeyPath:key] unsignedShortValue];
}

-(void)setUnsignedShort:(unsigned short)value forKeyPath:(NSString*)key;
{
    [self setValue:[NSNumber numberWithUnsignedShort:value] forKeyPath:key];
}

-(unsigned int)unsignedIntForKeyPath:(NSString*)key
{
    return [[self valueForKeyPath:key] unsignedIntValue];
}

-(void)setUnsignedInt:(unsigned int)value forKeyPath:(NSString*)key;
{
    [self setValue:[NSNumber numberWithUnsignedInt:value] forKeyPath:key];
}

-(NSUInteger)unsignedIntegerForKeyPath:(NSString*)key
{
    return [[self valueForKeyPath:key] unsignedIntegerValue];
}

-(void)setUnsignedInteger:(NSUInteger)value forKeyPath:(NSString*)key
{
    [self setValue:[NSNumber numberWithUnsignedInteger:value] forKeyPath:key];
}

-(unsigned long)unsignedLongForKeyPath:(NSString*)key
{
    return [[self valueForKeyPath:key] unsignedLongValue];
}

-(void)setUnsignedLong:(unsigned long)value forKeyPath:(NSString*)key;
{
    [self setValue:[NSNumber numberWithUnsignedLong:value] forKeyPath:key];
}

-(unsigned long long)unsignedLongLongForKeyPath:(NSString*)key
{
    return [[self valueForKeyPath:key] unsignedLongLongValue];
}

-(void)setUnsignedLongLong:(unsigned long long)value forKeyPath:(NSString*)key;
{
    [self setValue:[NSNumber numberWithUnsignedLongLong:value] forKeyPath:key];
}

#pragma mark NSValue valueForKeyPath:/setValue:forKeyPath:
-(CGSize)sizeForKeyPath:(NSString*)key
{
    return [[self valueForKeyPath:key] CGSizeValue];
}

-(void)setSize:(CGSize)value forKeyPath:(NSString*)key
{
    [self setValue:[NSValue valueWithCGSize:value] forKeyPath:key];
}

-(NSRange)rangeForKeyPath:(NSString*)key
{
    return [[self valueForKeyPath:key] rangeValue];
}

-(void)setRange:(NSRange)value forKeyPath:(NSString*)key
{
    [self setValue:[NSValue valueWithRange:value] forKeyPath:key];
}

-(CGRect)rectForKeyPath:(NSString*)key
{
    return [[self valueForKeyPath:key] CGRectValue];
}

-(void)setRect:(CGRect)value forKeyPath:(NSString*)key
{
    [self setValue:[NSValue valueWithCGRect:value] forKeyPath:key];
}

-(CGPoint)pointForKeyPath:(NSString*)key
{
    return [[self valueForKeyPath:key] CGPointValue];
}

-(void)setPoint:(CGPoint)value forKeyPath:(NSString*)key
{
    [self setValue:[NSValue valueWithCGPoint:value] forKeyPath:key];
}

-(CATransform3D)CATransform3DForKeyPath:(NSString*)key
{
    return [[self valueForKeyPath:key] CATransform3DValue];
}

-(void)setCATransform3D:(CATransform3D)value forKeyPath:(NSString*)key
{
    [self setValue:[NSValue valueWithCATransform3D:value] forKeyPath:key];
}

@end

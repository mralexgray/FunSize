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

#import <Cocoa/Cocoa.h>

@interface NSArray (FunSize)

/**
 * Passes each element to the block, and returns `YES` if the block returns `YES` for all elements.
 *
 * @param block A block, which will receive each element as a parameter.
 */
-(BOOL)all:(BOOL(^)(id object))block;

/**
 * Passes each element to the block, and returns `YES` if the block returns `YES` for any element.
 *
 * @param block A block, which will receive elements as a parameter until it returns `YES` (or the elements are
 * exhausted).
 */
-(BOOL)any:(BOOL(^)(id object))block;

/**
 * Returns an array of mapped values.
 * 
 * @param mapBlock A block to map with. The block will receive each element of
 * the array, and should return a mapped value to be inserted into the returned
 * array.
 */
-(NSArray*)map:(id(^)(id object))mapBlock;

/**
 * Returns an set of mapped values.
 * 
 * @param mapBlock A block to map with. The block will receive each element of
 * the array, and should return a mapped value to be inserted into the returned
 * set.
 */
-(NSSet*)mapToSet:(id(^)(id object))mapBlock;

/**
 * Similar to `map:`, but instead returns a dictionary, where the elements of
 * this array are the keys and the mapped values are the values.
 * 
 * @param mapBlock A block to map with. The block will receive each element of
 * the array, and should return a mapped value to be inserted into the returned dictionary.
 */
-(NSDictionary*)mapToDictionary:(id(^)(id object))mapBlock;

/**
 * Similar to `mapToDictionary:`, except the values of the array are used as the values of the dictionary, while
 * the mapped values are used as keys.
 * 
 * @param mapBlock A block to map with. The block will receive each element of
 * the array, and should return a mapped value to be used as a key in the resulting dictionary.
 */
-(NSDictionary*)mapToDictionaryKeys:(id(^)(id object))mapBlock;

/**
 * Filters an array, returning an array with the filtered contents.
 * 
 * @param filterBlock A block to filter with. The block will receive each
 * element of this array, and should return `YES` if the element should be
 * included in the filtered array, and `NO` if it should not.
 */
-(NSArray*)filter:(BOOL(^)(id object))filterBlock;

/**
 * Filters an array, returning a set with the filtered contents.
 * 
 * @param filterBlock A block to filter with. The block will receive each
 * element of this array, and should return `YES` if the element should be
 * included in the filtered set, and `NO` if it should not.
 */
-(NSSet*)filterToSet:(BOOL(^)(id object))filterBlock;

/**
 * Produces an array of two-element arrays from the array the message is sent
 * to and the parameter.
 * 
 * @param array The array to zip with this array.
 */
-(NSArray*)zip:(NSArray*)array;

/**
 * Similar to zip:, but uses a block instead of a second array to produce
 * the second value of each pair.
 * 
 * @param zipWithBlock A block, which will receive each element of this array.
 */
-(NSArray*)zipWith:(id(^)(id object))zipWithBlock;

/**
 * Returns a subset of this array from the start until the block returns `NO`.
 * 
 * @param untilBlock A block, which will receive elements of the array until
 * it returns `NO`, at which point the subset will end.
 */
-(NSArray*)subarrayUntil:(BOOL(^)(id object))untilBlock;

/**
 * Returns a subset of this array from the element where the block returns `YES`
 * until the last element of the array.
 * 
 * @param fromBlock A block, which will receive elements of the array until it
 * returns `YES`, at which point the subset will start.
 */
-(NSArray*)subarrayFrom:(BOOL(^)(id object))fromBlock;

/**
 * Returns an reversed array.
 */
-(NSArray*)reversedArray;

@end

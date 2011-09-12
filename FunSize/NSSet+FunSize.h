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

#import <Foundation/Foundation.h>

@interface NSSet (FunSize)

/**
 * Passes each element to the block, and returns `YES` if the block returns `YES` for all elements.
 *
 * @param block A block, which will receive each element as a parameter.
 */
-(BOOL)all:(BOOL(^)(id))block;

/**
 * Passes each element to the block, and returns `YES` if the block returns `YES` for any element.
 *
 * @param block A block, which will receive elements as a parameter until it returns `YES` (or the elements are
 * exhausted).
 */
-(BOOL)any:(BOOL(^)(id))block;

/**
 * Returns an set of mapped values.
 * 
 * @param mapBlock A block to map with. The block will receive each element of
 * the set, and should return a mapped value to be inserted into the returned set.
 */
-(NSSet*)map:(id(^)(id))mapBlock;

/**
 * Returns an array of mapped values.
 * 
 * @param mapBlock A block to map with. The block will receive each element of
 * the set, and should return a mapped value to be inserted into the returned array.
 */
-(NSArray*)mapToArray:(id(^)(id))mapBlock;

/**
 * Similar to map:, but instead returns a dictionary, where the elements of
 * this set are the keys and the mapped values are the values.
 * 
 * @param mapBlock A block to map with. The block will receive each element of
 * the set, and should return a mapped value to be inserted into the returned dictionary.
 */
-(NSDictionary*)mapToDictionary:(id(^)(id))mapBlock;

/**
 * Filters a set, returning an set with the filtered contents.
 * 
 * @param filterBlock A block to filter with. The block will receive each
 * element of this set, and should return `YES` if the element should be
 * included in the filtered set, and `NO` if it should not.
 */
-(NSSet*)filter:(BOOL(^)(id))filterBlock;

/**
 * Filters a set, returning a set with the filtered contents.
 * 
 * @param filterBlock A block to filter with. The block will receive each
 * element of this set, and should return `YES` if the element should be
 * included in the filtered array, and `NO` if it should not.
 */
-(NSArray*)filterToArray:(BOOL(^)(id))filterBlock;

@end

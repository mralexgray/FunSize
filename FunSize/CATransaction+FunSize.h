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

#import <Quartz/Quartz.h>

@interface CATransaction (FunSize)

/**	Performs the block, giving implicit animations the specified length.
 *
 * @param length The length of implicit animations.
 * @param block A block to wrap in a transaction.	*/
+(void)transactionWithLength:(NSTimeInterval)length actions:(void (^)())block;

/**	Performs the block, giving implicit animations the specified length and easing.
 *
 * @param length The length of implicit animations.
 * @param ease The easing function, which may be either an instance of `CAMediaTimingFunction` or one of the constant
 * strings.
 * @param block A block to wrap in a transaction.	*/
+(void)transactionWithLength:(NSTimeInterval)length easing:(id)ease actions:(void (^)())block;

/**	Performs the block with implicit animations disabled.
 *
 * @param block A block to wrap in a transaction.	*/
+(void)immediately:(void (^)())block;

@end

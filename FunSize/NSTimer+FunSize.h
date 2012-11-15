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

@interface NSTimer (FunSize)

#pragma mark Block Timers
/** Block Timers */

/**
 * Schedules a timer to execute a block at a specified interval.
 * 
 * @param interval The length of the timer.
 * @param yesOrNo Whether or not the timer should repeat.
 * @param block The block to execute when the timer completes.
 */
+(NSTimer*)scheduledTimerWithTimeInterval:(NSTimeInterval)interval repeats:(BOOL)yesOrNo block:(void (^)())block;

/**
 * Creates a timer that will execute a block at a specified interval.
 * 
 * @param interval The length of the timer.
 * @param yesOrNo Whether or not the timer should repeat.
 * @param block The block to execute when the timer completes.
 */
+(NSTimer*)timerWithTimeInterval:(NSTimeInterval)interval repeats:(BOOL)yesOrNo block:(void (^)())block;

@end

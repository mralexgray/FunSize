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

#import <Quartz/Quartz.h>

@interface CAKeyframeAnimation (FunSize)

/**
 * Returns an animation with _count_ keyframes. The block will be sent values from 0 to 1, and should return the
 * desired value for that point of the animation.
 *
 * @param count The number of keyframes.
 * @param block A block to construct and return each keyframe value.
 */
+(CAKeyframeAnimation*)animationWithKeyframes:(NSUInteger)count function:(id (^)(double fraction))block;

/**
 * Returns an animation with _count_ keyframes. The block will be sent values from 0 to 1, and should return the
 * desired value for that point of the animation.
 *
 * @param count The number of keyframes.
 * @param block A block to construct and return each keyframe value.
 */
+(CAKeyframeAnimation*)animationWithKeyframes:(NSUInteger)count doubleFunction:(double (^)(double fraction))block;

/**
 * Returns an animation with _count_ keyframes. The block will be sent values from 0 to 1, and should return the
 * desired value for that point of the animation.
 *
 * @param count The number of keyframes.
 * @param block A block to construct and return each keyframe value.
 */
+(CAKeyframeAnimation*)animationWithKeyframes:(NSUInteger)count rectFunction:(CGRect (^)(double fraction))block;

/**
 * Returns an animation with _count_ keyframes. The block will be sent values from 0 to 1, and should return the
 * desired value for that point of the animation.
 *
 * @param count The number of keyframes.
 * @param block A block to construct and return each keyframe value.
 */
+(CAKeyframeAnimation*)animationWithKeyframes:(NSUInteger)count
                            transformFunction:(CATransform3D (^)(double fraction))block;

@end

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

#import "NSTimer+FunSize.h"

typedef void (^FSTimerBlock)();

#pragma mark Block Timer Storage Helper
@interface FSTimerAdditionsHelper : NSObject
{
    FSTimerBlock block;
}

-(id)initWithBlock:(void (^)())timerBlock;
-(void)blockTimerCompleted:(NSTimer*)timer;

@end

@implementation FSTimerAdditionsHelper

-(id)initWithBlock:(void (^)())timerBlock
{
    self = [super init];
    if (self) block = Block_copy(timerBlock);
    return self;
}

-(void)blockTimerCompleted:(NSTimer*)timer
{
    block();
}

-(void)dealloc
{
    Block_release(block);
    [super dealloc];
}

-(void)finalize
{
    Block_release(block);
    [super finalize];
}

@end

@implementation NSTimer (FunSize)

+(NSTimer*)scheduledTimerWithTimeInterval:(NSTimeInterval)interval repeats:(BOOL)yesOrNo block:(void (^)())block
{
    FSTimerAdditionsHelper* helper = [[FSTimerAdditionsHelper alloc] initWithBlock:block];
    
    NSTimer* timer = [NSTimer scheduledTimerWithTimeInterval:interval
                                                      target:helper
                                                    selector:@selector(blockTimerCompleted:)
                                                    userInfo:nil
                                                     repeats:yesOrNo];
    
    [helper release];
    
    return timer;
}

+(NSTimer*)timerWithTimeInterval:(NSTimeInterval)interval repeats:(BOOL)yesOrNo block:(void (^)())block
{
    FSTimerAdditionsHelper* helper = [[FSTimerAdditionsHelper alloc] initWithBlock:block];
    
    NSTimer* timer = [NSTimer timerWithTimeInterval:interval
                                             target:helper
                                           selector:@selector(blockTimerCompleted:)
                                           userInfo:nil
                                            repeats:yesOrNo];
    [helper release];
    
    return timer;
}

@end

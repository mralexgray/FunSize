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

@import Foundation;

#if TARGET_OS_IPHONE
  #define NSSize CGSize
  #define NSRect CGRect
  #define NSPoint CGPoint

  @import UIKit;
  @import CoreText;

#else

  #define valueWithCGRect valueWithRect
  #define valueWithCGSize valueWithSize
  #define valueWithCGPoint valueWithPoint

  #define CGSizeValue sizeValue
  #define CGRectValue rectValue
  #define CGPointValue pointValue

  #define CGRectFromString NSRectFromString
  #define CGPointFromString NSPointFromString


  #define NSStringFromCGRect NSStringFromRect
  #define NSStringFromCGPoint NSStringFromPoint

  #define NSStringFromCGSize NSStringFromSize
  #define CGSizeFromString NSSizeFromString
  
  @import AppKit;

#endif

#import "CABasicAnimation+FunSize.h"
#import "CAKeyframeAnimation+FunSize.h"
#import "CALayer+FunSize.h"
#import "CAMediaTimingFunction+FunSize.h"
#import "CATransaction+FunSize.h"

#import "NSArray+FunSize.h"
#import "NSAttributedString+FunSize.h"
#import "NSBezierPath+FunSize.h"
#import "NSColor+FunSize.h"
#import "NSDictionary+FunSize.h"
#import "NSEvent+FunSize.h"
#import "NSGradient+FunSize.h"
#import "NSGraphicsContext+FunSize.h"
#import "NSImage+FunSize.h"
#import "NSMutableArray+FunSize.h"
#import "NSNotificationCenter+FunSize.h"
#import "NSNumber+FunSize.h"
#import "NSObject+FunSize.h"
#import "NSSet+FunSize.h"
#import "NSShadow+FunSize.h"
#import "NSString+FunSize.h"
#import "NSTextField+FunSize.h"
#import "NSTimer+FunSize.h"
#import "NSURL+FunSize.h"
#import "NSUserDefaults+FunSize.h"
#import "NSView+FunSize.h"

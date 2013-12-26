//
// Copyright (C) 2013 by Martin Johannesson
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
// (MIT License)
//

#import <Foundation/Foundation.h>
#import "MJServiceContainer.h"

/**
 * Default example implementation of the MJServiceContainer protocol.
 *
 * Either add services to an instance of this object, or inherit from
 * it and override the createServices method.
 */
@interface MJServices : NSObject <MJServiceContainer>

/**
 * Add an instance of a service object for the given protocol.
 */
- (void)addService:(id)service forProtocol:(Protocol *)serviceProtocol;

/**
 * Add an instance of a service object for the given protocol and qualifier.
 */
- (void)addService:(id)service
       forProtocol:(Protocol *)serviceProtocol
         qualifier:(NSString *)qualifier;

/**
 * Add an instance of a service object for all protocols that it implements.
 *
 * NOTE: This method does NOT add protocols of parent classes.
 */
- (void)addServiceForAllImplementedProtocols:(id)service;

/**
 * Override this method to add services from a subclass.
 * It is called from the init method.
 */
- (void)createServices;

@end

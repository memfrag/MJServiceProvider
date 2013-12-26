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

/**
 * Classes that implement the MJServiceContainer protocol are expected to
 * provide the services requested by the MJServiceProvider singleton object.
 * The services are app wide services that would otherwise typically be
 * implemented as singletons.
 */
@protocol MJServiceContainer <NSObject>

/**
 * Return a service that implements the specified protocol.
 *
 * The service may have been previously instantiated or could be
 * instantiated on the fly, depening on the service.
 *
 * @param serviceProtocol The protocol to get the corresponding service for.
 * @return An initialized service that implements the specified protocol.
 */
- (id)serviceForProtocol:(Protocol *)serviceProtocol;

/**
 * Return a service that implements the specified protocol.
 *
 * The service may have been previously instantiated or could be
 * instantiated on the fly, depening on the service.
 *
 * If more than one service of a certain protocol is required, then
 * an additional qualifier can be specified for discerning between the
 * the services.
 *
 * @param serviceProtocol The protocol to get the corresponding service for.
 * @return An initialized service that implements the specified protocol.
 */
- (id)serviceForProtocol:(Protocol *)serviceProtocol
               qualifier:(NSString *)qualifier;

@end

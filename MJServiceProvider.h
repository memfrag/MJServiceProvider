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
 * Return a service that implements the specified protocol.
 *
 * The service may have been previously instantiated or could be
 * instantiated on the fly, depening on the service.
 *
 * @param serviceProtocol The protocol to get the corresponding service for.
 * @return An initialized service that implements the specified protocol.
 */
id MJServiceForProtocol(Protocol *serviceProtocol);

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
id MJServiceForProtocolWithQualifier(Protocol *serviceProtocol,
                                     NSString *qualifier);

/**
 * The MJServiceProvider is a singleton object that aspires to be the only
 * singleton object in the app. Given a protocol (and an optional qualifier)
 * the service provider will request an instance of an object implementing
 * that protocol from a preconfigured service container and then return it
 * to the caller.
 */
@interface MJServiceProvider : NSObject

/**
 * Sets the service container to request services from.
 */
+ (void)setServiceContainer:(id<MJServiceContainer>)serviceContainer;

@end

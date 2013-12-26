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

#import "MJServices.h"
#import <objc/runtime.h>

#define MJ_APP_SERVICE_KEY(p) NSStringFromProtocol((p))
#define MJ_APP_SERVICE_QUALIFIED_KEY(p, q) [NSString stringWithFormat:@"%@/%@",\
                                            NSStringFromProtocol((p)), (q)]

@interface MJServices ()

@property (nonatomic, strong) NSMutableDictionary *services;

@end


@implementation MJServices

- (id)init
{
    self = [super init];
    if (self) {
        _services = [NSMutableDictionary dictionary];
        [self createServices];
    }
    return self;
}

- (void)addService:(id)service forProtocol:(Protocol *)serviceProtocol
{
    _services[MJ_APP_SERVICE_KEY(serviceProtocol)] = service;
}

- (void)addService:(id)service
       forProtocol:(Protocol *)serviceProtocol
         qualifier:(NSString *)qualifier
{
    _services[MJ_APP_SERVICE_QUALIFIED_KEY(serviceProtocol, qualifier)] = service;
}

/**
 * This method does NOT add protocols of parent classes.
*/
- (void)addServiceForAllImplementedProtocols:(id)service
{
    Class cls = [service class];
    unsigned int count;
    Protocol * __unsafe_unretained *protocols = class_copyProtocolList(cls, &count);
    
    for (unsigned i = 0; i < count; i++) {
        [self addService:service forProtocol:protocols[i]];
    }
    
    free(protocols);
}

- (id)serviceForProtocol:(Protocol *)serviceProtocol
{
    return _services[MJ_APP_SERVICE_KEY(serviceProtocol)];
}

- (id)serviceForProtocol:(Protocol *)serviceProtocol
               qualifier:(NSString *)qualifier
{
    return _services[MJ_APP_SERVICE_QUALIFIED_KEY(serviceProtocol, qualifier)];
}

#pragma mark - Services Setup

- (void)createServices
{
    // Init services and add them to the services dictionary here.
    // [self addService:... forProtocol:@protocol(...) qualifier:@"..."];
}

@end

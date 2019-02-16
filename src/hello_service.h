#ifndef _HELLO_SERVICE_H_
#define _HELLO_SERVICE_H_

#include "service_base.h"

class HelloService : public ServiceBase {
public:
    HelloService() {}
    virtual ~HelloService() {}

public:
    int handle(std::shared_ptr<Context> context) override;
};

#endif

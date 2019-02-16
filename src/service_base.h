#ifndef _SERVICE_BASE_H_
#define _SERVICE_BASE_H_

#include <string>
#include <memory>
#include "context.h"

class ServiceBase {
public:
    ServiceBase() {};
    virtual ~ServiceBase() {};
    ServiceBase(const ServiceBase &) = delete;
    ServiceBase& operator=(const ServiceBase &) = delete;

public:
    virtual int handle(std::shared_ptr<Context> context) = 0;
};

#endif

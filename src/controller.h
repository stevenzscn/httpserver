#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include <string>
#include <memory>
#include "context.h"

class Controller {
public:
    Controller() {}
    virtual ~Controller() {}
    Controller(const Controller &) = delete;
    Controller& operator=(const Controller &) = delete;

public:
    int control(std::shared_ptr<Context> context) const;
};

#endif

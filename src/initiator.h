#ifndef _INITIATOR_H_
#define _INITIATOR_H_

#include "http_server.h"
#include <memory>

class Initiator {
public:
    Initiator() {};
    virtual ~Initiator() {};
    Initiator(const Initiator &) = delete;
    Initiator& operator=(const Initiator &) = delete;

public:
    int initialize();
    int run();

private:
    int init_server();

private:
    std::shared_ptr<HttpServer> server_;
};

#endif

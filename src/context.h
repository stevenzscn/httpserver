#ifndef _CONTEXT_H_
#define _CONTEXT_H_

#include <string>
#include <iostream>
#include "common.h"

class Context final {
public:
    Context() {}
    Context(const Context &) = delete;
    Context & operator=(const Context &) = delete;
    virtual ~Context() {}

public:
    std::string uri_;
    std::string ua_;
    std::string real_ip_;
    std::string content_type_;

    std::string req_body_;
    std::string res_body_;
};

#endif

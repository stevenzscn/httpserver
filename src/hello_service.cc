#include "hello_service.h"
#include "common.h"
#include <iostream>
#include <sstream>

int HelloService::handle(std::shared_ptr<Context> context) {
    std::stringstream ss;
    ss << "uri:"
       << context->uri_
       << "\n"
       << "Content:\n"
       << context->req_body_;

    context->res_body_ = ss.str();

    return RC_OK;
}

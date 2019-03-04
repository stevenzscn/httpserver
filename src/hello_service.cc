#include "hello_service.h"
#include "common.h"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <sstream>

int HelloService::handle(std::shared_ptr<Context> context) {
    
    boost::property_tree::ptree hello;
    hello.put("uri", context->uri_);
    hello.put("content", context->req_body_);

    std::stringstream ss;
    boost::property_tree::json_parser::write_json(ss, hello);

    context->content_type_ = "application/json";
    context->res_body_ = ss.str();

    return RC_OK;
}

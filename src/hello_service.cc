#include "hello_service.h"
#include "common.h"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <sstream>

int HelloService::handle(std::shared_ptr<Context> context) {
    
    boost::property_tree::ptree hello_res;
    hello_res.put("uri", context->uri_);
    hello_res.put("content", context->req_body_);

    std::stringstream ss;
    boost::property_tree::json_parser::write_json(ss, hello_res);

    context->content_type_ = "application/json";
    context->res_body_ = ss.str();

    return RC_OK;
}

#include "initiator.h"
#include "common.h"
#include "utils.h"
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>

int Initiator::initialize() {
    int ret = RC_ERROR;
    
    ret = init_server();
    if (ret != RC_OK) {
        return ret;
    }

    return ret;
}

int Initiator::run() {
    int ret = RC_ERROR;

    if (server_) {
        ret = server_->start();
        if (ret != RC_OK) {
            return ret;
        }
    }

    return ret;
}

int Initiator::init_server() {
    server_ = std::make_shared<HttpServer>();
    int ret = server_->init();
    if (ret != RC_OK) {
        return ret;
    }

    return ret;
}


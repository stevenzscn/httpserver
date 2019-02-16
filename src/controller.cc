#include "controller.h"
#include "common.h"
#include "service_base.h"
#include "hello_service.h"

int Controller::control(std::shared_ptr<Context> context) const {
    const std::string HANDLE_HELLO = "/hello";
    if (context->uri_.compare(0, HANDLE_HELLO.length(), HANDLE_HELLO) == 0) {
        HelloService hello;
        std::string out_res;
        return hello.handle(context);
    } else {
        return RC_CTL_NOT_FOUND;
    }

    return RC_OK;
}

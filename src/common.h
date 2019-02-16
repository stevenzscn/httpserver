#ifndef _COMMON_H_
#define _COMMON_H_

#include <string>

enum ReturnCode {
    RC_OK = 0,
    RC_ERROR = -1,

    RC_INIT_ERROR = 1,
    RC_CONF_ERROR = 2,
    RC_FILE_ERROR = 3,
    RC_LOG_ERROR = 4,
    RC_REDIS_ERROR = 5,

    RC_CTL_NOT_FOUND = 404,
};

#endif

#ifndef _CONFIGURE_H_
#define _CONFIGURE_H_

#include <string>

class Configure {
public:
    Configure(const std::string& conf_path) : conf_path_(conf_path) {}
    Configure() {}
    virtual ~Configure() {}

public:
    void set_conf_path(const std::string& conf_path) { conf_path_ = conf_path; }
    int init();

private:
    std::string conf_path_;
};

#endif

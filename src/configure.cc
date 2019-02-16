#include "configure.h"
#include "common.h"
#include "utils.h"
#include "config_file.h"

#include <fstream>

int Configure::init() {
    std::ifstream conf_file(conf_path_);
    if (!conf_file)
        return RC_FILE_ERROR;

    conf_file >> utils::G<ConfigFile>(); 
    conf_file.close();

    return RC_OK;
}

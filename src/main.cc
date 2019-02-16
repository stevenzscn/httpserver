#include "initiator.h"

#include <stdlib.h>
#include <getopt.h>
#include <unistd.h>
#include <string>

static std::string conf_path;
static bool daemon_flag = false;
static int option_index = 0;
static struct option long_options[] = {
    {"daemon", 0, NULL, 'd'},
    {0, 0, 0, 0}
};

int main(int argc, char* argv[])
{
    char opt = 0;
    while ((opt = getopt_long(argc, argv, "c:",
                    long_options, &option_index)) != -1) {
        switch (opt) {
            case 'd':
                daemon_flag = true;
                break;
            case 'c':
                conf_path = optarg;
                break;
            default:
                continue;
        }
    }

    std::shared_ptr<Initiator> initiator(new Initiator());
    initiator->initialize();

    if (daemon_flag) {
        daemon(1, 0);
    }

    initiator->run();

    return EXIT_SUCCESS;
}


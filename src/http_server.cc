#include "http_server.h"
#include "common.h"
#include "utils.h"

using tcp = boost::asio::ip::tcp;       // from <boost/asio/ip/tcp.hpp>
namespace http = boost::beast::http;    // from <boost/beast/http.hpp>


int HttpServer::init() {
    address_ = boost::asio::ip::make_address("0.0.0.0");
    port_ = 9999;
    threads_ = 4;
    doc_root_ = std::make_shared<std::string>(".");

    return RC_OK;
}

int HttpServer::start() {
    // The io_context is required for all I/O
    boost::asio::io_context ioc{threads_};

    // Create and launch a listening port
    std::make_shared<listener>(
            ioc,
            tcp::endpoint{address_, port_},
            doc_root_)->run();

    // Run the I/O service on the requested number of threads
    std::vector<std::thread> v;
    v.reserve(threads_ - 1);
    for(auto i = threads_ - 1; i > 0; --i)
        v.emplace_back(
                [&ioc]
                {
                ioc.run();
                });
    ioc.run();

    return RC_OK;
}

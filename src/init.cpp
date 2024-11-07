#include <iostream>
#include "libraries/httplib.h"

using namespace httplib;

/*
    Server testing. This is so fucking awesome
*/

int main()
{
    std::cout << "Running server." << std::endl;

    Server server;

    server.Get("/sigma", [](const Request& /*req*/, Response& res) {
        std::cout << "Received GET request on /sigma." << std::endl;
        res.set_content("I hate sigmas.", "text/plain");
    });

    server.listen("0.0.0.0", 12800);
}
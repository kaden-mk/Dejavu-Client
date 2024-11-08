#include <iostream>
#include "libraries/httplib.h"

using namespace httplib;

/*
    Server testing. This is so fucking awesome
*/

int main()
{
    const short PORT = 8080;

    std::cout << "Running Dejavu Client on port " << PORT << '.' << std::endl;

    Server server;

    server.Get("/sigma", [](const Request& /*req*/, Response& res) {
        std::cout << "Received GET request on /sigma." << std::endl;
        

        res.set_content("{\"message\": \"I hate sigmas.\"}", "application/json");
    });

    server.listen("127.0.0.1", PORT);
}
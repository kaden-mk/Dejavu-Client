#include <iostream>
#include <fstream>
#include <string>
#include <istream>
#include "libraries/json.hpp"
#include "libraries/httplib.h"

using json = nlohmann::json;
using namespace httplib;

Server server;

#include "modules/commands.h"

int main()
{
    InitCommands();

    std::string input;

    while (true)
    {
        std::cout << "Run a command: ";
        std::getline(std::cin, input);

        std::istringstream iss(input);
        std::string commandName;
        iss >> commandName;

        std::vector<std::string> args;
        std::string arg;
        while (iss >> arg) {
            args.push_back(arg);
        }

        try {
            ExecuteCommand(commandName, args);
        }
        catch (const std::exception& exception) {
            std::cout << exception.what() << std::endl;
        }
    }
}
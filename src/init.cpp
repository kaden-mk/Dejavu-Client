#include <iostream>
#include <fstream>
#include <string>
#include <istream>
#include <filesystem>
#include <map>
#include "libraries/json.hpp"
#include "libraries/httplib.h"

using json = nlohmann::json;
using namespace httplib;

Server server;

// used for storing the build folders, goes like this "buildname" = path
std::map<std::string, std::string> folders;

#include "modules/commands.h"

int main()
{
    InitCommands();

    std::string input;

    std::cout << "Welcome to Dejavu Client!\nMade by: Astr0verload & Davey\nType 'help' to view available commands\n";

    while (!isExited)
    {
        std::cout << "> ";
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
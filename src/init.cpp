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

// JSON SAVING

// saves the json file
static void SaveFoldersToFile(const std::string& fileName = "folders.json") {
    json j;
    for (const auto& [buildName, path] : folders) {
        j[buildName] = path;
    }

    std::ofstream file(fileName);
    if (file.is_open()) {
        file << j.dump(4); // does a pretty print w 4 spaces
        file.close();
    }
}

// loads the json and adds it to the map
static void LoadFoldersFromFile(const std::string& fileName = "folders.json") {
    std::ifstream file(fileName);
    if (file.is_open()) {
        json j;
        file >> j;
        file.close();

        for (const auto& [buildName, path] : j.items()) {
            folders[buildName] = path.get<std::string>();
        }
    }
}

#include "modules/commands.h"
#include "modules/injectdll.h"

int main()
{
    injection();
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
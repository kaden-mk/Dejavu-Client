#include <iostream>
#include <fstream>
#include <string>
#include <istream>
#include "libraries/json.hpp"
#include "libraries/httplib.h"

using json = nlohmann::json;

// Responses
#include "responses/catalog.h"
#include "responses/calendar.h"
#include "responses/fortnite-game.h"
#include "responses/DefaultEngine.h"
#include "responses/DefaultGame.h"
#include "responses/DefaultRuntimeOptions.h"
#include "responses/athenaProfile.h"
#include "responses/common_core.h"
#include "responses/common_public.h"
#include "responses/collections.h"
#include "responses/creative.h"

using namespace httplib;

Server server;

// Modules
#include "modules/statics.h"
#include "modules/dynamics.h"
#include "modules/api.h"
#include "modules/profile.h"
#include "modules/commands.h"

int main()
{
    const short PORT = 8080;

    initStatics();
    initDynamics();
    initApi();
    initProfile();
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
#pragma once

#include <vector>
#include <iostream>

struct Command {
	std::string name;
	std::string description;
};

std::vector<Command> commands;

void GetAllCommands() {

}

void AddCommand(std::string name, std::string description) {

}

Command FindCommand(std::string name) {

}

void ExecuteCommand(std::string name) {

}
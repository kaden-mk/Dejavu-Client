struct Command {
	std::string name;
	std::string description;
	std::function<void(const std::vector<std::string>&)> execute;
};

std::vector<Command> commands;

void GetAllCommands() {

}

Command AddCommand(const std::string name, const std::string description, std::function<void(const std::vector<std::string>&)> execute) {
	Command newCommand;
	newCommand.name = name;
	newCommand.description = description;
	newCommand.execute = execute;

	commands.push_back(newCommand);

	return newCommand;
}

bool DoesCommandExist(const std::string& name) {
	return std::any_of(commands.begin(), commands.end(), [&](const Command& command) {
		return command.name == name;
	});
}

Command GetCommand(const std::string& name) {
	auto it = std::find_if(commands.begin(), commands.end(), [&](const Command& command) {
		return command.name == name;
		});

	if (it != commands.end()) {
		return *it;
	}
	else {
		throw std::runtime_error("Command not found.");
	}
}

void ExecuteCommand(const std::string& name, const std::vector<std::string>& args = {}) {
	bool commandExists = DoesCommandExist(name);

	if (!commandExists) {
		std::cout << "This command doesn't exist!\n";
		return;
	}

	Command command = GetCommand(name);

	if (command.execute) {
		command.execute(args);
	}
}

// Command setup

void InitCommands() {
	// run server

	Command runServerCommand = AddCommand("run", "Runs stuff.",
		[](const std::vector<std::string>& args) {
			// TODO: add better arg checking
			if (!args.empty()) {
				if (args[0] == "server")
					std::cout << "Running server on port: " << args[1] << std::endl;
			}
			else {
				std::cout << "No port specified. Usage: run server <port>" << std::endl;
			}
		});
}
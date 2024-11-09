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

	int PORT = 0;
	bool isServerRunning = false;

	Command runServerCommand = AddCommand("run", "Runs stuff.",
		[&isServerRunning, &PORT](const std::vector<std::string>& args) {
			if (!args.empty()) {
				if (args[0] == "server") {
					if (isServerRunning) {
						std::cout << "You already have a server running!" << std::endl;
						return;
					}

					if (args.size() < 2) {
						std::cout << "You need to specify the port number!" << std::endl;
						return;
					}

					isServerRunning = true;
					PORT = std::stoi(args[1]);
					std::cout << "Running Dejavu Client on port: " << PORT << std::endl;

					server.listen("120.0.0.1", PORT);
				}
			}
			else {
				std::cout << "You need to specify args!" << std::endl;
			}
		});
}
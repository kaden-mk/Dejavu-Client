struct Command {
	std::string name;
	std::string description;
	std::function<void(const std::vector<std::string>&)> execute;
};

std::vector<Command> commands;

// Prints out every command with its description.
void GetAllCommands() {

}

// Adds a command structure to commands & creates it.
Command AddCommand(const std::string name, const std::string description, std::function<void(const std::vector<std::string>&)> execute) {
	Command newCommand;
	newCommand.name = name;
	newCommand.description = description;
	newCommand.execute = execute;

	commands.push_back(newCommand);

	return newCommand;
}

// Checks if a command exists.
bool DoesCommandExist(const std::string& name) {
	return std::any_of(commands.begin(), commands.end(), [&](const Command& command) {
		return command.name == name;
	});
}

// Returns a command with the specificed name.
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

// Executes a command with the specificed name & args.
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

bool isExited = false;

void InitCommands() {
	LoadFoldersFromFile();

	// build stuff

	Command buildCommand = AddCommand("build", "Used for building stuff.",
		[](const std::vector<std::string>& args) {
			if (args.empty()) {
				std::cout << "You need to specify args!" << std::endl;
				return;
			}

			if (args[0] == "add") {
				if (args.size() < 3) {
					std::cout << "You need to specify more args! build add <path> <buildname>";
					return;
				}

				std::string path = args[1];
				if (!std::filesystem::exists(path)) {
					std::cout << "The specified path does not exist: " << path << std::endl;
					return;
				}

				std::string buildName = args[2];

				if (folders.find(buildName) != folders.end()) {
					std::cout << "This build name already exists! Remove it or use a different build name." << std::endl;
					return;
				}

				// adds the buildname to the map
				folders[buildName] = path;

				SaveFoldersToFile();

				std::cout << "Successfully added build: " << buildName << " as a saved directory.\n";
			}
			else if (args[0] == "remove") {
				if (args.size() < 2) {
					std::cout << "You need to specify more args! build remove <buildname>";
					return;
				}

				std::string buildName = args[1];

				if (folders.find(buildName) == folders.end()) {
					std::cout << "This build doesn't exist!" << std::endl;
					return;
				}

				folders.erase(buildName);
				
				SaveFoldersToFile();

				std::cout << "Successfully removed build: " << buildName << std::endl;
			}
			else if (args[0] == "list") {
				for (const auto& pair : folders) {
					std::cout << "Name: " << pair.first << ", Directory: " << pair.second << std::endl;
				}
			}
			else if (args[0] == "run") {
				// args are build run <buildname> <ip> <port>

				if (args.size() < 4) {
					std::cout << "You need to specify more args! build run <buildname> <ip> <port>\n";
					return;
				}

				std::string buildName = args[1];
				std::string ip = args[2];
				int port = std::stoi(args[3]);

				if (folders.find(buildName) == folders.end()) {
					std::cout << "This build doesn't exist!" << std::endl;
					return;
				}

				std::string directory = folders[buildName] + "/FortniteGame/Binaries/Win64/FortniteClient-Win64-Shipping.exe";

				if (!std::filesystem::exists(directory)) {
					std::cout << "Could not find specified .exe file inside the directory.\n";
					return;
				}

				// checking if the backend is online

				std::cout << "Pinging the backend with ip: " << ip << " & port: " << port << std::endl;

				Client client(ip, port);
				client.set_connection_timeout(10);

				auto response = client.Get("/waitingroom/api/waitingroom");

				client.stop();

				if (!response || response->status != StatusCode::OK_200 && response->status != StatusCode::NoContent_204) {
					std::cout << "Backend offline, please try again.\n";
					return;
				}

				std::cout << "Backend online, launching Fortnite." << std::endl;
				
				// creates the command to run the .exe
				std::string command = "\"" + directory + "\" -skippatchcheck -epicportal -HTTP=WinInet";

				// i could've used createprocess for more control but i'll see

				int result = std::system(command.c_str());

				if (result == -1) {
					std::cout << "Failed to launch Fortnite." << std::endl;
				}	
			}
		});

	// exit command

	Command exitCommand = AddCommand("exit", "Exits the program.",
		[](const std::vector<std::string>& args) {
			isExited = true;
			SaveFoldersToFile();
		});
		
}
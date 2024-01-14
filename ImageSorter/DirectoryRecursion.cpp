	#include "Header.h"

	void directoryRecursion(const std::string& DIRECTORY_PATH) {
		std::cout << "Please choose an option:" << std::endl;
		std::cout << "1] Open this directory" << std::endl;
		std::cout << "2] Select this directory" << std::endl;

		int userChoice;
		std::cin >> userChoice;
		std::vector<std::string> subdirectories;
		int directoryIndex;

		switch (userChoice) {
		case 1: {
			system("CLS");
			std::cout << "Subdirectories of " << DIRECTORY_PATH << ":\n";
			int count = 1;
			for (const auto& entry : std::filesystem::directory_iterator(DIRECTORY_PATH)) {
				if (std::filesystem::is_directory(entry)) {
					std::cout << "[" << count << "] " << entry.path().string() << '\n';
					subdirectories.push_back(entry.path().string());
					count++;
				}
			}
			std::cout << "[" << count << "] Go back\n";
			std::cout << "Please enter the number of the subdirectory you want to open: ";

			std::cin >> directoryIndex;
			if (directoryIndex >= 1 && directoryIndex <= subdirectories.size()) {
				directoryStack.push(subdirectories[directoryIndex - 1]);
				directoryRecursion(subdirectories[directoryIndex - 1]);
			}
			else if (directoryIndex == subdirectories.size() + 1) {
				if (!directoryStack.empty()) {
					directoryStack.pop();
				}
				if (!directoryStack.empty()) {
					std::string previousDirectory = directoryStack.top();
					directoryRecursion(previousDirectory);
					system("CLS");
				}
				else {
					std::cout << "No previous directory to go back to.\n";
				}
			}
			else {
				std::cout << "Invalid option. Please try again." << std::endl;
			}
			break;
		}

		case 2: {
			std::cout << "Are you sure you want to sort this directory " << DIRECTORY_PATH << " ? [1] Yes/[2] No" << std::endl;
			std::cin >> userChoice;
			if (userChoice == 1) {
				imageSorter(DIRECTORY_PATH);
				system("CLS");
			}
			else if (userChoice != 2) {
				std::cout << "Invalid Choice. Try again" << std::endl;
			}
			break;
		}

		default:
			std::cout << "Invalid option. Please try again." << std::endl;
		}
	}

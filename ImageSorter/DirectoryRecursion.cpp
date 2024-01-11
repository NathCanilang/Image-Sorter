#include "Header.h"

void directoryRecursion(const std::string& directoryPath) {
    std::cout << "Please choose an option:" << std::endl;
    std::cout << "1] Open this directory" << std::endl;
    std::cout << "2] Select this directory" << std::endl;
    std::cout << "3] Back" << std::endl;

    int userChoice;
    std::cin >> userChoice;

    switch (userChoice) {
    case 1: {
        std::cout << "Subdirectories of " << directoryPath << ":\n";
        std::vector<std::string> subdirectories;
        int count = 1;
        for (const auto& entry : std::filesystem::directory_iterator(directoryPath)) {
            if (std::filesystem::is_directory(entry)) {
                std::cout << "[" << count << "] " << entry.path().string() << '\n';
                subdirectories.push_back(entry.path().string());
                count++;
            }
        }
        std::cout << "Please enter the number of the subdirectory you want to open: ";
        int directoryIndex;
        std::cin >> directoryIndex;
        directoryRecursion(subdirectories[directoryIndex - 1]);
        break;
    }
    case 2:
        std::cout << "You have selected this folder" << std::endl;
        break;

    case 3:
        std::cout << "Go back" << std::endl;
        break;

    default:
        std::cout << "Invalid option. Please try again." << std::endl;
    }
}

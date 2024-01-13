#include "Header.h"

void directoryRecursion(const std::string& directoryPath) {
    std::cout << "Please choose an option:" << std::endl;
    std::cout << "1] Open this directory" << std::endl;
    std::cout << "2] Select this directory" << std::endl;

    int userChoice;
    std::cin >> userChoice;
    std::vector<std::string> subdirectories;

    switch (userChoice) {
    case 1: {
        system("CLS");
        std::cout << "Subdirectories of " << directoryPath << ":\n";
        int count = 1;
        for (const auto& entry : std::filesystem::directory_iterator(directoryPath)) {
            if (std::filesystem::is_directory(entry)) {
                std::cout << "[" << count << "] " << entry.path().string() << '\n';
                subdirectories.push_back(entry.path().string());
                count++;
            }
        }
        std::cout << "[" << count << "] Go back\n";
        std::cout << "Please enter the number of the subdirectory you want to open: ";
        int directoryIndex;
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

    case 2:
        std::cout << "You have selected this folder" << std::endl;
        break;

    default:
        std::cout << "Invalid option. Please try again." << std::endl;
    }
}

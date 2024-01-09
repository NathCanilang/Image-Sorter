#include "Header.h"


void directoryRecursion(int userChoice) {

	std::cout << "Please choose an option:" << std::endl;
	std::cout << "1] Open this directory" << std::endl;
	std::cout << "2] Select this directory" << std::endl;
	std::cout << "3] Back" << std::endl;

	switch (userChoice) {
	case 1:
		std::cout << "Open this directory" << std::endl;
		break;

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

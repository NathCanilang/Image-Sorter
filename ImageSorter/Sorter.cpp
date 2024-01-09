#include "Header.h"

//all images are stored in a folder
//once the said folder is selected 
//iterate all the files and look for extensions of the files 
//separate them based on their file extensions on a separate folder

//New entry
/* the user will give the folder that they want to be sorted
but the file path of the sorted images is fixed*/

int main() {

	/*std::string testPath1 = "A:\Screenshots";
	std::string testPath2 = "A:\Sorted Images";
	myMethod.imageSorter(testPath1);
	myMethod.reverseImageSort(testPath2);*/

	DWORD driveMask = GetLogicalDrives();
	std::vector<std::string> partitions;

	for (int i = 0; i < 26; ++i) {
		if (driveMask & (1 << i)) {
			char driveLetter = 'A' + i;
			partitions.push_back(std::string(1, driveLetter) + ":\\");
		}
	}

	std::string selectedPartition;
	std::cout << "Please select the partition from the list below that you want to sort." << std::endl;
	for (int i = 0; i < partitions.size(); i++) {
		std::cout << i + 1 << ". " << partitions[i] << std::endl;
	}

	int partitionIndex;
	std::cin >> partitionIndex;
	selectedPartition = partitions[partitionIndex - 1];

	std::cout << "You selected: " << selectedPartition << std::endl;
	std::cout << "The folders in this partition are:" << std::endl;

	std::vector<std::string> directories;
	int count = 1;
	for (const auto& entry : std::filesystem::directory_iterator(selectedPartition)) {
		if (std::filesystem::is_directory(entry)) {
			directories.push_back(entry.path().string());
			std::cout << count << "] " << entry.path().string() << std::endl;
			count++;
		}
	}

	std::cout << "Please select the directory from the list above that you want to sort." << std::endl;
	int directoryIndex;
	std::cin >> directoryIndex;
	//std::string selectedDirectory = directories[directoryIndex - 1];
	std::string selectedDirectory = directories[directoryIndex - 1];

	//presumablly na dito ka magsisimula ng recursion call dapat ang ipapasa na parameter yung user input
	
	std::cout << "You selected: " << selectedDirectory << std::endl;

	std::cout << "Please choose an option:" << std::endl;
	std::cout << "1] Open this directory" << std::endl;
	std::cout << "2] Select this directory" << std::endl;
	std::cout << "3] Back" << std::endl;

	int option;
	std::cin >> option;

	switch (option) {
	case 1: {
		//need to puch to the stack and do recursion and print all the subdirectories
		std::cout << "Subdirectories of " << selectedDirectory << ":\n";
		for (const auto& entry : std::filesystem::directory_iterator(selectedDirectory)) {
			if (std::filesystem::is_directory(entry)) {
				std::cout << entry.path().string() << '\n';
			}
		}
		break;
	}
	case 2: {
		//tawagin mo na yun method mismo at kunin na yung full file path 
		std::cout << "You have selected the directory: " << selectedDirectory << "\n";

		break;
	}
	case 3: {
		std::cout << "Going back to partition selection...\n";
		//need to pop the last/current directory and go there
		break;
	}
	default: {
		std::cout << "Invalid option. Please try again." << std::endl;
	}
	}


	return 0;
}

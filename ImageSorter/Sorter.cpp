#include "Header.h"

//all images are stored in a folder
//once the said folder is selected 
//iterate all the files and look for extensions of the files 
//separate them based on their file extensions on a separate folder

//New entry
/* the user will give the folder that they want to be sorted
but the file path of the sorted images is fixed*/

std::string selectedDirectory;

int main() {

	/*std::string testPath1 = "A:\Screenshots";
	std::string testPath2 = "A:\Sorted Images";
	myMethod.imageSorter(testPath1);
	myMethod.reverseImageSort(testPath2);*/

	DWORD driveMask = GetLogicalDrives();
	std::vector<std::string> partitions;

	int i;
	for (i = 0; i < 26; ++i) {
		if (driveMask & (1 << i)) {
			char driveLetter = 'A' + i;
			partitions.push_back(std::string(1, driveLetter) + ":\\");
		}
	}

	std::string selectedPartition;
	while (true) {
		std::cout << "Please select the partition from the list below that you want to sort." << std::endl;
		for (i = 0; i < partitions.size(); i++) {
			std::cout << "[" << i + 1 << "] " << partitions[i] << std::endl;
		}

		std::cout << "[" << i + 1 << "] Exit" << std::endl;


		std::cout << "Enter the number from the selection: ";

		int partitionIndex;
		std::cin >> partitionIndex;
		if (partitionIndex < 1 || partitionIndex > i + 1) {
			std::cout << "Invalid selection. Please enter a number between 1 and " << i + 1 << "." << std::endl;
			continue;
		}

		if (partitionIndex == i + 1) {
			return 0;
		}

		selectedPartition = partitions[partitionIndex - 1];
		directoryStack.push(selectedPartition);

		system("CLS");
		std::cout << "You selected: " << selectedPartition << std::endl;
		std::cout << "The folders in this partition are:" << std::endl;

		std::vector<std::string> directories;
		int count = 0;
		for (const auto& entry : std::filesystem::directory_iterator(selectedPartition)) {
			if (std::filesystem::is_directory(entry)) {
				directories.push_back(entry.path().string());
				std::cout << "[" << count + 1 << "] " << entry.path().string() << std::endl;
				count++;
			}

		}
		std::cout << "[" << count + 1 << "] Go Back" << std::endl;
		std::cout << "Please select the directory from the list above that you want to sort." << std::endl;
		std::cout << "Enter the number from the selection: ";
		int directoryIndex;
		std::cin >> directoryIndex;
		std::cout << directoryIndex << std::endl;
		if (directoryIndex == (count + 1)) {
			directoryStack = std::stack<std::string>();
			system("CLS");
		}
		else {
			selectedDirectory = directories[directoryIndex - 1];
			directoryStack.push(selectedDirectory);
			directoryRecursion(selectedDirectory);
		}
	}

	return 0;
}

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

	for (int i = 0; i < 26; ++i) {
		if (driveMask & (1 << i)) {
			char driveLetter = 'A' + i;
			partitions.push_back(std::string(1, driveLetter) + ":\\");
		}
	}

	std::string selectedPartition;
	std::cout << "Please select the partition from the list below that you want to sort." << std::endl;
	for (int i = 0; i < partitions.size(); i++) {
		std::cout << "[" << i + 1 << "] " << partitions[i] << std::endl;
	}
	std::cout << "Enter the number from the selection: ";

	int partitionIndex;
	std::cin >> partitionIndex;
	selectedPartition = partitions[partitionIndex - 1];

	system("CLS");
	std::cout << "You selected: " << selectedPartition << std::endl;
	std::cout << "The folders in this partition are:" << std::endl;

	std::vector<std::string> directories;
	int count = 1;
	for (const auto& entry : std::filesystem::directory_iterator(selectedPartition)) {
		if (std::filesystem::is_directory(entry)) {
			directories.push_back(entry.path().string());
			std::cout << "[" << count << "] " << entry.path().string() << std::endl;
			count++;
		}
	}

	std::cout << "Please select the directory from the list above that you want to sort." << std::endl;
	std::cout << "Enter the number from the selection: ";
	int directoryIndex;
	std::cin >> directoryIndex;
	selectedDirectory = directories[directoryIndex - 1];

	// Call the recursive function with the selected directory
	directoryRecursion(selectedDirectory);

	return 0;
}

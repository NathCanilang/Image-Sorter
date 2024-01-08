#pragma once
#include <iostream>
#include <algorithm>
#include <filesystem>
#include <fstream>
#include <string>
#include <cstdio>
#include <set>
#include<Windows.h>

//all images are stored in a folder
//once the said folder is selected 
//iterate all the files and look for extensions of the files 
//separate them based on their file extensions on a separate folder

//New entry
/* the user will give the folder that they want to be sorted
but the file path of the sorted images is fixed*/


class Main
{
public:

    void imageSorter(const std::string& IMAGE_DIRECTORY) {
        std::string sortedImageDirectory = "A:\\Sorted Images";
        std::vector<std::string> failedFiles;
        std::set<std::string> validExtensions = { ".jpg", ".jpeg", ".png", ".ico", ".bmp", ".gif", ".svg", ".webp" };

        try {
            for (const auto& entry : std::filesystem::directory_iterator(IMAGE_DIRECTORY)) {
                std::string fileName = entry.path().string();
                std::string fileExtension = entry.path().extension().string();
                std::string subDirectory;

                if (validExtensions.find(fileExtension) != validExtensions.end()) {
                    if (fileExtension == ".jpg" || fileExtension == ".jpeg") {
                        subDirectory = "JPEG";
                    }
                    else if (fileExtension == ".png") {
                        subDirectory = "PNG";
                    }
                    else if (fileExtension == ".ico") {
                        subDirectory = "ICO";
                    }
                    else if (fileExtension == ".bmp") {
                        subDirectory = "BMP";
                    }
                    else if (fileExtension == ".gif") {
                        subDirectory = "GIF";
                    }
                    else if (fileExtension == ".svg") {
                        subDirectory = "SVG";
                    }
                    else if (fileExtension == ".webp") {
                        subDirectory = "WEBP";
                    }

                    std::filesystem::path destPath = sortedImageDirectory;
                    destPath /= subDirectory;
                    destPath /= entry.path().filename();

                    if (rename(fileName.c_str(), destPath.string().c_str()) != 0) {
                        failedFiles.push_back(fileName);
                    }
                    else {
                        std::cout << "Operation success.\n";
                    }
                }
            }

            if (!failedFiles.empty()) {
                std::cout << "Failed to move the following images:\n";
                for (const auto& file : failedFiles) {
                    std::cout << file << '\n';
                }
            }
        }

        catch (std::filesystem::filesystem_error& e) {
            std::cout << e.what() << '\n';
        }
    }


	void reverseImageSort(const std::string& SORTED_IMAGE_DIRECTORY) {
		std::string screenshotDirectory = "A:\\Screenshots";

		try {
			for (const auto& entry : std::filesystem::recursive_directory_iterator(SORTED_IMAGE_DIRECTORY)) {
				if (std::filesystem::is_regular_file(entry.path())) {
					std::string files = entry.path().string();
					std::string fileExtension = entry.path().extension().string();
					std::cout << files << std::endl;

					std::filesystem::path destPath = screenshotDirectory;
					destPath /= entry.path().filename();

					if (rename(files.c_str(), destPath.string().c_str()) != 0) {
						std::cout << "Failed to move the image." << std::endl;
						std::cout << "Image Name: " << files << "File extension: " << fileExtension << std::endl;
					}
					else {
						std::cout << "Operation success.\n";
					}
				}
			}
		}

		catch (std::filesystem::filesystem_error& e) {
			std::cout << e.what() << '\n';
		}
	}
};



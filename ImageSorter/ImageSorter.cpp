#include "Header.h"

void imageSorter(const std::string& IMAGE_DIRECTORY) {
    std::vector<std::string> failedFiles;
    std::set<std::string> validExtensions = { ".jpg", ".jpeg", ".png", ".ico", ".bmp", ".gif", ".svg", ".webp" };

    std::filesystem::path sortedImagesPath = IMAGE_DIRECTORY;
    sortedImagesPath /= "Sorted Images";

    if (!std::filesystem::exists(sortedImagesPath)) {
        std::filesystem::create_directory(sortedImagesPath);
    }

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

                std::filesystem::path destPath = sortedImagesPath;
                destPath /= subDirectory;

                if (!std::filesystem::exists(destPath)) {
                    std::filesystem::create_directory(destPath);
                }

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

//Emergency Function
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
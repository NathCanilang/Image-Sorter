#pragma once
#include <iostream>
#include <algorithm>
#include <filesystem>
#include <fstream>
#include <string>
#include <cstdio>
#include <set>
#include<Windows.h>
#include <stdlib.h>

extern std::string selectedDirectory;

void imageSorter(const std::string& IMAGE_DIRECTORY);
void reverseImageSort(const std::string& SORTED_IMAGE_DIRECTORY);
void directoryRecursion(const std::string& directoryPath);
void ReturnDirectoryOnce();

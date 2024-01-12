#pragma once
#include <iostream>
#include <algorithm>
#include <filesystem>
#include <fstream>
#include <string>
#include <cstdio>
#include <set>
#include <Windows.h>
#include <stdlib.h>
#include <stack>

extern std::string selectedDirectory;
extern std::stack<std::string> directoryStack;

void imageSorter(const std::string& IMAGE_DIRECTORY);
void reverseImageSort(const std::string& SORTED_IMAGE_DIRECTORY);
void directoryRecursion(const std::string& directoryPath);
void push(const std::string& DIRECTORY);
void pop();

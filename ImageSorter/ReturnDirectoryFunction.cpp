#include "Header.h"

std::stack<std::string> directoryStack;

void push(const std::string& directory) {
    directoryStack.push(directory);
}

void pop() {
    if (!directoryStack.empty()) {
        directoryStack.pop();
    }
}
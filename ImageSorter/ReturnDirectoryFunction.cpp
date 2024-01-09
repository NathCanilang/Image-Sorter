#include "Header.h"

std::vector<std::string> direcetoryContainer;

void pop(std::string element) {
	element.pop_back();

}

void push(std::string element) {
	if (element.empty()) {
		std::cout << "How did you manage to do this?" << std::endl; // Display full message if the stack is empty
	}
	else {
		// Remove the last element from the vector
		element.pop_back();
	}
}
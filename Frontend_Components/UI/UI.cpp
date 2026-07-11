#include "UI.hpp"
#include <iostream>
#include <string>
#include <limits>

void printMenu() {
    std::cout << "\n--- G25 Coordinate Converter ---\n"
              << "1. Convert Unscaled to Scaled\n"
              << "2. Convert Scaled to Unscaled\n"
              << "3. Exit\n"
              << "---------------------------------\n"
              << "Enter your choice: ";
}

uint8_t getMenuChoice() {
    int choice;
    while (true) {
        std::cin >> choice;
        if (!std::cin.fail()) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return static_cast<uint8_t>(choice);
        }
        std::cout << "Invalid input. Please enter a number: ";
        std::cin.clear(); 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    }
}

std::string getFilePath() {
    std::string path;
    std::cout << "Please enter the input file path: ";
    std::getline(std::cin, path);
    const auto first = path.find_first_not_of(" \t\n\r\"");
    if (first == std::string::npos) return "";
    const auto last = path.find_last_not_of(" \t\n\r\"");
    return path.substr(first, (last - first + 1));
}
//
// Created by ethan on 4/24/24.
//

#include "../include/FileManager.h"
#include <iostream>
#include <filesystem>
#include <vector>
#include <string>

FileManager::FileManager() {
    std::vector<std::string> pathStack;

    while (true)
    {
        std::string inputPath;

        if (!pathStack.empty())
        {
            std::cout << "Current directory: " << std::filesystem::path(pathStack.back()) << std::endl;
        }

        std::cout << "Enter next directory name (or 'back' to go up, 'exit' to quit): ";
        std::getline(std::cin, inputPath);

        if (inputPath == "exit")
        {
            break;
        }
        else if (inputPath == "back" && !pathStack.empty())
        {
            pathStack.pop_back();
            continue;
        }

        std::filesystem::path currentPath = (!pathStack.empty()) ? std::filesystem::path(pathStack.back()) : std::filesystem::path("/");
        currentPath /= inputPath;

        if (std::filesystem::exists(currentPath) && std::filesystem::is_directory(currentPath))
        {
            listFiles(currentPath);
            pathStack.push_back(currentPath.string());
        }
        else
        {
            std::cout << "Invalid directory name." << std::endl;
        }

        std::cout << std::endl;
    }
}

void FileManager::listFiles(const std::filesystem::path& directoryPath) {
    std::cout << "Listing directory: " << directoryPath << std::endl;

    for (const auto& entry : std::filesystem::directory_iterator(directoryPath))
    {
        std::cout << entry.path().filename() << std::endl;
    }
}
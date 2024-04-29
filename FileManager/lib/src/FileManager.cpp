#include "../include/FileManager.h"
#include <iostream>
#include <filesystem>
#include <vector>
#include <string>

FileManager::FileManager() {
    std::vector<std::string> pathStack;

    std::string inputPath = "/";

    if (std::filesystem::exists(inputPath) && std::filesystem::is_directory(inputPath))
    {
        listFiles(inputPath);
        pathStack.push_back(inputPath);
    }
    else
    {
        std::cout << "Invalid directory name." << std::endl;
    }

    while (true)
    {

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

    for (const auto& entry : std::filesystem::directory_iterator(directoryPath)) {
        std::string filename = entry.path().filename().string();
        std::string extension = entry.path().extension().string();
        if (entry.is_directory()) {
            std::cout << "\x1B[34m" << filename << "/" << "\x1B[0m" << std::endl;
        } else if (extension == ".pdf" || extension == ".txt" || extension == ".docx" || extension == ".doc" || extension == ".pptx" || extension == ".ppt" || extension == ".xlsx" || extension == ".xls" || extension == ".csv" || extension == ".xml" || extension == ".json") {
            std::cout << "\x1B[32m" << filename << "\x1B[0m" << std::endl;
        } else if (entry.is_regular_file()) {
            std::cout << filename << std::endl;
        }
    }
}
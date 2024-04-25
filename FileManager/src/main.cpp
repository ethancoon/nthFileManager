#include <iostream>
#include <filesystem>
#include <string>
#include <vector>

namespace fs = std::filesystem;

void traverseDirectories(const fs::path& directoryPath)
{
    std::cout << "Listing directory: " << directoryPath << std::endl;

    for (const auto& entry : fs::directory_iterator(directoryPath))
    {
        std::cout << entry.path().filename() << std::endl;
    }
}

int main()
{
    std::vector<std::string> pathStack;

    while (true)
    {
        std::string inputPath;

        if (!pathStack.empty())
        {
            std::cout << "Current directory: " << fs::path(pathStack.back()) << std::endl;
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

        fs::path currentPath = (!pathStack.empty()) ? fs::path(pathStack.back()) : fs::path("/");
        currentPath /= inputPath;

        if (fs::exists(currentPath) && fs::is_directory(currentPath))
        {
            traverseDirectories(currentPath);
            pathStack.push_back(currentPath.string());
        }
        else
        {
            std::cout << "Invalid directory name." << std::endl;
        }

        std::cout << std::endl;
    }

    return 0;
}

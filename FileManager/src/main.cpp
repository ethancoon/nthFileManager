#include <iostream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

void traverseDirectories(const fs::path& directoryPath)
{
    std::cout << "Listing directory: " << directoryPath << std::endl;

    for (const auto& entry : fs::directory_iterator(directoryPath))
    {
        std::cout << entry.path().string() << std::endl;
    }
}

int main()
{
    std::string inputPath;

    while (true)
    {
        std::cout << "Enter directory path (or 'exit' to quit): ";
        std::getline(std::cin, inputPath);

        if (inputPath == "exit")
        {
            break;
        }

        fs::path directoryPath(inputPath);

        if (fs::exists(directoryPath) && fs::is_directory(directoryPath))
        {
            traverseDirectories(directoryPath);
        }
        else
        {
            std::cout << "Invalid directory path." << std::endl;
        }

        std::cout << std::endl;
    }

    return 0;
}

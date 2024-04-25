#include <iostream>
#include <filesystem>

void traverseDirectory(const std::filesystem::path& directoryPath)
{
    for (const auto& entry : std::filesystem::directory_iterator(directoryPath))
    {
        try
        {
            if (std::filesystem::is_symlink(entry.path()))
            {
                // Skip symbolic links
                continue;
            }
            else if (std::filesystem::is_regular_file(entry.path()))
            {
                std::cout << entry.path() << std::endl;
            }
            else if (std::filesystem::is_directory(entry.path()))
            {
                traverseDirectory(entry.path());
            }
        }
        catch (const std::filesystem::filesystem_error& e)
        {
            std::cerr << "filesystem error: " << e.what() << std::endl;
        }
    }
}

int main() {
    std::filesystem::path rootPath = "/"; // Start from the root directory
    traverseDirectory(rootPath);

    return 0;
}

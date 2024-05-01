#ifndef NTHFILEMANAGER_FILEMANAGER_H
#define NTHFILEMANAGER_FILEMANAGER_H

#include <filesystem>

class FileManager {
public:
    FileManager();

    static void listFiles(const std::filesystem::path& directoryPath);
    static void createFile(const std::filesystem::path& filePath);
};


#endif //NTHFILEMANAGER_FILEMANAGER_H

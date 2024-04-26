#ifndef NTHFILEMANAGER_FILEMANAGER_H
#define NTHFILEMANAGER_FILEMANAGER_H

#include <filesystem>

class FileManager {
public:
    FileManager();

    static void listFiles(const std::filesystem::path& directoryPath);
};


#endif //NTHFILEMANAGER_FILEMANAGER_H

//
// Created by ethan on 4/24/24.
//

#ifndef NTHFILEMANAGER_FILEMANAGER_H
#define NTHFILEMANAGER_FILEMANAGER_H

#include <filesystem>

class FileManager {
public:
    FileManager();

    void listFiles(const std::filesystem::path& directoryPath);
};


#endif //NTHFILEMANAGER_FILEMANAGER_H

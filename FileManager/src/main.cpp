#include <filesystem>
#include <fstream>
#include <iostream>

using namespace std;
using namespace std::filesystem;

int main() {
    std::filesystem::path directoryPath = "test";

    if (!exists(directoryPath)) {
        create_directory(directoryPath);
        cout << "Directory created: " << directoryPath
             << endl;
    }

    path filepath = directoryPath / "my_file.txt";

    ofstream file(filepath);
    if (file.is_open()) {
        file << "Hello, FileSystem!";
        file.close();
        cout << "File created: " << filepath << endl;
    }
    else {
        cerr << "Failed to create file: " << filepath
             << endl;
    }

    return 0;
}


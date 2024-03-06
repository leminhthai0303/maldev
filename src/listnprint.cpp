#include <iostream>
#include <filesystem>
#include <vector>
#include <string>

namespace fs = std::filesystem;

struct FileItem {
    std::string name;
    bool isDirectory;
};

// Function to get a list of all files and directories in a specific path
std::vector<FileItem> listFilesAndDirectories(const std::string& path) {
    std::vector<FileItem> result;
    try {
        for (const auto& entry : fs::directory_iterator(path)) {
            if(fs::is_directory(entry.path())) {
                result.push_back({entry.path().filename().string(), true});
            } else {
                result.push_back({entry.path().filename().string(), false});
            }
        }
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return result;
}

// Function to print out files and directories from the data structure
void print(const std::vector<FileItem>& items, const std::string& prefix, const std::string& currentPath) {
    for (const auto& item : items) {
        std::cout << prefix;
        std::cout << (item.isDirectory ? "Directory: " : "File: ") << item.name << std::endl;

        if (item.isDirectory) {
            std::string newPath = currentPath + item.name + "/";
            std::vector<FileItem> subItems = listFilesAndDirectories(newPath);
            print(subItems, prefix + "  ", newPath);
        }
    }
}

int main() {
    std::string path = "C:\\"; // Path to C drive

    // Get a list of files and directories from the path
    std::vector<FileItem> filesAndDirs = listFilesAndDirectories(path);

    // Print out files and directories
    print(filesAndDirs, "", path);

    return 0;
}

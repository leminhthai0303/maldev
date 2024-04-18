#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>

namespace fs = std::filesystem;

struct FileItem {
    std::string name;
    bool isDirectory;
};

std::vector<FileItem> listFilesAndDirectories(const std::string& path) {
    std::vector<FileItem> result;
    try {
        for (const auto& entry : fs::directory_iterator(path)) {
            if (fs::is_directory(entry.path())) {
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

// Function to increase the size of a string to the nearest multiple of 16
std::string increaseSizeofString(const std::string& input) {
    size_t currentSize = input.size();
    size_t newSize = ((currentSize + 15) / 16) * 16;
    if (newSize > currentSize) {
        return input + std::string(newSize - currentSize, '\0');
    }
    return input;
}

// Function to read the content of a file into a single string
std::string readFiles(const std::string& filePath) {
    std::ifstream file(filePath, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filePath << std::endl;
        return "";
    }

    // Determine file size
    file.seekg(0, std::ios::end);
    std::streampos fileSize = file.tellg();
    file.seekg(0, std::ios::beg);

    // Read the entire file content into a string
    std::string fileContent(fileSize, '\0');
    file.read(&fileContent[0], fileSize);
    file.close();

    // Increase size to nearest multiple of 16 if necessary
    fileContent = increaseSizeofString(fileContent);

    return fileContent;
}

void print(const std::vector<FileItem>& items, const std::string& prefix, const std::string& currentPath) {
    for (const auto& item : items) {
        std::cout << prefix;
        if (item.isDirectory) {
            std::cout << "Directory: " << item.name << std::endl;
            std::string newPath = currentPath + item.name + "/";
            std::vector<FileItem> subItems = listFilesAndDirectories(newPath);
            print(subItems, prefix + "  ", newPath);
        } else {
            std::cout << "File: " << item.name << std::endl;
            std::string fileContent = readFiles(currentPath + item.name);
            std::cout << "File size: " << fileContent.size() << std::endl;
            std::cout << fileContent << std::endl;
        }
    }
}

int main() {
    std::string path = "C:\\test\\";
    std::vector<FileItem> items = listFilesAndDirectories(path);
    print(items, "", path);
    return 0;
}

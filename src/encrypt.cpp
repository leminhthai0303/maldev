#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

void listFilesAndFolders(const fs::path& directoryPath, const std::string& indent = "") {
    try {
        if (!fs::exists(directoryPath) || !fs::is_directory(directoryPath)) {
            std::cout << "Directory does not exist or is not a directory." << std::endl;
            return;
        }

        for (const auto& entry : fs::directory_iterator(directoryPath)) {
            try {
                if (fs::is_directory(entry.status())) {
                    std::cout << indent << "[Folder] " << entry.path().filename().string() << std::endl;
                    listFilesAndFolders(entry.path(), indent + "    ");
                }
            } catch (const std::exception& e) {
                std::cout << indent << "Cannot access: " << entry.path().filename().string() << " - " << e.what() << std::endl;
            }
        }

        for (const auto& entry : fs::directory_iterator(directoryPath)) {
            try {
                if (!fs::is_directory(entry.status())) {
                    std::cout << indent << "[File]   " << entry.path().filename().string() << std::endl;
                }
            } catch (const std::exception& e) {
                std::cout << indent << "Cannot access: " << entry.path().filename().string() << " - " << e.what() << std::endl;
            }
        }
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Error accessing directory: " << directoryPath << " - " << e.what() << std::endl;
    }
}

int main() {
    std::string path = "C:/";
    listFilesAndFolders(path);
    return 0;
}

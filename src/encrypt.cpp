#include <iostream>
#include <filesystem>
#include <chrono>
#include <iomanip>

namespace fs = std::filesystem;

// Hàm duyệt tệp
void traverseFiles(const fs::path& directoryPath) {
    try {
        // Duyệt qua tất cả các tệp trong thư mục được chỉ định
        for (const auto& entry : fs::directory_iterator(directoryPath)) {
            // Kiểm tra xem entry có phải là tệp không
            if (fs::is_regular_file(entry)) {
                std::cout << "File: " << entry.path() << '\n';
            }
        }
    } catch (const fs::filesystem_error& ex) {
        std::cerr << "Error accessing directory: " << ex.what() << std::endl;
    }
}

// Hàm xuất thông tin về tệp
void printFileInfo(const fs::path& directoryPath) {
    try {
        // Duyệt qua tất cả các tệp trong thư mục được chỉ định
        for (const auto& entry : fs::directory_iterator(directoryPath)) {
            // Kiểm tra xem entry có phải là tệp không
            if (fs::is_regular_file(entry)) {
                std::cout << "File: " << entry.path() << '\n';
                std::cout << "   Kích thước: " << fs::file_size(entry) << " bytes\n";
                auto last_write_time = fs::last_write_time(entry);
                std::time_t c_time = decltype(last_write_time)::clock::to_time_t(last_write_time);
                std::cout << "   Sửa đổi lần cuối: " << std::put_time(std::localtime(&c_time), "%c") << '\n';
            }
        }
    } catch (const fs::filesystem_error& ex) {
        std::cerr << "Error accessing directory: " << ex.what() << std::endl;
    }
}

int main() {
    fs::path c_drive_path = "C:/";

    std::cout << "Danh sách các tệp trong ổ đĩa C:\n";
    traverseFiles(c_drive_path);

    std::cout << "\nThông tin chi tiết về các tệp trong ổ đĩa C:\n";
    printFileInfo(c_drive_path);

    return 0;
}

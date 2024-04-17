#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cstdint>

std::vector<std::vector<uint8_t>> convertToUint8Arrays(const std::vector<std::string>& strings) {
    std::vector<std::vector<uint8_t>> byteArrays;

    // Duyệt qua từng chuỗi trong vector strings
    for (const std::string& str : strings) {
        // Khởi tạo mảng uint8_t với độ dài là độ dài của chuỗi str
        std::vector<uint8_t> byteArray(str.begin(), str.end());

        // Thêm mảng này vào vector kết quả
        byteArrays.push_back(byteArray);
    }

    return byteArrays;
}

std::vector<std::string> splitInto16CharStrings(const std::string& input) {
    std::vector<std::string> result;
    int inputLength = input.length();
    
    // Duyệt qua chuỗi đầu vào và cắt thành các chuỗi con có độ dài chính xác là 16 ký tự
    for (int i = 0; i < inputLength; i += 16) {
        // Lấy chuỗi con từ vị trí i đến i+15 (hoặc hết chuỗi nếu không đủ 16 ký tự)
        std::string substring = input.substr(i, 16);

        // Thêm chuỗi con vào vector kết quả
        result.push_back(substring);
    }
    
    return result;
}

void output(const char* title, uint8_t *data, uint32_t size) {
    std::cout << title; // Xuất chuỗi tiêu đề

    // Đặt các phép toán xuất chuỗi dưới dạng hex
    for (uint32_t index = 0; index < size; index++) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<uint32_t>(data[index]);
    }

    std::cout << std::endl; // Xuống dòng sau khi xuất xong
}

std::string increaseSizeofString(const std::string& input) {
    size_t currentSize = input.size();
    size_t newSize = ((currentSize + 15) / 16) * 16;
    if (newSize > currentSize) {
        return std::string(input) + std::string(newSize - currentSize, '\0');
    }
    return input;
}

int main() {
    std::string input;
    std::getline(std::cin, input);
    std::cout << input.size() << std::endl;
    input = increaseSizeofString(input);
    std::cout << input.size();
    std::vector<std::string> substrings = splitInto16CharStrings(input);
    std::vector<std::vector<uint8_t>> byteArrays = convertToUint8Arrays(substrings);
    std::cout << "Các giá trị uint8_t tương ứng của chuỗi đã nhập:" << std::endl;
    for (const auto& byteArray : byteArrays) {
        std::cout << std::endl << byteArray.size() << std::endl;
        for (uint8_t byte : byteArray) {
            std::cout << static_cast<int>(byte) << " ";
        }
    }
    std::cout << std::endl;
    return 0;
}

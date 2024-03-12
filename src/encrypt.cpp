#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

// Hàm tính lũy thừa modul hiệu quả
long long modPow(long long base, int exp, int modulus) {
    long long result = 1;
    base = base % modulus;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % modulus;
        exp = exp >> 1;
        base = (base * base) % modulus;
    }
    return result;
}

void encrypt(const std::string& path, int& e, int& n) {
    std::fstream file(path, std::ios::binary | std::ios::in | std::ios::out);

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << path << std::endl;
        return;
    }

    char byte;
    while (file.read(&byte, 1)) {
        unsigned char text = static_cast<unsigned char>(byte);
        unsigned char cipher = static_cast<unsigned char>(modPow(text, e, n));
        file.seekp(-1, std::ios::cur);
        file.put(cipher);
    }

    file.close();
}

// int main() {
//     std::string filePath = "C:\\test\\test.bat";
//     int e, n;

//     e = 3;
//     n = 667;

//     encrypt(filePath, e, n);

//     std::cout << "Encryption completed." << std::endl;

//     return 0;
// }
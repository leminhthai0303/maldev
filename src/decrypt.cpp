#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

// Hàm tính lũy thừa modul hiệu quả
long long modPow1(long long base, int exp, int modulus) {
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

void decrypt(const std::string& path, int& d, int& n) {
    std::fstream file(path, std::ios::binary | std::ios::in | std::ios::out);

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << path << std::endl;
        return;
    }

    char byte;
    while (file.read(&byte, 1)) {
        unsigned char cipher = static_cast<unsigned char>(byte);
        unsigned char text = static_cast<unsigned char>(modPow1(cipher, d, n));
        file.seekp(-1, std::ios::cur);
        file.put(text);
    }

    file.close();
}

// int main() {
//     std::string filePath = "C:\\test\\test.bat";
//     int d, n;

//     d = 411;
//     n = 667;

//     decrypt(filePath, d, n);

//     std::cout << "Decryption completed." << std::endl;

//     return 0;
// }
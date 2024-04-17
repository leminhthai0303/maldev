#include <iostream>
#include <vector>
#include <random>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>

struct KeyAndIV {
    std::vector<unsigned char> key;
    std::vector<unsigned char> iv;
};

const int size = 16;

KeyAndIV generateKeyAndIV(int key_size, int iv_size) {
    std::random_device rd;
    std::mt19937 gen(rd()); 

    std::uniform_int_distribution<> dis(0, 15);

    std::vector<unsigned char> key(key_size);
    for (int i = 0; i < key_size; ++i) {
        key[i] = static_cast<unsigned char>(dis(gen));
    }

    // Generate random IV
    std::vector<unsigned char> iv(iv_size);
    for (int i = 0; i < iv_size; ++i) {
        iv[i] = static_cast<unsigned char>(dis(gen));
    }

    KeyAndIV result;
    for (const auto& byte : key) {
        std::stringstream ss;
        ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(byte);
        std::string hex_byte = ss.str();
        result.key.push_back(hex_byte[0]); // MSB
        result.key.push_back(hex_byte[1]); // LSB
    }

    for (const auto& byte : iv) {
        std::stringstream ss;
        ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(byte);
        std::string hex_byte = ss.str();
        result.iv.push_back(hex_byte[0]); // MSB
        result.iv.push_back(hex_byte[1]); // LSB
    }

    return result;
}


int main()
{
    std::string hexKeyInput, hexIVInput;
    KeyAndIV GenKeyAndIV = generateKeyAndIV(size, size);

    std::string path = "C:\\maldev\\text.txt";
    std::string path1 = "C:\\maldev\\output.kma";

    AESEncryptCBC(path, path1, GenKeyAndIV.key, GenKeyAndIV.iv);

    //AESDecryptCBC(path1, path1, GenKeyAndIV.key, GenKeyAndIV.iv);

    return 0;
}
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

void encrypt(const std::string& path, int& e, int& n) {
    std::fstream file(path, std::ios::binary | std::ios::in | std::ios::out);

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << path << std::endl;
        return;
    }

    char byte;
    while (file.read(&byte, 1)) {
        char text = static_cast<int>(static_cast<unsigned char>(byte));
        char cipher = static_cast<char>(static_cast<int>(std::fmod(std::pow(text, e), n)));

        file.seekp(-1, std::ios::cur);
        file.put(cipher);
    }

    file.close();
}
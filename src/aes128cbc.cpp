#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <array>
#include <random>
#include <sstream>
#include <fstream>
#include <bitset>
#include "AES_128_CBC.h"

// Hàm sinh key và iv ngẫu nhiên
void generateKeyAndIV(uint8_t *key, uint8_t *iv, int SIZE) {
    std::random_device rd;
    std::mt19937 gen(rd()); 

    std::uniform_int_distribution<> dis(0, 255); // Đổi giá trị từ 0 đến 255 để tạo byte ngẫu nhiên

    // Sinh key ngẫu nhiên
    for (int i = 0; i < SIZE; ++i) {
        key[i] = static_cast<uint8_t>(dis(gen)); // Ép kiểu sang uint8_t
    }

    // Sinh IV ngẫu nhiên
    for (int i = 0; i < SIZE; ++i) {
        iv[i] = static_cast<uint8_t>(dis(gen)); // Ép kiểu sang uint8_t
    }

}

void output(const char* title, uint8_t *data, uint32_t size) {
    std::cout << title; // Xuất chuỗi tiêu đề

    // Đặt các phép toán xuất chuỗi dưới dạng hex
    for (uint32_t index = 0; index < size; index++) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<uint32_t>(data[index]);
    }

    std::cout << std::endl; // Xuống dòng sau khi xuất xong
}

std::string ToHex(const std::string& s, bool upper_case)
{
    std::ostringstream ret;

    for (std::string::size_type i = 0; i < s.length(); ++i)
    {
        int z = s[i] & 0xff;
        ret << std::hex << "0x" << std::setfill('0') << std::setw(2) << (upper_case ? std::uppercase : std::nouppercase) << z;
        if (i < s.length() - 1)
            ret << " ";
    }

    return ret.str();
}

void readFiles(std::string inputPath) {
    std::ifstream f(inputPath, std::ios::in|std::ios::binary|std::ios::ate);
    std::streampos size;
    char *memblock;

    if (f.is_open()) {
        size = f.tellg();
    memblock = new char [size];
    f.seekg (0, std::ios::beg);
    f.read (memblock, size);
    f.close();

    std::string tohexed = ToHex(std::string(memblock, size), true);
    std::cout << tohexed << std::endl;
    delete[] memblock;
    }
}



int main() {
    // Example Key (128 bits / 16 bytes)
    uint8_t key[16];

    // Example IV (128 bits / 16 bytes)
    uint8_t iv[16];
    const int SIZE = 16;
    generateKeyAndIV(key, iv, SIZE);

    readFiles("..\\..\\files\\test.txt");
    // Example Data (32 bytes)
    //uint8_t data[48] = {0x54, 0x68, 0x69, 0x73, 0x20, 0x69, 0x73, 0x20, 0x61, 0x20, 0x73, 0x69, 0x6d, 0x70, 0x6c, 0x65,
    //                    0x20, 0x41, 0x45, 0x53, 0x2d, 0x31, 0x32, 0x38, 0x2d, 0x43, 0x42, 0x43, 0x20, 0x65, 0x78, 0x61,
    //                    0x20, 0x41, 0x45, 0x53, 0x2d, 0x31, 0x32, 0x38, 0x2d, 0x43, 0x42, 0x43, 0x20, 0x65, 0x78};
//
    //output("original block 1: 0x", data, 16);
    //output("original block 2: 0x", data + 16, 16);
    //output("original block 3: 0x", data + 32, 16);
//
    //AES_CTX ctx;
    //AES_EncryptInit(&ctx, key, iv);
//
    //for (unsigned int offset = 0; offset < 48; offset += 16) {
    //    AES_Encrypt(&ctx, data + offset, data + offset);
    //}
//
    //output("\nencrypted block 1: 0x", data, 16);
    //output("encrypted block 2: 0x", data + 16, 16);
    //output("encrypted block 3: 0x", data + 32, 16);

    // Decryption Example
    //AES_DecryptInit(&ctx, key, iv);
//
    //for (unsigned int offset = 0; offset < 48; offset += 16) {
    //    AES_Decrypt(&ctx, data + offset, data + offset);
    //}
//
    //output("\ndecrypted block 1: 0x", data, 16);
    //output("decrypted block 2: 0x", data + 16, 16);
    //output("decrypted block 3: 0x", data + 32, 16);

    return 0;
}
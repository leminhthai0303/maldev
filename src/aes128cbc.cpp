#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <array>
#include <random>
#include <sstream>
#include "AES_128_CBC.h"

// Định nghĩa cấu trúc KeyAndIV với key và iv là mảng uint8_t có kích thước cố định
struct KeyAndIV {
    std::array<uint8_t, 16> key; // Key có kích thước 16 byte
    std::array<uint8_t, 16> iv;  // IV có kích thước 16 byte
};

const int size = 16;

// Hàm sinh key và iv ngẫu nhiên
KeyAndIV generateKeyAndIV(int key_size, int iv_size) {
    std::random_device rd;
    std::mt19937 gen(rd()); 

    std::uniform_int_distribution<> dis(0, 15); // Đổi giá trị từ 0 đến 255 để tạo byte ngẫu nhiên

    KeyAndIV result;

    // Sinh key ngẫu nhiên
    for (int i = 0; i < 16; ++i) {
        result.key[i] = static_cast<uint8_t>(dis(gen)); // Ép kiểu sang uint8_t
    }

    // Sinh IV ngẫu nhiên
    for (int i = 0; i < 16; ++i) {
        result.iv[i] = static_cast<uint8_t>(dis(gen)); // Ép kiểu sang uint8_t
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

int main() {
    // Example Key (128 bits / 16 bytes)
    uint8_t key[16] = {0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x97, 0x99, 0x89, 0xcf, 0xab, 0x12};

    // Example IV (128 bits / 16 bytes)
    uint8_t iv[16] = {0x0f, 0x47, 0x0e, 0x7f, 0x75, 0x9c, 0x47, 0x0f, 0x42, 0xc6, 0xd3, 0x9c, 0xbc, 0x8e, 0x23, 0x25};

    // Example Data (32 bytes)
    uint8_t data[48] = {0x54, 0x68, 0x69, 0x73, 0x20, 0x69, 0x73, 0x20, 0x61, 0x20, 0x73, 0x69, 0x6d, 0x70, 0x6c, 0x65,
                        0x20, 0x41, 0x45, 0x53, 0x2d, 0x31, 0x32, 0x38, 0x2d, 0x43, 0x42, 0x43, 0x20, 0x65, 0x78, 0x61,
                        0x20, 0x41, 0x45, 0x53, 0x2d, 0x31, 0x32, 0x38, 0x2d, 0x43, 0x42, 0x43, 0x20, 0x65, 0x78};

    output("original block 1: 0x", data, 16);
    output("original block 2: 0x", data + 16, 16);
    output("original block 3: 0x", data + 32, 16);

    AES_CTX ctx;
    AES_EncryptInit(&ctx, key, iv);

    for (unsigned int offset = 0; offset < 48; offset += 16) {
        AES_Encrypt(&ctx, data + offset, data + offset);
    }

    output("\nencrypted block 1: 0x", data, 16);
    output("encrypted block 2: 0x", data + 16, 16);
    output("encrypted block 3: 0x", data + 32, 16);

    // Decryption Example
    AES_DecryptInit(&ctx, key, iv);

    for (unsigned int offset = 0; offset < 48; offset += 16) {
        AES_Decrypt(&ctx, data + offset, data + offset);
    }

    output("\ndecrypted block 1: 0x", data, 16);
    output("decrypted block 2: 0x", data + 16, 16);
    output("decrypted block 3: 0x", data + 32, 16);

    return 0;
}
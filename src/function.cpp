#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>
#include <random>
#include "AES_128_CBC.h"

const int SIZE = 16;

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

namespace fs = std::filesystem;

struct FileItem
{
    std::string name;
    bool isDirectory;
};

std::vector<FileItem> listFilesAndDirectories(const std::string &path)
{
    std::vector<FileItem> result;
    try
    {
        for (const auto &entry : fs::directory_iterator(path))
        {
            if (fs::is_directory(entry.path()))
            {
                result.push_back({entry.path().filename().string(), true});
            }
            else
            {
                result.push_back({entry.path().filename().string(), false});
            }
        }
    }
    catch (const fs::filesystem_error &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return result;
}

// Function to increase the size of a string to the nearest multiple of 16
std::string increaseSizeofString(const std::string &input)
{
    size_t currentSize = input.size();
    size_t newSize = ((currentSize + 15) / 16) * 16;
    if (newSize > currentSize)
    {
        return input + std::string(newSize - currentSize, '\0');
    }
    return input;
}

// Function to read the content of a file into a single string
std::string readFiles(const std::string &filePath)
{
    std::ifstream file(filePath, std::ios::binary);
    if (!file.is_open())
    {
        std::cerr << "Failed to open file: " << filePath << std::endl;
        return "";
    }

    // Determine file size
    file.seekg(0, std::ios::end);
    std::streampos fileSize = file.tellg();
    file.seekg(0, std::ios::beg);

    // Read the entire file content into a string
    std::string fileContent(fileSize, '\0');
    file.read(&fileContent[0], fileSize);
    file.close();

    // Increase size to nearest multiple of 16 if necessary
    fileContent = increaseSizeofString(fileContent);

    return fileContent;
}

void print(const std::vector<FileItem> &items, const std::string &prefix, const std::string &currentPath, uint8_t *key, uint8_t *iv)
{
    for (const auto &item : items)
    {
        std::cout << prefix;
        if (item.isDirectory)
        {
            std::string newPath = currentPath + item.name + "/";
            std::vector<FileItem> subItems = listFilesAndDirectories(newPath);
            print(subItems, prefix + "  ", newPath, key, iv);
        }
        else
        {
            std::string fileContent = readFiles(currentPath + item.name);
            int size = fileContent.size();
            uint8_t data[size];
            for (size_t i = 0; i < size; i++)
            {
                data[i] = static_cast<uint8_t>(fileContent[i]);
            }

            for(int i = 0; i< size/16; i ++){
                char title[50];
                sprintf(title, "original block %d: 0x", i + 1);
                output(title, data + i * 16, 16);
            }

            AES_CTX ctx;
            AES_EncryptInit(&ctx, key, iv);

            for (unsigned int offset = 0; offset < size; offset += 16)
            {
                AES_Encrypt(&ctx, data + offset, data + offset);
            }
            std::cout << std::endl;
            for(int i = 0; i< size/16; i ++){
                char title[50];
                sprintf(title, "encrypted block %d: 0x", i + 1);
                output(title, data + i * 16, 16);
            }

            AES_DecryptInit(&ctx, key, iv);
             for (unsigned int offset = 0; offset < size; offset += 16)
            {
                AES_Decrypt(&ctx, data + offset, data + offset);
            }
            std::cout << std::endl;
            for(int i = 0; i< size/16; i ++){
                char title[50];
                sprintf(title, "decrypted block %d: 0x", i + 1);
                output(title, data + i * 16, 16);
            }
            std::cout << std::endl;
        }
    }
}
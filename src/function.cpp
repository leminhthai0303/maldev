#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>
#include <random>
#include "AES_128_CBC.h"

namespace fs = std::filesystem;

const int SIZE = 16;

const std::string keyFilename = "key.txt";
const std::string ivFilename = "iv.txt";

void generateKeyAndIV(uint8_t *key, uint8_t *iv, int size)
{
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> dis(0, 255);

    // Generate random key
    for (int i = 0; i < size; ++i)
    {
        key[i] = static_cast<uint8_t>(dis(gen));
        iv[i] = static_cast<uint8_t>(dis(gen));
    }
}

void saveToFile(const std::string &filename, const uint8_t *data, int size)
{
    std::ofstream file(filename, std::ios::binary);
    if (file.is_open())
    {
        file.write(reinterpret_cast<const char *>(data), size);
        file.close();
    }
}

void readFromFile(const std::string &filename, uint8_t *data, int size)
{
    std::ifstream file(filename, std::ios::binary);
    if (file.is_open())
    {
        file.read(reinterpret_cast<char *>(data), size);
        file.close();
    }
}

bool filesExist(const std::string &file1, const std::string &file2)
{
    return (fs::exists(file1) && fs::exists(file2));
}

void genKeyIfNeeded(uint8_t *key, uint8_t *iv)
{
    if (!filesExist(keyFilename, ivFilename))
    {
        generateKeyAndIV(key, iv, SIZE);
        saveToFile(keyFilename, key, SIZE);
        saveToFile(ivFilename, iv, SIZE);
    }
}

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

void enc(const std::vector<FileItem> &items, const std::string &prefix, const std::string &currentPath, const uint8_t *key, const uint8_t *iv)
{
    for (const auto &item : items)
    {
        std::cout << prefix;
        if (item.isDirectory)
        {
            std::string newPath = currentPath + item.name + "\\";
            std::vector<FileItem> subItems = listFilesAndDirectories(newPath);
            enc(subItems, prefix + "  ", newPath, key, iv);
        }
        else
        {
            std::cout << "File: " << item.name << std::endl;
            std::string fileContent = readFiles(currentPath + item.name);
            int size = fileContent.size();
            uint8_t data[size];
            for (size_t i = 0; i < size; i++)
            {
                data[i] = static_cast<uint8_t>(fileContent[i]);
            }

            AES_CTX ctx;
            AES_EncryptInit(&ctx, key, iv);

            for (unsigned int offset = 0; offset < size; offset += 16)
            {
                AES_Encrypt(&ctx, data + offset, data + offset);
            }
            std::cout << "Encrypted" << std::endl;
            saveToFile(currentPath + item.name, data, sizeof(data));
        }
    }
}

void dec(const std::vector<FileItem> &items, const std::string &prefix, const std::string &currentPath, const uint8_t *key, const uint8_t *iv)
{
    for (const auto &item : items)
    {
        std::cout << prefix;
        if (item.isDirectory)
        {
            std::string newPath = currentPath + item.name + "\\";
            std::vector<FileItem> subItems = listFilesAndDirectories(newPath);
            dec(subItems, prefix + "  ", newPath, key, iv);
        }
        else
        {
            std::cout << "File: " << item.name << std::endl;
            std::string fileContent = readFiles(currentPath + item.name);
            int size = fileContent.size();
            uint8_t data[size];
            for (size_t i = 0; i < size; i++)
            {
                data[i] = static_cast<uint8_t>(fileContent[i]);
            }

            AES_CTX ctx;
            AES_DecryptInit(&ctx, key, iv);

            for (unsigned int offset = 0; offset < size; offset += 16)
            {
                AES_Decrypt(&ctx, data + offset, data + offset);
            }

            std::cout << "Decrypted" << std::endl;
            saveToFile(currentPath + item.name, data, sizeof(data));
        }
    }
}
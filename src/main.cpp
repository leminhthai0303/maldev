#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <cmath>
#include "listnprint.cpp"

int main() {
    srand(time(NULL));
    
    RSA::primefiller();
    RSA::setkeys();
    
    std::string path = "C:\\test\\";
    std::vector<FileItem> filesAndDirs = listFilesAndDirectories(path);

    // readPublicKeyFromFile();
    // encoder(filesAndDirs, path);

    // readPrivateKeyFromFile();
    // decoder(filesAndDirs, path);

    return 0;
}
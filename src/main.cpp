<<<<<<< HEAD
#include "../include/rsa.h"
=======
>>>>>>> 8dd77fc8f4ea5398280231f502f5e9233bf44cd9
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <cmath>
<<<<<<< HEAD

using namespace std;
namespace fs = std::filesystem;

void fileEnum(string path) {
    try {
        for (const auto& entry : fs::directory_iterator(path)) {
            cout << entry.path() << endl; 
        }
    } catch (const fs::filesystem_error& ex){
        cerr << "Error accessing path" << ex.what() << endl;
    }
}

void openFile(ofstream &f) {
    f.open("test.txt");
    if (f.is_open()) {
        f << "Hello, World! This was printed using function" << endl;
        f.close();
    }
    else {
        cerr << "Unable to open file" << endl;
    }
}

int main() {
    int e, d, n;
    keyGen(e, d, n);
    cout << e << " " << d << " " << n << endl;
=======
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
>>>>>>> 8dd77fc8f4ea5398280231f502f5e9233bf44cd9
}
#include "../include/rsa.h"
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <cmath>

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
}
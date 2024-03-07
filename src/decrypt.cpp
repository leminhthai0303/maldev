#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Decrypt {
private:
    int private_key;
    int n;

public:
    Decrypt() {
        readPrivateKeyFromFile();
    }

    void readPrivateKeyFromFile() {
        std::ifstream privateKeyFile("private.txt");
        if (privateKeyFile.is_open()) {
            privateKeyFile >> private_key;
            privateKeyFile >> n;
            privateKeyFile.close();
        }
    }

    long long int decrypt(int encrypted_text) {
        int d = private_key;
        long long int decrypted = 1;
        while (d--) {
            decrypted *= encrypted_text;
            decrypted %= n;
        }
        return decrypted;
    }

    std::string decode(std::vector<int> encoded) {
        std::string s;
        for (auto& num : encoded)
            s += decrypt(num);
        return s;
    }
};
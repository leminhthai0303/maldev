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

// int main() {
//     Decrypt decryptor;

//     decryptor.readPrivateKeyFromFile();

//     std::vector<int> encoded_message = {693, 101, 612, 200, 39, 287, 101, 612, 612, 685, 229, 101};

//     std::string decoded_message = decryptor.decode(encoded_message);
//     std::cout << "Decoded message: " << decoded_message << std::endl;

//     return 0;
// }
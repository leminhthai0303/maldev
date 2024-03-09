#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Encrypt {
private:
    int public_key;
    int n;

public:
    Encrypt() {
        readPublicKeyFromFile();
    }

    void readPublicKeyFromFile() {
        std::ifstream publicKeyFile("public.txt");
        if (publicKeyFile.is_open()) {
            publicKeyFile >> public_key;
            publicKeyFile >> n;
            publicKeyFile.close();
        }
    }

    long long int encrypt(double message) {
        int e = public_key;
        long long int encrypted_text = 1;
        while (e--) {
            encrypted_text *= message;
            encrypted_text %= n;
        }
        return encrypted_text;
    }

    std::vector<int> encode(std::string message) {
        std::vector<int> form;
        for (auto& letter : message)
            form.push_back(encrypt((int)letter));
        return form;
    }
};

// int main() {
//     Encrypt encryptor;

//     std::string message = "Test Message";

//     encryptor.readPublicKeyFromFile();

//     std::vector<int> encoded_message = encryptor.encode(message);

// 	for (auto& p : encoded_message)
// 		std::cout << p << " ";
//     std::cout << std::endl;

//     return 0;
// }
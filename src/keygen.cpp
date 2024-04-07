//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <numeric>
#include <fstream> // For file operations
#include <random>  // For random number generation

namespace RSA {
    std::set<int> prime;
    int public_key;
    int private_key;
    int n;

    void primefiller() {
        std::vector<bool> seive(250, true);
        seive[0] = false;
        seive[1] = false;
        for (int i = 2; i < 250; i++) {
            for (int j = i * 2; j < 250; j += i) {
                seive[j] = false;
            }
        }
        for (int i = 0; i < seive.size(); i++) {
            if (seive[i])
                prime.insert(i);
        }
    }

    int pickrandomprime() {
        int k = rand() % prime.size(); // Select a random index
        auto it = prime.begin();
        advance(it, k); // Move iterator to the k-th element
        int ret = *it;
        prime.erase(it); // Remove the chosen prime number
        return ret;
    }

    void setkeys() {
        // Check if public.txt already exists
        std::ifstream publicFileCheck("public.txt");
        if (publicFileCheck) {
            // File exists, so no need to generate keys
            publicFileCheck.close();
            return;
        }

        int prime1 = pickrandomprime(); // first prime number
        int prime2 = pickrandomprime(); // second prime number
        n = prime1 * prime2;
        int fi = (prime1 - 1) * (prime2 - 1);
        int e = 2;
        while (std::gcd(e, fi) != 1) {
            e++;
        }
        public_key = e;
        int d = 2;
        while ((d * e) % fi != 1) {
            d++;
        }
        private_key = d;

        // Save public and private keys to files
        std::ofstream publicKeyFile("public.txt");
        if (publicKeyFile.is_open()) {
            publicKeyFile << public_key << std::endl;
            publicKeyFile << n << std::endl;
            publicKeyFile.close();
        }

        std::ofstream privateKeyFile("private.txt");
        if (privateKeyFile.is_open()) {
            privateKeyFile << private_key << std::endl;
            privateKeyFile << n << std::endl;
            privateKeyFile.close();
        }
    }
} // namespace RSA

// int main(){
//     RSA::primefiller();
//     RSA::setkeys();
// }

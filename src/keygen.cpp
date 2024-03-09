#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <numeric>
#include <fstream> // For file operations
#include <random>  // For random number generation

std::set<int> prime;
int public_key;
int private_key;
int n;

void primefiller() {
    std::vector<bool> sieve(250, true);
    sieve[0] = false;
    sieve[1] = false;
    for (int i = 2; i < 250; i++) {
        for (int j = i * 2; j < 250; j += i) {
            sieve[j] = false;
        }
    }
    for (int i = 0; i < sieve.size(); i++) {
        if (sieve[i])
            prime.insert(i);
    }
}

int pickrandomprime() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, prime.size() - 1);

    auto it = prime.begin();
    std::advance(it, dis(gen));

    int ret = *it;
    prime.erase(it);
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
    
    int prime1 = pickrandomprime();
    int prime2 = pickrandomprime();
    n = prime1 * prime2;
    int phi_n = (prime1 - 1) * (prime2 - 1);
    int e = 2;
    while (1) {
        if (std::gcd(e, phi_n) == 1)
            break;
        e++;
    }
    public_key = e;
    int d = 2;
    while (1) {
        if ((d * e) % phi_n == 1)
            break;
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
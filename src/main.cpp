#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <cmath>

using namespace std;
namespace fs = std::filesystem;

// Check if a number is a prime number
bool isPrime(int n) {
    if (n <= 1) return false;

    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

// Generate a random prime number
int randPrime() {
    srand((unsigned int)time(NULL));
    int randNum, num;
    do {
    randNum = rand();
    if (randNum > 1000)
        num = randNum % 100000;
    else
        continue;
    } while (!isPrime(num));
    return num;
}

// Calculate gcd of 2 numbers
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Calculate modular inverse
int modInverse(int A, int M)
{
    for (int X = 1; X < M; X++)
        if (((A % M) * (X % M)) % M == 1)
            return X;
}

void keyGen(int &e, int &d, int &n) {
    // Create 2 prime numbers
    int p = randPrime();
    int q = randPrime();

    // Calculate Modulus Number (n)
    int n = p * q;

    // Calculate Phi Number (phi(n))
    int phi = (p-1) * (q-1);

    // Generate public exponent number (e) with 2 conditions {(1 < e < phi) && (gcd(e, phi) == 1)}
    do {
        e = randPrime() % 1000;
    } while ( (1 < e < phi) && (gcd(e, phi) != 1));

    d = modInverse(e, phi);
}

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
}
#include <string>
#include <filesystem>
#include <cmath>
#include "../include/rsa.h"

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
    num = randNum % 10000;
    } while (!isPrime(num) && num > 100);
    return num;
}

// Calculate gcd of 2 numbers
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Calculate modular inverse
int modInverse(int A, int M) {
    for (int X = 1; X < M; X++) {
        if (((A % M) * (X % M)) % M == 1) {
            return X;
        }
    }
    return -1;
}

void keyGen(int &e, int &d, int &n) {
    // Create 2 prime numbers
    int p = randPrime();
    int q = randPrime();

    // Calculate Modulus Number (n)
    n = p * q;

    // Calculate Phi Number (phi(n))
    int phi = (p-1) * (q-1);

    // Generate public exponent number (e) with 2 conditions {(1 < e < phi) && (gcd(e, phi) == 1)}
    do {
        e = randPrime() % 10000;
    } while ( (1 < e < phi) && (gcd(e, phi) != 1));

    d = modInverse(e, phi);

    while (d == -1) {
        // Regenerate e
        e = randPrime() % 10000;

        // Recalculate d
        d = modInverse(e, phi);
    }
}

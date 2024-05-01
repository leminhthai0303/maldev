#include "function.cpp"

int main()
{
    uint8_t key[16];
    uint8_t iv[16];
    generateKeyAndIV(key, iv, size);
    saveKeyAndIVToDesktop("secret.kma", key, iv, size);
    return 0;
}
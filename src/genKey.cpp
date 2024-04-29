#include "function.cpp"

int main()
{
    uint8_t key[16];
    uint8_t iv[16];
    genKeyIfNeeded(key, iv);
    
    return 0;
}
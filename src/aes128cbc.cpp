#include <iostream>
#include <vector>
#include <random>
#include <cstring>

// AES S-Box
const unsigned char sbox[256] = {
    // The S-box values for AES
    0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76,
    0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0,
    0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15,
    0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75,
    0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84,
    0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf,
    0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8,
    0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2,
    0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73,
    0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb,
    0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79,
    0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08,
    0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a,
    0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e,
    0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf,
    0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16};

// AES Inverse S-Box
const unsigned char inv_sbox[256] = {
    // The inverse S-box values for AES
    0x52, 0x09, 0x6a, 0xd5, 0x30, 0x36, 0xa5, 0x38, 0xbf, 0x40, 0xa3, 0x9e, 0x81, 0xf3, 0xd7, 0xfb,
    0x7c, 0xe3, 0x39, 0x82, 0x9b, 0x2f, 0xff, 0x87, 0x34, 0x8e, 0x43, 0x44, 0xc4, 0xde, 0xe9, 0xcb,
    0x54, 0x7b, 0x94, 0x32, 0xa6, 0xc2, 0x23, 0x3d, 0xee, 0x4c, 0x95, 0x0b, 0x42, 0xfa, 0xc3, 0x4e,
    0x08, 0x2e, 0xa1, 0x66, 0x28, 0xd9, 0x24, 0xb2, 0x76, 0x5b, 0xa2, 0x49, 0x6d, 0x8b, 0xd1, 0x25,
    0x72, 0xf8, 0xf6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xd4, 0xa4, 0x5c, 0xcc, 0x5d, 0x65, 0xb6, 0x92,
    0x6c, 0x70, 0x48, 0x50, 0xfd, 0xed, 0xb9, 0xda, 0x5e, 0x15, 0x46, 0x57, 0xa7, 0x8d, 0x9d, 0x84,
    0x90, 0xd8, 0xab, 0x00, 0x8c, 0xbc, 0xd3, 0x0a, 0xf7, 0xe4, 0x58, 0x05, 0xb8, 0xb3, 0x45, 0x06,
    0xd0, 0x2c, 0x1e, 0x8f, 0xca, 0x3f, 0x0f, 0x02, 0xc1, 0xaf, 0xbd, 0x03, 0x01, 0x13, 0x8a, 0x6b,
    0x3a, 0x91, 0x11, 0x41, 0x4f, 0x67, 0xdc, 0xea, 0x97, 0xf2, 0xcf, 0xce, 0xf0, 0xb4, 0xe6, 0x73,
    0x96, 0xac, 0x74, 0x22, 0xe7, 0xad, 0x35, 0x85, 0xe2, 0xf9, 0x37, 0xe8, 0x1c, 0x75, 0xdf, 0x6e,
    0x47, 0xf1, 0x1a, 0x71, 0x1d, 0x29, 0xc5, 0x89, 0x6f, 0xb7, 0x62, 0x0e, 0xaa, 0x18, 0xbe, 0x1b,
    0xfc, 0x56, 0x3e, 0x4b, 0xc6, 0xd2, 0x79, 0x20, 0x9a, 0xdb, 0xc0, 0xfe, 0x78, 0xcd, 0x5a, 0xf4,
    0x1f, 0xdd, 0xa8, 0x33, 0x88, 0x07, 0xc7, 0x31, 0xb1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xec, 0x5f,
    0x60, 0x51, 0x7f, 0xa9, 0x19, 0xb5, 0x4a, 0x0d, 0x2d, 0xe5, 0x7a, 0x9f, 0x93, 0xc9, 0x9c, 0xef,
    0xa0, 0xe0, 0x3b, 0x4d, 0xae, 0x2a, 0xf5, 0xb0, 0xc8, 0xeb, 0xbb, 0x3c, 0x83, 0x53, 0x99, 0x61,
    0x17, 0x2b, 0x04, 0x7e, 0xba, 0x77, 0xd6, 0x26, 0xe1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0c, 0x7d};

// Round constant array
const unsigned char Rcon[10] = {
    0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1B, 0x36};

// Khởi tạo IV ngẫu nhiên
void GenerateIV(unsigned char *iv)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, 15);
    for (int i = 0; i < 16; ++i)
    {
        iv[i] = static_cast<unsigned char>(dis(gen));
    }
}

// Khởi tạo khóa ngẫu nhiên
void GenerateKey(unsigned char *key)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, 15);
    for (int i = 0; i < 16; ++i)
    {
        key[i] = static_cast<unsigned char>(dis(gen));
    }
}

// Hàm nhân 2 trong trường Galois
unsigned char mul2(unsigned char val)
{
    if (val < 0x80)
    {
        return val << 1;
    }
    else
    {
        return (val << 1) ^ 0x1b; // XOR với 0x1b nếu bit cao của val bằng 1
    }
}

// Hàm nhân 3 trong trường Galois
unsigned char mul3(unsigned char val)
{
    return mul2(val) ^ val;
}

// Hàm nhân 9 trong trường Galois
unsigned char mul9(unsigned char val)
{
    return mul2(mul2(mul2(val))) ^ val;
}

// Hàm nhân 11 trong trường Galois
unsigned char mul11(unsigned char val)
{
    return mul2(mul2(mul2(val)) ^ val) ^ val;
}

// Hàm nhân 13 trong trường Galois
unsigned char mul13(unsigned char val)
{
    return mul2(mul2(mul2(val)) ^ mul2(val)) ^ val;
}

// Hàm nhân 14 trong trường Galois
unsigned char mul14(unsigned char val)
{
    return mul2(mul2(mul2(val)) ^ mul2(val) ^ val);
}

// Key Expansion
void KeyExpansion(const unsigned char *key, unsigned char *roundKeys)
{
    const int Nk = 4;  // Number of columns in key
    const int Nb = 4;  // Number of columns in state (AES is always 4)
    const int Nr = 10; // Number of rounds

    unsigned char temp[4];
    int i = 0;

    // Copy the original key to the first 16 bytes of the roundKeys
    for (; i < Nk * 4; ++i)
    {
        roundKeys[i] = key[i];
    }

    // Generate the remaining bytes of the roundKeys
    while (i < Nb * (Nr + 1) * 4)
    {
        for (int j = 0; j < 4; ++j)
        {
            temp[j] = roundKeys[i - 4 + j];
        }

        if (i / 16 % Nk == 0)
        {
            // RotWord
            unsigned char tmp = temp[0];
            temp[0] = temp[1];
            temp[1] = temp[2];
            temp[2] = temp[3];
            temp[3] = tmp;

            // SubWord
            for (int j = 0; j < 4; ++j)
            {
                temp[j] = sbox[temp[j]];
            }

            temp[0] ^= Rcon[i / 16 / Nk - 1];
        }
        else if (Nk > 6 && i / 16 % Nk == 4)
        {
            // SubWord
            for (int j = 0; j < 4; ++j)
            {
                temp[j] = sbox[temp[j]];
            }
        }

        for (int j = 0; j < 4; ++j)
        {
            roundKeys[i] = roundKeys[i - Nk * 4] ^ temp[j];
            ++i;
        }
    }
}

// Substitution Bytes
void SubBytes(unsigned char *state)
{
    for (int i = 0; i < 16; ++i)
    {
        state[i] = sbox[state[i]];
    }
}

// Shift Rows
void ShiftRows(unsigned char *state)
{
    unsigned char tmp[16];
    for (int i = 0; i < 16; ++i)
    {
        tmp[i] = state[i];
    }

    state[1] = tmp[5];
    state[5] = tmp[9];
    state[9] = tmp[13];
    state[13] = tmp[1];

    state[2] = tmp[10];
    state[6] = tmp[14];
    state[10] = tmp[2];
    state[14] = tmp[6];

    state[3] = tmp[15];
    state[7] = tmp[3];
    state[11] = tmp[7];
    state[15] = tmp[11];
}

// Mix Columns
void MixColumns(unsigned char *state)
{
    unsigned char tmp[16];
    for (int i = 0; i < 16; ++i)
    {
        tmp[i] = state[i];
    }

    state[0] = (unsigned char)(mul2(tmp[0]) ^ mul3(tmp[1]) ^ tmp[2] ^ tmp[3]);
    state[1] = (unsigned char)(tmp[0] ^ mul2(tmp[1]) ^ mul3(tmp[2]) ^ tmp[3]);
    state[2] = (unsigned char)(tmp[0] ^ tmp[1] ^ mul2(tmp[2]) ^ mul3(tmp[3]));
    state[3] = (unsigned char)(mul3(tmp[0]) ^ tmp[1] ^ tmp[2] ^ mul2(tmp[3]));

    state[4] = (unsigned char)(mul2(tmp[4]) ^ mul3(tmp[5]) ^ tmp[6] ^ tmp[7]);
    state[5] = (unsigned char)(tmp[4] ^ mul2(tmp[5]) ^ mul3(tmp[6]) ^ tmp[7]);
    state[6] = (unsigned char)(tmp[4] ^ tmp[5] ^ mul2(tmp[6]) ^ mul3(tmp[7]));
    state[7] = (unsigned char)(mul3(tmp[4]) ^ tmp[5] ^ tmp[6] ^ mul2(tmp[7]));

    state[8] = (unsigned char)(mul2(tmp[8]) ^ mul3(tmp[9]) ^ tmp[10] ^ tmp[11]);
    state[9] = (unsigned char)(tmp[8] ^ mul2(tmp[9]) ^ mul3(tmp[10]) ^ tmp[11]);
    state[10] = (unsigned char)(tmp[8] ^ tmp[9] ^ mul2(tmp[10]) ^ mul3(tmp[11]));
    state[11] = (unsigned char)(mul3(tmp[8]) ^ tmp[9] ^ tmp[10] ^ mul2(tmp[11]));

    state[12] = (unsigned char)(mul2(tmp[12]) ^ mul3(tmp[13]) ^ tmp[14] ^ tmp[15]);
    state[13] = (unsigned char)(tmp[12] ^ mul2(tmp[13]) ^ mul3(tmp[14]) ^ tmp[15]);
    state[14] = (unsigned char)(tmp[12] ^ tmp[13] ^ mul2(tmp[14]) ^ mul3(tmp[15]));
    state[15] = (unsigned char)(mul3(tmp[12]) ^ tmp[13] ^ tmp[14] ^ mul2(tmp[15]));
}

// Add Round Key
void AddRoundKey(unsigned char *state, const unsigned char *roundKey)
{
    for (int i = 0; i < 16; ++i)
    {
        state[i] ^= roundKey[i];
    }
}

void AESEncryptCBC(const unsigned char *plaintext, unsigned char *ciphertext, const unsigned char *key, const unsigned char *iv)
{
    unsigned char state[16];
    unsigned char roundKeys[176];

    // Khởi tạo round keys từ khóa
    KeyExpansion(key, roundKeys);

    // Đặt IV cho block đầu tiên
    std::memcpy(state, iv, 16);

    // Mã hóa từng block của plaintext
    for (size_t i = 0; i < strlen((const char *)plaintext); i += 16)
    {
        // XOR với block trước đó hoặc IV
        for (int j = 0; j < 16; ++j)
        {
            state[j] ^= plaintext[i + j];
        }

        // Thực hiện AES encryption trên block hiện tại
        AddRoundKey(state, key);

        for (int round = 1; round < 10; ++round)
        {
            SubBytes(state);
            ShiftRows(state);
            MixColumns(state);
            AddRoundKey(state, roundKeys + round * 16);
        }

        SubBytes(state);
        ShiftRows(state);
        AddRoundKey(state, roundKeys + 160); // Round 10

        // Sao chép ciphertext vào buffer
        std::memcpy(ciphertext + i, state, 16);
    }
}


//Hàm ngược dùng để decrypt
// Hàm dịch các hàng ngược lại
void InvShiftRows(unsigned char *state)
{
    unsigned char tmp[16];
    for (int i = 0; i < 16; ++i)
    {
        tmp[i] = state[i];
    }

    state[1] = tmp[13];
    state[5] = tmp[9];
    state[9] = tmp[5];
    state[13] = tmp[1];

    state[2] = tmp[10];
    state[6] = tmp[14];
    state[10] = tmp[2];
    state[14] = tmp[6];

    state[3] = tmp[7];
    state[7] = tmp[11];
    state[11] = tmp[15];
    state[15] = tmp[3];
}

// Hàm thực hiện pha giải mã SubBytes
void InvSubBytes(unsigned char *state)
{
    for (int i = 0; i < 16; ++i)
    {
        state[i] = inv_sbox[state[i]];
    }
}

// Hàm thực hiện pha giải mã MixColumns
void InvMixColumns(unsigned char *state)
{
    unsigned char tmp[16];
    for (int i = 0; i < 16; ++i)
    {
        tmp[i] = state[i];
    }

    state[0] = (unsigned char)(mul14(tmp[0]) ^ mul11(tmp[1]) ^ mul13(tmp[2]) ^ mul9(tmp[3]));
    state[1] = (unsigned char)(mul9(tmp[0]) ^ mul14(tmp[1]) ^ mul11(tmp[2]) ^ mul13(tmp[3]));
    state[2] = (unsigned char)(mul13(tmp[0]) ^ mul9(tmp[1]) ^ mul14(tmp[2]) ^ mul11(tmp[3]));
    state[3] = (unsigned char)(mul11(tmp[0]) ^ mul13(tmp[1]) ^ mul9(tmp[2]) ^ mul14(tmp[3]));

    state[4] = (unsigned char)(mul14(tmp[4]) ^ mul11(tmp[5]) ^ mul13(tmp[6]) ^ mul9(tmp[7]));
    state[5] = (unsigned char)(mul9(tmp[4]) ^ mul14(tmp[5]) ^ mul11(tmp[6]) ^ mul13(tmp[7]));
    state[6] = (unsigned char)(mul13(tmp[4]) ^ mul9(tmp[5]) ^ mul14(tmp[6]) ^ mul11(tmp[7]));
    state[7] = (unsigned char)(mul11(tmp[4]) ^ mul13(tmp[5]) ^ mul9(tmp[6]) ^ mul14(tmp[7]));

    state[8] = (unsigned char)(mul14(tmp[8]) ^ mul11(tmp[9]) ^ mul13(tmp[10]) ^ mul9(tmp[11]));
    state[9] = (unsigned char)(mul9(tmp[8]) ^ mul14(tmp[9]) ^ mul11(tmp[10]) ^ mul13(tmp[11]));
    state[10] = (unsigned char)(mul13(tmp[8]) ^ mul9(tmp[9]) ^ mul14(tmp[10]) ^ mul11(tmp[11]));
    state[11] = (unsigned char)(mul11(tmp[8]) ^ mul13(tmp[9]) ^ mul9(tmp[10]) ^ mul14(tmp[11]));

    state[12] = (unsigned char)(mul14(tmp[12]) ^ mul11(tmp[13]) ^ mul13(tmp[14]) ^ mul9(tmp[15]));
    state[13] = (unsigned char)(mul9(tmp[12]) ^ mul14(tmp[13]) ^ mul11(tmp[14]) ^ mul13(tmp[15]));
    state[14] = (unsigned char)(mul13(tmp[12]) ^ mul9(tmp[13]) ^ mul14(tmp[14]) ^ mul11(tmp[15]));
    state[15] = (unsigned char)(mul11(tmp[12]) ^ mul13(tmp[13]) ^ mul9(tmp[14]) ^ mul14(tmp[15]));
}

int main()
{
    unsigned char plaintext[16] = "hello world!!!";
    unsigned char key[16];
    GenerateKey(key);
    std::cout << "key: ";
    for (int i = 0; i < 16; ++i)
    {
        std::cout << std::hex << (int)key[i];
    }
    std::cout << std::endl;
    unsigned char iv[16];
    GenerateIV(iv);
    std::cout << "iv: ";
    for (int i = 0; i < 16; ++i)
    {
        std::cout << std::hex << (int)iv[i];
    }
    std::cout << std::endl;
    unsigned char ciphertext[16];

    AESEncryptCBC(plaintext, ciphertext, key, iv);

    std::cout << "Cipher text: ";
    for (int i = 0; i < 16; ++i)
    {
        std::cout << std::hex << (int)ciphertext[i];
    }
    std::cout << std::endl;

    return 0;
}

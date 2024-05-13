#include "function.cpp"

int main()
{
    if (filesExist("secret.kma"))
    {
        uint8_t key[16];
        uint8_t iv[16];

        readKeyAndIVFromDesktop("secret.kma", key, iv, size);

        std::string username = getCurrentUsername();
        std::string path = "C:\\Users\\" + username + "\\";
        std::string OneDrivePath = path + "OneDrive" + "\\";
        std::string folderPath;

        // Các thư mục cần xem
        std::vector<std::string> folders = {"Documents", "Downloads", "Pictures"};

        for (const auto &folder : folders)
        {
            if (fs::exists(OneDrivePath) && fs::is_directory(OneDrivePath) && fs::exists(folder) && fs::is_directory(folder))
            {
                folderPath = OneDrivePath + folder + "\\";
            }
            else
            {
                folderPath = path + folder + "\\";
            }

            // Liệt kê các tệp và thư mục trong thư mục hiện tại
            std::vector<FileItem> items = listFilesAndDirectories(folderPath);

            dec(items, "", folderPath, key, iv);
        }

        deleteKeyAndIV("secret.kma");
    }

    return 0;
}
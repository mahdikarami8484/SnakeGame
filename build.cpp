#include <windows.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>

// تابع بازگشتی برای جستجو در ساب‌فولدرها
void findCppFiles(const std::string& dir, std::vector<std::string>& cppFiles) {
    WIN32_FIND_DATA findFileData;
    HANDLE hFind = FindFirstFile((dir + "\\*").c_str(), &findFileData);

    if (hFind == INVALID_HANDLE_VALUE) {
        return; // فولدر خالی است یا مشکلی وجود دارد
    }

    do {
        const std::string fileName = findFileData.cFileName;
        const std::string filePath = dir + "\\" + fileName;

        // اگر این یک فولدر باشد، وارد آن می‌شویم
        if (findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
            if (fileName != "." && fileName != "..") {
                findCppFiles(filePath, cppFiles); // جستجو در ساب‌فولدر
            }
        }
        else if (fileName.substr(fileName.find_last_of(".") + 1) == "cpp") {
            cppFiles.push_back(filePath); // فایل cpp پیدا شد
        }
    } while (FindNextFile(hFind, &findFileData) != 0);

    FindClose(hFind);
}

void compileProject(const std::string& includeDir, const std::string& srcDir, const std::string& outputFile) {
    std::vector<std::string> cppFiles;

    // پیدا کردن فایل‌های cpp در فولدر و ساب‌فولدرها
    findCppFiles(srcDir, cppFiles);

    if (cppFiles.empty()) {
        std::cerr << "No C++ files found in " << srcDir << std::endl;
        return;
    }

    // ساخت دستور g++ برای کامپایل پروژه
    std::string command = "g++ -I " + includeDir;
    for (const auto& file : cppFiles) {
        command += " \"" + file + "\"";
    }
    command += " -o \"" + outputFile + "\"";

    // اجرای دستور کامپایل
    std::cout << "Running command: " << command << std::endl;
    int result = std::system(command.c_str());

    if (result == 0) {
        std::cout << "Compilation successful: " << outputFile << std::endl;
    } else {
        std::cerr << "Compilation failed!" << std::endl;
    }
}

int main() {
    std::string includeDir = "include";  // مسیر پوشه include
    std::string srcDir = "src";          // مسیر پوشه source
    std::string outputFile = "build\\snake.exe";  // نام فایل خروجی
    compileProject(includeDir, srcDir, outputFile);
    return 0;
}

// main.c - 程序入口
#include <stdio.h>
#include <stdlib.h>
#include "mylib/menu.h"
#include "mylib/play.h"

#ifdef _WIN32
    #include <windows.h>
#else
    #include <locale.h>
#endif

void friend_system_cli() {
    while (1 == 1)
    {
        menu();
        play();
    }
    
}

void main() {
#ifdef _WIN32
    // 设置 Windows 控制台为 UTF-8
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#else
    // Linux/Mac：使用本地语言环境（一般默认 UTF-8）
    setlocale(LC_ALL, "");
#endif

    return friend_system_cli();
}

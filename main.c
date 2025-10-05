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
    play();
}

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#else
    setlocale(LC_ALL, "");
#endif
    friend_system_cli();
    return 0;
}

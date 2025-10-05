#include "fileio.h"
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

#ifdef _WIN32
    #include <direct.h>
#endif

#define MAX_LINE_LENGTH 256

int load_friends_from_csv(const char *filename, Friend *friends, int *friend_count) {
    char filepath[256];
    snprintf(filepath, sizeof(filepath), "data/%s", filename);

    struct stat st = {0};
    if (stat("data", &st) == -1) {
#ifdef _WIN32
        if (_mkdir("data") != 0) {
            perror("无法创建 data 目录");
            return 0;
        }
#else
        if (mkdir("data", 0755) != 0) {
            perror("无法创建 data 目录");
            return 0;
        }
#endif
    }

    // 打开文件，如果不存在则新建
    FILE *file = fopen(filepath, "r");
    if (!file) {
        file = fopen(filepath, "w");
        if (!file) {
            perror("无法创建文件");
            return 0;
        }
        fclose(file);
        file = fopen(filepath, "r");
    }

    char line[MAX_LINE_LENGTH];
    *friend_count = 0;

    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "%d,%49[^,],%d,%9[^,],%199[^\n]",
                    &friends[*friend_count].id, 
                    friends[*friend_count].name, 
                    &friends[*friend_count].qqid, 
                    friends[*friend_count].gender, 
                    friends[*friend_count].desc) == 5) {
            (*friend_count)++;
        }
    }

    fclose(file);
    return 1;
}

int save_friends_to_csv(const char *filename, const Friend *friends, int friend_count) {
    char filepath[256];
    snprintf(filepath, sizeof(filepath), "data/%s", filename);

    FILE *file = fopen(filepath, "w");
    if (!file) {
        perror("无法创建文件");
        return 0;
    }

    for (int i = 0; i < friend_count; i++) {
        fprintf(file, "%d,%s,%d,%s,%s\n", 
                friends[i].id, 
                friends[i].name, 
                friends[i].qqid, 
                friends[i].gender, 
                friends[i].desc);
    }

    fclose(file);
    return 1;
}


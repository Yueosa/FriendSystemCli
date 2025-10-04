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

/*
示例调用
#include <stdio.h>
#include "fileio.h"

#define MAX_FRIENDS 100

int main() {
    Friend friends[MAX_FRIENDS];
    int friend_count = 0;

    // 1. 从 CSV 加载
    if (!load_friends_from_csv("friends.csv", friends, &friend_count)) {
        printf("读取 CSV 失败！\n");
        return 1;
    }
    printf("已加载 %d 个好友\n", friend_count);

    // 2. 添加新好友
    Friend new_friend = { 
        .id = friend_count + 1,
        .qqid = 12345678
    };
    snprintf(new_friend.name, sizeof(new_friend.name), "Alice");
    snprintf(new_friend.gender, sizeof(new_friend.gender), "Female");
    snprintf(new_friend.desc, sizeof(new_friend.desc), "喜欢编程的朋友");

    friends[friend_count++] = new_friend;

    // 3. 保存到 CSV
    if (!save_friends_to_csv("friends.csv", friends, friend_count)) {
        printf("保存 CSV 失败！\n");
        return 1;
    }

    printf("已保存 %d 个好友\n", friend_count);

    // 4. 打印所有好友
    for (int i = 0; i < friend_count; i++) {
        printf("ID=%d, Name=%s, QQ=%d, Gender=%s, Desc=%s\n",
                friends[i].id,
                friends[i].name,
                friends[i].qqid,
                friends[i].gender,
                friends[i].desc);
    }

    return 0;
}
*/
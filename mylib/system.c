#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "system.h"
#include "output.h"
#include "audit.h"

#define MAX_FRIEND 100

static Friend friends[MAX_FRIEND];
static int friend_count = 0;

void system_init() {
    friend_count = 0;
}

int system_add_friend(Friend f) {
    if (friend_count >= MAX_FRIEND) {
        output_error("朋友太多了~塞不下了唔...");
        return 0;
    }
    friends[friend_count++] = f;
    output_info("太好了~是新的朋友...");
    audit_log("ADD", f.name);
    return 1;
}

int system_remove_friend(int id) {
    for (int i = 0; i < friend_count; i++) {
        if (friends[i].id == id) {
            friends[i] = friends[friend_count - 1];
            friend_count--;
            output_info("再见朋友...我会想你的喵...");
            audit_log("DELETE", "删除了没用的朋友");
            return 1;
        }
    }
    output_warning("错误...不存在的对象");
    return 0;
}


Friend* system_find_friend(int id) {
    for (int i = 0; i < friend_count; i++) {
        if (friends[i].id == id) {
            return &friends[i];
        }
    }
    return NULL;
}

void system_list_friends() {
    if (friend_count == 0) {
        output_warning("\n怎么一个朋友都没有...");
        return;
    }
    printf("\n");
    for (int i = 0; i < friend_count; i++) {
        printf("ID: %d | 名字: %s | QQ: %d | 性别: %s | 描述: %s\n",
                friends[i].id,
                friends[i].name,
                friends[i].qqid,
                friends[i].gender,
                friends[i].desc
                );
    }
}

void system_cleanup() {
    friend_count = 0;
}

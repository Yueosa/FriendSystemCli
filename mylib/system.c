#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "system.h" // 系统操作
#include "output.h" // 输出重构
#include "audit.h" // 日志审计
#include "fileio.h" // 本地存储

#include "friend.h" // 朋友类型


#define MAX_FRIEND 100

static Friend friends[MAX_FRIEND];
static int friend_count = 0;

void system_init() {
    friend_count = 0;
}

int system_add_friend(Friend f) {
    if (friend_count >= MAX_FRIEND) {
        output_error("朋友太多了~塞不下了唔...");
        audit_log("ADD_ERROR", f.name);
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
            audit_log("DELETE", friends[i].name);
            return 1;
        }
    }
    output_warning("错误...不存在的对象");
    audit_log("DELETE_ERROR", id);
    return 0;
}


Friend* system_find_friend(int id) {
    for (int i = 0; i < friend_count; i++) {
        if (friends[i].id == id) {
            audit_log("FIND", id);
            return &friends[i];
        }
    }
    audit_log("FIND_ERROR", id);
    return NULL;
}

void system_list_friends() {
    if (friend_count == 0) {
        output_warning("\n怎么一个朋友都没有...");
        audit_log("LIST_ERROR", 0);
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
    audit_log("LIST", 1);
}

void system_cleanup() {
    friend_count = 0;
}
/*
示例调用
#include "system.h"
#include "audit.h"
#include "output.h"
#include <stdio.h>

int main() {
    // 初始化
    system_init();
    audit_init("system.log");

    // 添加好友
    Friend f1 = {1, "Alice", 123456, "Female", "喜欢编程"};
    Friend f2 = {2, "Bob", 654321, "Male", "打游戏的好伙伴"};

    system_add_friend(f1);
    system_add_friend(f2);

    // 列出好友
    system_list_friends();

    // 查找好友
    Friend* f = system_find_friend(1);
    if (f) {
        printf("\n找到好友：%s (QQ: %d)\n", f->name, f->qqid);
    }

    // 删除好友
    system_remove_friend(2);

    // 再次列出
    system_list_friends();

    // 清理
    system_cleanup();
    audit_close();

    return 0;
}

*/

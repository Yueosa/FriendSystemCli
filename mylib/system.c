#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "system.h"
#include "output.h"
#include "audit.h"
#include "fileio.h"

#include "friend.h"


#define MAX_FRIEND 100


static Friend friends[MAX_FRIEND];
static int friend_count = 0;


static void system_cleanup() {
    friend_count = 0;
}


enum STAT system_init() {
    system_cleanup();

    if (load_friends_from_csv("friends.csv", friends, &friend_count)) {
        output_error("无法加载csv");
        return FAILED;
    }

    if (audit_init("audit.log")) {
        output_error("audit初始化失败");
        return FAILED;
    }
    return SUCCESS;
}


static Friend system_get_friend() {
    Friend f;
    char buffer[128];

    printf("输入学生ID: ");
    fgets(buffer, sizeof(buffer), stdin);
    f.id = atoi(buffer);  // 把字符串转成数字，自动忽略非数字部分

    printf("输入姓名: ");
    fgets(f.name, sizeof(f.name), stdin);
    f.name[strcspn(f.name, "\n")] = '\0'; // 去掉换行

    printf("输入QQID: ");
    fgets(buffer, sizeof(buffer), stdin);
    f.qqid = atoi(buffer);

    printf("输入性别: ");
    fgets(f.gender, sizeof(f.gender), stdin);
    f.gender[strcspn(f.gender, "\n")] = '\0';

    printf("输入描述: ");
    fgets(f.desc, sizeof(f.desc), stdin);
    f.desc[strcspn(f.desc, "\n")] = '\0';

    return f;
}


static enum STAT system_add_friend(Friend f) {
    if (friend_count >= MAX_FRIEND) {
        output_error("朋友太多了~塞不下了唔...");
        audit_log("ADD_ERROR", f.name);
        return FAILED;
    }
    friends[friend_count++] = f;
    output_info("太好了~是新的朋友...");
    audit_log("ADD", f.name);
    return SUCCESS;
}


enum STAT system_get_and_add_friend() {
    Friend f = system_get_friend();
    return system_add_friend(f);

}


enum STAT system_remove_friend(int id) {
    for (int i = 0; i < friend_count; i++) {
        if (friends[i].id == id) {
            friends[i] = friends[friend_count - 1];
            friend_count--;
            output_info("再见朋友...我会想你的喵...");
            audit_log("DELETE", friends[i].name);
            return SUCCESS;
        }
    }
    output_warning("错误...不存在的对象");
    char buf[32];
    sprintf(buf, "%d", id);
    audit_log("DELETE_ERROR", buf);
    return FAILED;
}


static Friend* system_find_friend(int id) {
    for (int i = 0; i < friend_count; i++) {
        if (friends[i].id == id) {
            char buf[32];
            sprintf(buf, "%d", id);
            audit_log("FIND", buf);
            return &friends[i];
        }
    }
    char buf[32];
    sprintf(buf, "%d", id);
    audit_log("FIND_ERROR", buf);
    return NULL;
}


void system_find_and_printf(int id) {
    Friend* f = system_find_friend(id);
    if (f != NULL) {
        print_friend(f);
    } else {
        output_warning("对象不存在");
    }
}


enum STAT system_list_friends() {
    if (friend_count == 0) {
        output_warning("\n怎么一个朋友都没有...");
        audit_log("LIST_ERROR", "List is empty");
        return FAILED;
    }
    printf("\n");
    for (int i = 0; i < friend_count; i++) {
        printf("| ID: %d | 名字: %s | QQ: %d | 性别: %s | 描述: %s |\n",
                friends[i].id,
                friends[i].name,
                friends[i].qqid,
                friends[i].gender,
                friends[i].desc
                );
    }
    audit_log("LIST", "Success");
    return SUCCESS;
}


enum STAT system_end() {
    if (save_friends_to_csv("friends.csv", friends, friend_count)) {
        output_error("无法保存数据");
        return FAILED;
    }

    system_cleanup();
    audit_close();
    return SUCCESS;
}

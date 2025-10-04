#include <stdio.h>
#include <stdlib.h>
#include "friend.h" // 定义朋友
#include "system.h" // 系统操作
#include "output.h" // 信息输出
#include "audit.h"
#include "fileio.h"

// 这里应该只保留if结构，其余操作下放到system完成

int play() {

    Friend friends[100];
    int friend_count = 0;

    if (!load_friends_from_csv("friends.csv", friends, &friend_count)) {
        output_warning("无法加载朋友数据，可能是文件不存在或格式错误");
    }

    system_init();
    if (!audit_init("audit.log")) {
        output_error("审计系统初始化失败");
        return 1;
    }

    int choice;
    while (1) {
        print_menu();
        scanf("%d", &choice);

        if (choice == 1) {
            Friend f;
            printf("输入学生ID: ");
            scanf("%d", &f.id);
            printf("输入姓名: ");
            scanf("%s", f.name);
            printf("输入QQID: ");
            scanf("%d", &f.qqid);
            printf("输入性别: ");
            scanf("%s", f.gender);
            printf("输入描述: ");
            scanf("%s", f.desc);
            system_add_friend(f);
            friends[friend_count++] = f;
        } else if (choice == 2) {
            int id;
            printf("输入要删除的朋友ID: ");
            scanf("%d", &id);
            system_remove_friend(id);
        } else if (choice == 3) {
            int id;
            printf("输入要查询的朋友ID: ");
            scanf("%d", &id);
            Friend* f = system_find_friend(id);
            if (f) {
                printf("找到朋友: %s\n", f->name);
            } else {
                output_warning("对象不存在");
            }
        } else if (choice == 4) {
            system_list_friends();
        } else if (choice == 5) {
            output_info("退出系统");
            break;
        } else {
            output_warning("无效选择");
        }
    }

    if (!save_friends_to_csv("friends.csv", friends, friend_count)) {
        output_error("无法保存朋友数据");
    }

    system_cleanup();
    audit_close();
    return 0;
}

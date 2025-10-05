#include <stdio.h>
#include <stdlib.h>
#include "friend.h"
#include "system.h"
#include "output.h"
#include "audit.h"
#include "fileio.h"
#include "menu.h"

int play() {
    if (system_init() != 0) {
        output_error("系统初始化失败，退出。");
        return 1;
    }

    int choice;
    while (1) {
        menu();
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

    system_end();
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#include "friend.h"
#include "system.h"
#include "output.h"
#include "audit.h"
#include "fileio.h"
#include "menu.h"


enum SATA {
    SUCCESS = 0,
    FAILED = 1,
};


enum Options {
    ADD = 1,
    DELETE,
    FIND,
    LIST,
    QUIT,
};


int play() {
    if (system_init() != 0) {
        output_error("系统初始化失败");
        return FAILED;
    }

    int choice;
    while (1) {
        menu();
        scanf("%d", &choice);

        switch (choice) {
            case ADD: {
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
                break;
            }

            case DELETE: {
                int id;
                printf("输入要删除的朋友ID: ");
                scanf("%d", &id);
                system_remove_friend(id);
                break;
            }

            case FIND: {
                int id;
                printf("输入要查询的朋友ID: ");
                scanf("%d", &id);
                system_find_and_printf(id);
                break;
            }

            case LIST:
                system_list_friends();
                break;

            case QUIT:
                output_info("退出系统");
                system_end();
                return SUCCESS;

            default:
                output_warning("无效选择，请重新输入！");
                break;
        }
    }

    system_end();
    return SUCCESS;
}

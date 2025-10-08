#include <stdio.h>
#include <stdlib.h>

#include "friend.h"
#include "system.h"
#include "output.h"
#include "audit.h"
#include "fileio.h"
#include "menu.h"
#include "play.h"


enum PLAY_STAT play() {
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
                system_get_and_add_friend();
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

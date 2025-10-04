#include "friend.h"
#include <stdio.h>

void print_friend(const Friend *f) {
    if (f == NULL) {
        printf("朋友信息为空\n");
        return;
    }
    printf("ID: %d | 名字: %d | QQ: %d | 性别: %s | 描述: %s\n",
    f->id, f->name, f->qqid, f->gender, f->desc);
}

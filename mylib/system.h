#ifndef SYSTEM_H
#define SYSTEM_H

#include "friend.h"

// 初始化系统
void system_init();

// 添加朋友
int system_add_friend(Friend f);

// 删除朋友
int system_remove_friend(int id);

// 寻找朋友，返回指针
Friend* system_find_friend(int id);

// 列出所有朋友
void system_list_friends();

// 清理
void system_cleanup();

#endif

#ifndef SYSTEM_H
#define SYSTEM_H

#include "friend.h"

void system_init();

int system_add_friend(Friend f);

int system_remove_friend(int id);

Friend* system_find_friend(int id);

void system_list_friends();

void system_cleanup();

#endif

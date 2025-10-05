#ifndef SYSTEM_H
#define SYSTEM_H

#include "friend.h"


int system_init();


int system_add_friend(Friend f);


int system_remove_friend(int id);


Friend* system_find_friend(int id);


void system_find_and_printf(int id);


int system_list_friends();


int system_end();


#endif

#ifndef SYSTEM_H
#define SYSTEM_H

#include "friend.h"
#include "status.h"


enum STATUS system_init();


enum STATUS system_get_and_add_friend();


enum STATUS system_remove_friend(int id);


void system_find_and_printf(int id);


enum STATUS system_list_friends();


enum STATUS system_end();


#endif

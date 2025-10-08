#ifndef SYSTEM_H
#define SYSTEM_H

#include "friend.h"


enum SYSTEM_STAT {
    SUCCESS = 0,
    FAILED = 1,
};


enum SYSTEM_STAT system_init();


enum SYSTEM_STAT system_get_and_add_friend();


enum SYSTEM_STAT system_remove_friend(int id);


void system_find_and_printf(int id);


enum SYSTEM_STAT system_list_friends();


enum SYSTEM_STAT system_end();


#endif

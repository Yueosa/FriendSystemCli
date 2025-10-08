#ifndef SYSTEM_H
#define SYSTEM_H

#include "friend.h"


enum STAT {
    SUCCESS = 0,
    FAILED = 1,
};


enum STAT system_init();


Friend system_get_friend();


enum STAT system_add_friend(Friend f);


enum STAT system_get_and_add_friend();


enum STAT system_remove_friend(int id);


Friend* system_find_friend(int id);


void system_find_and_printf(int id);


enum STAT system_list_friends();


enum STAT system_end();


#endif

#ifndef FILEIO_H
#define FILEIO_H

#include "friend.h"


int load_friends_from_csv(const char *filename, Friend *friends, int *friend_count);


int save_friends_to_csv(const char *filename, const Friend *friends, int friend_count);


#endif

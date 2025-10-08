#ifndef FILEIO_H
#define FILEIO_H

#include "friend.h"
#include "status.h"


enum STATUS load_friends_from_csv(const char *filename, Friend *friends, int *friend_count);


enum STATUS save_friends_to_csv(const char *filename, const Friend *friends, int friend_count);


#endif

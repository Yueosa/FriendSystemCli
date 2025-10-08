#ifndef FILEIO_H
#define FILEIO_H

#include "friend.h"


enum FILEIO_STAT {
    SUCCESS = 0,
    FAILED = 1,
};


enum FILEIO_STAT load_friends_from_csv(const char *filename, Friend *friends, int *friend_count);


enum FILEIO_STAT save_friends_to_csv(const char *filename, const Friend *friends, int friend_count);


#endif

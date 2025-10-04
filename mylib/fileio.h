#ifndef FILEIO_H
#define FILEIO_H

#include "friend.h"

// 加载朋友数据
int load_friends_from_csv(const char *filename, Friend *friends, int *friend_count);

// 保存朋友数据
int save_friends_to_csv(const char *filename, const Friend *friends, int friend_count);

#endif

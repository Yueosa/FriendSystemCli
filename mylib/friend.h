#ifndef FRIEND_H
#define FRIEND_H


typedef struct {
    int id;
    char name[50];
    int qqid;
    char gender[10];
    char desc[200];
} Friend;


void print_friend(const Friend *f);


#endif

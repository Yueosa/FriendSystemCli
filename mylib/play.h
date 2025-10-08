#ifndef PLAY_H
#define PLAY_H


enum PLAY_STAT {
    SUCCESS = 0,
    FAILED = 1,
};


enum Options {
    ADD = 1,
    DELETE,
    FIND,
    LIST,
    QUIT,
};


enum PLAY_STAT play();


#endif

#ifndef AUDIT_H
#define AUDIT_H


enum AUDIT_STAT {
    SUCCESS = 0,
    FAILED = 1,
};


enum AUDIT_STAT audit_init(const char *filename);


void audit_log(const char *action, const char *detail);


void audit_close();


# endif

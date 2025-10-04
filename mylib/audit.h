#ifndef AUDIT_H
#define AUDIT_H

int audit_init(const char *filename);

void audit_log(const char *action, const char *detail);

void audit_close();

# endif

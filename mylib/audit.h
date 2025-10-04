#ifndef AUDIT_H
#define AUDIT_H

// 成功返回1，失败返回0
int audit_init(const char *filename);

// 写入日志
void audit_log(const char *action, const char *detail);

// 关闭日志
void audit_close();

# endif

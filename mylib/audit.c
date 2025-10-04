#include "audit.h"
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

#ifdef _WIN32
    #include <direct.h>
#endif

static FILE *audit_file = NULL;

int audit_init(const char *filename) {
    char filepath[256];

// 跨平台目录创建
#ifdef _WIN32
    _mkdir("log"); // Win
#else
    mkdir("log", 0755); // Linux
#endif

    snprintf(filepath, sizeof(filepath), "log/%s", filename);

    audit_file = fopen(filepath, "a");
    return (audit_file != NULL);
}

void audit_log(const char *action, const char *detail) {
    if (!audit_file) return;

    time_t now = time(NULL);
    char *time_str = ctime(&now);
    time_str[strcspn(time_str, "\n")] = '\0';

    fprintf(audit_file, "[%s] ACTION: %s | DETAIL: %s\n", time_str, action, detail);
    fflush(audit_file);
}

void audit_close() {
    if (audit_file) {
        fclose(audit_file);
        audit_file = NULL;
    }
}

/*
示例调用
#include <stdio.h>
#include "audit.h"

int main() {
    // 初始化日志系统，日志会写到 log/app.log
    if (!audit_init("app.log")) {
        printf("无法初始化日志系统！\n");
        return 1;
    }

    // 写入一些日志
    audit_log("START", "程序启动");
    audit_log("LOGIN", "用户 alice 登录成功");
    audit_log("DOWNLOAD", "用户下载文件 report.pdf");
    audit_log("LOGOUT", "用户 alice 退出登录");

    // 关闭日志
    audit_close();

    printf("日志已写入 log/app.log\n");
    return 0;
}
*/

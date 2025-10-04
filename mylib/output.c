#include "output.h"
#include <stdio.h>


void output_info(const char *message) {
    printf("[INFO] %s\n", message);
}

void output_error(const char *message) {
    printf("[ERROR] %s\n", message);
}

void output_warning(const char *message) {
    printf("[WARNING] %s\n", message);
}

/*
示例调用
#include "output.h"

int main() {
    output_info("程序启动成功");
    output_warning("配置文件缺失，使用默认配置");
    output_error("无法连接数据库");

    return 0;
}
*/

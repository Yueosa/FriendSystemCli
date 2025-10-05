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

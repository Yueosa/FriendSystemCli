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


#ifdef _WIN32
    _mkdir("log");
#else
    mkdir("log", 0755);
#endif

    snprintf(filepath, sizeof(filepath), "log/%s", filename);

    audit_file = fopen(filepath, "a");
    return (audit_file == NULL);
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

#include "libmx.h"

char *mx_strdup(const char *str) {
    if (str == NULL) return NULL;
    int len = mx_strlen(str);
    char *dup = mx_strnew(len);
    if (dup == NULL) return NULL;
    mx_strcpy(dup, str);
    return dup;
}


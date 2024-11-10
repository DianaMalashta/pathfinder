#include "libmx.h"

char *mx_strndup(const char *s1, size_t n) {
    if (!s1) return NULL;
    size_t len = mx_strlen(s1);
    if(n > len) n = len;
    char *dup = mx_strnew(n + 1);
    if(dup == NULL) return NULL;
    
    for(size_t i = 0; i < n; i++) dup[i] = s1[i];
    dup[n] = '\0';
    
    return dup;
}


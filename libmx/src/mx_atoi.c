#include "libmx.h"

int mx_atoi(const char *str){
    if (!str) return 0;
    int result = 0;
    int sign = 1;

    while (mx_isspace(*str)) str++;

    if (*str == '-' || *str == '+') {
        if (*str == '-') sign = -1;
        str++;
    }

    while (*str && mx_isdigit(*str)) {
        result = result * 10 + (*str - '0');
        str++;
    }

    return result * sign;
}

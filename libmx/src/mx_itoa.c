#include "libmx.h"

int mx_countd(int number){
    int count = 0;
    if (number == 0) return 1;
    if (number < 0) number = -number;
    while (number != 0){
        count++;
        number /= 10;
    }
    return count;
}

char *mx_itoa(int number){
    int negative = number < 0;
    int len = mx_countd(number) + negative;
    char *result = mx_strnew(len + 1);

    if (number == 0){
        result[0] = '0';
        return result;
    }

    if (negative){
        number = -number;
        result[0] = '-';
    }

    for (int i = len - 1; i >= 0; i--){
        result[i] = (number % 10) + '0';
        number /= 10;
        if (number == 0) break;
    }
    return result;
}

#include "libmx.h"

void mx_printint(int n){
    if (n == 0) {
        mx_printchar('0');
        return;
    }
    if (n < 0) {
       	mx_printchar('-');
        n = -n;
    }
	int digit = 1;
    int temp = n;
    while (temp / 10 != 0) {
        digit *= 10;
        temp /= 10;
    }
    while (digit != 0) {
        mx_printchar(n / digit + '0');
       	n %= digit;
        digit /= 10;
    }
}

#include "libmx.h"

unsigned long mx_hex_to_nbr(const char *hex) {
    if(hex == NULL) return 0;
    unsigned long result = 0;
    int len = 0;
    int power = 0;
    while (hex[len] != '\0') {
        len++;
    }
    for (int i = len - 1; i >= 0; i--) {
        char c = hex[i];
        int digit_value = 0;
        if (mx_isdigit(c)) {
            digit_value = c - '0';
        } else if (mx_isalpha(c)) {
            if (mx_islower(c)) {
                digit_value = c - 'a' + 10;
            } else if (mx_isupper(c)) {
                digit_value = c - 'A' + 10;
            }
        } else return 0;
        unsigned long res = 1;
        for(int i = 0; i < power; i++){
            res *= 16;
        }
        result += digit_value * res;
        power++;
    }
    return result;
}

#include "libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
    if(nbr == 0){
        char* ans = mx_strnew(1);
        ans[0] = 0;
        return ans;
    }
    int digits = 1;
    unsigned long temp = nbr;
    while (temp / 16 > 0) {
        digits++;
        temp /= 16;
    }
    char* ans = mx_strnew(digits + 1);
    if (ans == NULL){
        return NULL;
	}
    int i = 0;
    while (nbr != 0) {
        int rem = nbr % 16;
        char ch;
        if (rem < 10) {
            ch = rem + '0';
        } else {
            ch = rem + 'a' - 10;
        }
        ans[i++] = ch;
        nbr = nbr / 16;
    }
    ans[i] = '\0';
    int j = mx_strlen(ans) - 1;
    int k = 0;
    while (k < j) {
        char temp = ans[k];
        ans[k] = ans[j];
        ans[j] = temp;
        k++;
        j--;
    }
    return ans;
}


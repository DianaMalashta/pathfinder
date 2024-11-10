#include "libmx.h"

int mx_binary_search(char **arr, int size, const char *s, int *count){
    if(!arr || !s || !count || size <= 0) return -1;
    
    int left = 0, right = size - 1;
    *count = 0;
    
    while(left <= right){
        int middle = left + (right - left) / 2;
        (*count)++;
        int cmp  = mx_strcmp(arr[middle], s);
        if(cmp == 0) return middle;
        if(cmp < 0) left = middle + 1;
        else right = middle - 1;
    }
    *count = 0;
    return -1;
}


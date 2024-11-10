#include "libmx.h"

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n){
        if(!dst || !src) return NULL;	
        unsigned char *temp_d = dst;
	const unsigned char *temp_s = src;
	for(size_t i = 0; i < n; i++){
		*temp_d = *temp_s;
		temp_d++;
		temp_s++;
	}
	return dst;
}


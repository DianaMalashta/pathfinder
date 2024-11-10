#include "libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n){
	unsigned char *temp_d = dst;
	const unsigned char *temp_s = src;
	for(size_t i = 0; i < n; i++){
		*temp_d = *temp_s;
		if(*temp_s == (unsigned char)c) return temp_d++;
		temp_d++;
		temp_s++;
	}
	return NULL;
}


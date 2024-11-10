#include "libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len){
	unsigned char *temp_d = dst;
	const unsigned char *temp_s = src;

	if(temp_d < temp_s || temp_d >= (temp_s + len)){
		for(size_t i = 0; i < len; i++) temp_d[i] = temp_s[i];
	}
	else{
		for(size_t i = len; i > 0; i--) temp_d[i - 1] = temp_s[i - 1];
	}
	return dst;
}


#include "libmx.h"

void *mx_memchr(const void *s, int c, size_t n){
	const unsigned char *temps = s;
	for(size_t i = 0; i < n; i++){
		if(*temps == (unsigned char)c) return (void *)temps;
		temps++;
	}
	return NULL;
}


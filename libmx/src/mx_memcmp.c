#include "libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n){
	const unsigned char *temp1 = s1;
	const unsigned char *temp2 = s2;
	for(size_t i = 0; i < n; i++){
		if(*temp1 != *temp2) return *temp1 - *temp2;
		temp1++;
		temp2++;
	}
	return 0;
}


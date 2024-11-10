#include "libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len){
	if(!big || !little || big_len == 0 || big_len < little_len) return NULL;
	const unsigned char *b = big;
	const unsigned char *l = little;
	for(size_t i = 0; i <= big_len - little_len; i++){
	        if(b[i] == l[0]){
	                size_t j = 1;
	                while(j < little_len && b[i + j] == l[j]) j++;
	                if(j == little_len) return (void *)(b + i);
	        }
	}
	return NULL;
}


#include "libmx.h"

int mx_count_words(const char *str, char c){
	if(!str) return -1;
	int count = 0;
	for(int i = 0; str[i] != '\0'; i++){
		if(str[i] != c && (i == 0 || str[i - 1] == c)) count++;
	}
	return count;
}


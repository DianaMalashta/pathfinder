#include "libmx.h"

int mx_get_substr_index(const char *str, const char *sub){
	if(!str || !sub) return -2;
	for(int i = 0; str[i] != '\0'; i++){
		int j = 0;
		while(str[i + j] == sub[j] && sub[j] != '\0') j++;
		if(sub[j] == '\0') return i;
	}
	return -1;
}


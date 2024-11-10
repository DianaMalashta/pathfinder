#include <stddef.h>

int mx_count_substr(const char *str, const char *sub){
        if(!str || !sub) return -1;
	if(*sub == '\0') return 0;
        
    	int count = 0;
    	while((str = mx_strstr(str, sub)) != NULL){
        	count++;
        	str++;
    	}
    	return count;
}



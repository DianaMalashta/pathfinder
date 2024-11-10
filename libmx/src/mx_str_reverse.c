#include "libmx.h"

void mx_str_reverse(char *s){
	if(!s) return;
	char *start = s;
	char *end = s;
	char temp;
	
	while(*end) end++;
	end--;
	
	while(start < end){
		temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}
}


#include "libmx.h"

char *mx_strtrim(const char *str){
	if(!str) return NULL;
	
	int start = 0;
	int end = mx_strlen(str) - 1;
	while(mx_isspace(str[start])) start++;
	while(end >= start && mx_isspace(str[end])) end--;
	
	if(start > end){
		char *empty = mx_strnew(0);
		empty[0] = '\0';
		return empty;
	}
	int trimmed_len = end - start + 1;
	
	char *trim = mx_strnew(trimmed_len);
	if(!trim) return NULL;
	mx_strncpy(trim, &str[start], trimmed_len);
	trim[trimmed_len] = '\0';
	
	return trim;
}


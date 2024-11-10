#include "libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace){
	if(!sub || !str || !replace) return NULL;

	int str_len = mx_strlen(str);
	int sub_len = mx_strlen(sub);
	int replace_len = mx_strlen(replace);
	int count_sub = mx_count_substr(str,  sub);
	if(count_sub == 0 || sub_len == 0) return mx_strdup(str);
	
	int new_str_len = str_len - (sub_len * count_sub) + (replace_len * count_sub);
	char *new_str = mx_strnew(new_str_len);
	if(!new_str) return NULL;

	const char *current = str;
	char *new_str_pos = new_str;
	while ((current = strstr(current, sub)) != NULL){
		int len_before_sub = current - str;
		mx_strncpy(new_str_pos, str, len_before_sub);
		new_str_pos += len_before_sub;
		mx_strcpy(new_str_pos, replace);
		new_str_pos += replace_len;
		str = current + sub_len;
		current = str;
	}

	mx_strcpy(new_str_pos, str);
	return new_str;
}


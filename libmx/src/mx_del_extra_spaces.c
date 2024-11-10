#include "libmx.h"

char *mx_del_extra_spaces(const char *str){
	if(!str) return NULL;

	char *trimmed = mx_strtrim(str);
	if(!trimmed) return NULL;
	int len = mx_strlen(trimmed);
	char *new_str = mx_strnew(len);
	if(!new_str){
		free(trimmed);
		return NULL;
	}

	int i = 0, j = 0;
	bool inside = false;

	while(i < len){
		if(!mx_isspace(trimmed[i])){
			new_str[j++] = trimmed[i];
			inside = true;
		}
		else if(inside){
			new_str[j++] = ' ';
			inside = false;
		}
		i++;
	}
	if(j > 0 && new_str[j - 1] == ' ') new_str[j - 1] = '\0';
	else new_str[j] = '\0';

	free(trimmed);
	return(new_str);
}


#include "libmx.h"

char **mx_strsplit(const char *s, char c){
	if(!s) return NULL;

	int words_count = mx_count_words(s, c);
	char **result = (char **)malloc(sizeof(char *) * (words_count + 1));
	if(!result) return NULL;

	int i = 0;
	while(*s){
		while(*s == c){
			s++;
		}
		if(*s) {
			const char *start = s;
			int len = 0;
			while(*s && *s != c){
				len++;
				s++;
			}
			result[i] = mx_strnew(len);
			if(!result[i]){
				for(int j = 0; j < i; j++) free(result[j]);
				free(result);
				return NULL;
			}
			mx_strncpy(result[i], start, len);
			i++;
		}
	}
	result[i] = NULL;
	return result;
}


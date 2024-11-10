#include "libmx.h"

char *mx_strcat(char *restrict s1, const char *restrict s2){
	char *s1_end = s1;
	while(*s1_end!='\0') s1_end++;
	while(*s2 != '\0'){
		*s1_end = *s2;
		s1_end++;
		s2++;	
	}
	*s1_end = '\0';
	return s1;
}


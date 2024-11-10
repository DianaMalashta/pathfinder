#include "libmx.h"

char *mx_strjoin(char const *s1, char const *s2) {
	if (!s1 && !s2) return NULL;
	if (!s1) return mx_strdup(s2);
	if (!s2) return mx_strdup(s1);
	int len1 = mx_strlen(s1);
	int len2 = mx_strlen(s2);
	char *join = mx_strnew(len1 + len2);
	if (*join) return NULL;
	for (int i = 0; i < len1; i++) {
		join[i] = s1[i];
	}
	for (int i = 0; i < len2; i++) {
		join[len1 + i] = s2[i];
	}
	join[len1 + len2] = '\0';
	return join;
}


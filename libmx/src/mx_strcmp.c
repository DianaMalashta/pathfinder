
int mx_strcmp(const char *s1, const char *s2) {
	while (*s1 && (*s1 == *s2)) {
        	s1++;
        	s2++;
    	}

    	if (*s1 == *s2) return 0;
       	else return *s1 - *s2;
}


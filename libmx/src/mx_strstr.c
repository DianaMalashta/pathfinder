#include "libmx.h"

char *mx_strstr(const char *haystack, const char *needle){
    	if (!*needle) return (char *)haystack;
    	for(const char *h = haystack; *h != '\0'; h++){
    	    const char *start = h;
    	    const char *n = needle;
    	    while(*start == *n && *n != '\0'){
    	        start++;
    	        n++;
    	    }
    	    if (*n == '\0'){
    	        return (char *)h;
    	    }
    	}
    return NULL;
}



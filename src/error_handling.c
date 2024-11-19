#include "pathfinder.h"

bool is_valid_island(const char *name){
    while(*name){
        if(!mx_isalpha(*name)) return false;
        name++;
    }
    return true;
}

bool is_valid_lenght(const char *lenght){
    if(!lenght || *lenght == '\0') return false;
	if(lenght[0] == '0') return false;
    int return_pointer = 0;
    while(*lenght){
        if(!mx_isdigit(*lenght)) return false;
        lenght++;
        return_pointer++;
    }
    while(return_pointer>0){
        lenght--;
        return_pointer--;
    }

    return mx_atoi(lenght) > 0;
}

void print_file_error(const char *filename, const char *str, const char *str2){
    write(2, str, mx_strlen(str));
    write(2, filename, mx_strlen(filename));
    write(2, str2, mx_strlen(str2));
    exit(-1);
}

void print_line_error(int i){
    char *line_num_str = mx_itoa(i);
    write(2, "error: line ", mx_strlen("error: line "));
    write(2, line_num_str, mx_strlen(line_num_str));
    write(2, " is not valid\n", mx_strlen(" is not valid\n"));
    free(line_num_str);
    exit(-1);
}

char **check_split_with_index(const char *s, char c, int *index){
	if(!s) return NULL;

	int words_count = mx_count_words(s, c);
	char **result = (char **)malloc(sizeof(char *) * (words_count + 1));
	if(!result) return NULL;

	int i = 0;
	bool delim_already = false;
	while(*s){
		while(*s == c){
			if(delim_already){
                *index = i;
                for(int j = 0; j < i; j++) free(result[j]);
                free(result);
				return NULL;
			}
			delim_already = true;
			s++;
		}
		if(*s) {
			delim_already = false;
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


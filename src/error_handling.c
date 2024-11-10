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

void print_line_error(int i) {
    char *line_num_str = mx_itoa(i);
    write(2, "error: line ", mx_strlen("error: line "));
    write(2, line_num_str, mx_strlen(line_num_str));
    write(2, " is not valid\n", mx_strlen(" is not valid\n"));
    free(line_num_str);
    exit(-1);
}


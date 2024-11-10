#include "libmx.h"

char *mx_file_to_str(const char *file){
	if(!file) return NULL;
	int fd = open(file, O_RDONLY);
	if(fd < 0) return NULL;

	int size = 0;
	char buffer[1];
	while(read(fd, buffer, 1) > 0) size++;
	close(fd);

	fd = open(file, O_RDONLY);
	if(fd < 0) return NULL;
	char *str = mx_strnew(size);
	if(!str){
		close(fd);
		return NULL;
	}

	int bytes = read(fd, str, size);
	if(bytes != size){
		free(str);
		close(fd);
		return NULL;
	}

	str[size] = '\0';
	close(fd);
	return str;
}


#include "libmx.h"

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
	if (!lineptr || buf_size <= 0 || fd < 0) return -2;
	static char buffer[1];
	char *result = NULL;
	size_t result_len = 0;
	ssize_t bytes_read;

	*lineptr = NULL;

	while ((bytes_read = read(fd, buffer, 1)) > 0) {
		if (buffer[0] == delim) break;
		if (result_len % buf_size == 0) {
			char *new_result = mx_realloc(result, result_len + buf_size + 1);
			if (!new_result) {
				free(result);
				return -2;
			}
			result = new_result;
		}
		result[result_len++] = buffer[0];
	}
	if (bytes_read == -1 || (bytes_read == 0 && result_len == 0)){
	        free(result);
	        return -2;
	}
	result[result_len] = '\0';
	*lineptr = result;
	return result_len;
}


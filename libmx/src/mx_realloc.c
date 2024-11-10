#include "libmx.h"

void *mx_realloc(void *ptr, size_t size){
	if(size == 0 && !ptr){
		free(ptr);
		return NULL;
	}
	if(!ptr) return malloc(size);

	void *new_ptr = malloc(size);
	if(!new_ptr) return NULL;
	//size_t old_size = malloc_usable_size(ptr);
	//size_t new_size;
	//if(old_size < size) new_size = old_size;
	//else new_size = size;
	//mx_memccpy(new_ptr, ptr, new_size);
	mx_memcpy(new_ptr, ptr, size);
	free(ptr);
	return new_ptr;
}


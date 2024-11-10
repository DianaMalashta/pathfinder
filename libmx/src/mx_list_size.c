#include "libmx.h"

int mx_list_size(t_list *list){
	if(!list) return 0;
	t_list *temp = list;
	int node = 0;
	while(temp){
		temp = temp->next;
		node++;
	}
	return node;
}


#include "libmx.h"

void mx_push_front(t_list **list, void *data){
	t_list *temp = mx_create_node(data);
	if(!temp) return;
	temp->next = *list;
	*list = temp;
}


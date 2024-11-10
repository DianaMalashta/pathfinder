#include "libmx.h"

t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *)){
	if(!lst || !cmp) return lst;
	int swap;
	t_list *temp;
	while(1){
		swap = 0;
		temp = lst;
		while(temp->next != NULL){
			if(cmp(temp->data, temp->next->data)){
				void *c = temp->data;
				temp->data = temp->next->data;
				temp->next->data = c;

				swap = 1;
			}
			temp = temp->next;
		}
		if(!swap) break;
	}
	return lst;
}


#include "libmx.h"

void swap(char **arr, int i, int j){
	char *temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

int partition(char **arr, int left, int right, int *swaps){
	int pivot_len = mx_strlen(arr[left + (right - left) / 2]);
	int l = left, r = right;
	while(l <= r){
		while(mx_strlen(arr[l]) < pivot_len) l++;
		while(mx_strlen(arr[r]) > pivot_len) r--;
		if(l <= r){
			if(l != r){
				swap(arr, l, r);
				(*swaps)++;
			}
			l++;
			r--;
		}
	}
	return l;
}

int mx_quicksort(char **arr, int left, int right){
	if(!arr) return -1;
	int swaps = 0;
	if(left < right) {
		int index = partition(arr, left, right, &swaps);
		swaps += mx_quicksort(arr, left, index-1);
		swaps += mx_quicksort(arr, index, right);
	}
	return swaps;
}


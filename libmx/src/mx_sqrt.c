int mx_sqrt(int x) {
    	if (x < 0) return 0;
    	if (x == 0 || x == 1) return x;
    	
	int start = 1, end = x, mid;
	while (start <= end) {
       		mid = (start + end) / 2;
        	if (mid * mid == x) return mid;
                if (mid * mid < x) start = mid + 1;
        	else end = mid - 1;
	}
	return 0;
}


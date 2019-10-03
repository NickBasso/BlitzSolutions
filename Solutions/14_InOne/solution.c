#include <stdio.h>
#include <limits.h>

void main(){
	int n, x, k = 0, i, a[10000] = {0}, min = INT_MAX, max = INT_MIN;
	
	scanf("%d%d", &n, &x);
	
	for(i = 0; i < n; i++){
		scanf("%d", &a[i]);
		k += a[i] == x ? 1 : 0;
		
		if(a[i] > max)
			max = a[i];
		if(a[i] < min)
			min = a[i];
	}
		
	printf("Amount of %d in the array a is: %d\n", x, k);
	printf("Min element: %d\nMax element: %d", min, max);
	
}

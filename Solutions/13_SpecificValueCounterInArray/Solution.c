#include <stdio.h>

void main(){
	int n, x, k = 0, i, a[10000] = {0};
	
	scanf("%d%d", &n, &x);
	
	for(i = 0; i < n; i++){
		scanf("%d", &a[i]);
		k += a[i] == x ? 1 : 0;
	}
		
	printf("%d", k);	
}

#include <stdio.h>
#include <limits.h>

void main(){
	FILE *f;
	f = fopen("input.txt", "r");
	
	int n, i, t, a[1000] = {0}, k;
	
	fscanf(f, "%d%d", &n, &k);
	
	for(i = 0; i < n; i++)
		fscanf(f, "%d", &a[i]);
		
	for(i = n; i < n * 2; i++)
		a[i] = a[i - n];
		
	for(i = 0; i < n; i++){
		a[i] = a[(i + k) % n + n];
		printf("%d ", a[i]);
	}
}

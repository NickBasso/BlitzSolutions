#include <stdio.h>
#include <stdlib.h>

// void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*))

int cmp (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

void main(){
	freopen("input.txt", "r", stdin);
	
	int n, m, i, j;
	int a[100][100] = {0};
	
	scanf("%d%d", &n, &m);
	
	for(i = 0; i < n; i++)
		for(j = 0; j < m; j++)
			scanf("%d", &a[i][j]);
			
	for(i = 0; i < n; i++, printf("\n"))
		for(j = 0; j < m; j++)
			printf("%d ", a[i][j]);
	printf("\n\n");	
		
	for(i = 0; i < n; i++)
		qsort(a[i], m, sizeof(int), cmp);
		
	int temp, k;
	
	for(i = 0; i < n; i++, printf("\n"))
		for(j = 0; j < m; j++)
			printf("%d ", a[i][j]);
	printf("\n\n");	
	
	for(i = 0; i < m; i++){
		for(k = 0; k < n; k++){
			for(j = 0; j < n - 1; j++){
				if(a[j][i] > a[j + 1][i]){
					temp = a[j][i];
					a[j][i] = a[j + 1][i];
					a[j + 1][i] = temp;
				}
			}
		}	
	}
	
	
	for(i = 0; i < n; i++, printf("\n"))
		for(j = 0; j < n; j++)
			printf("%d ", a[i][j]);
}

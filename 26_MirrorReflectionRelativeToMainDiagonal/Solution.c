#include <stdio.h>

void main(){
	freopen("input.txt", "r", stdin);
	
	int n, m, i, j, a[100][100], tmp;
	int used[100][100] = {0};
	
	scanf("%d", &n);
	
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)	
			scanf("%d", &a[i][j]);
			
	for(i = 0; i < n / 2 + 1; i++)
		for(j = 0; j < n; j++){
			if(i != j && !used[i][j]){
				tmp = a[i][j];
				a[i][j] = a[j][i];
				a[j][i] = tmp;
				used[j][i] = 1;
			}
		}
		
	for(i = 0; i < n; i++, printf("\n"))
		for(j = 0; j < n; j++)	
			printf("%d ", a[i][j]);
}

#include <stdio.h>

void main(){
	freopen("input.txt", "r", stdin);
	
	int n, m, i, j, a[100][100], tmp;
	int used[100][100] = {0};
	
	scanf("%d", &n);
	
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)	
			scanf("%d", &a[i][j]);
			
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++){
			if(i + j != n && !used[i][j]){
				tmp = a[i][j];
				a[i][j] = a[n - 1 - j][n - 1 - i];
				a[n - 1 - j][n - 1 - i] = tmp;
				used[n - 1 - j][n - 1 - i] = 1;
			}
		}
		
	for(i = 0; i < n; i++, printf("\n"))
		for(j = 0; j < n; j++)	
			printf("%d ", a[i][j]);
}

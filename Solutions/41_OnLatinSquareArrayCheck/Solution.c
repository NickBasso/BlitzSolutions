#include <stdio.h>

#define N 100

int main(){
	freopen("input.txt", "r", stdin);
	
	int n, i, j, a[N][N] = {0};
	
	scanf("%d", &n);
	
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++){
			scanf("%d", &a[i][j]);
			a[i][n] += a[i][j];
			a[n][j] += a[i][j];
		}
		
	for(i = 0; i <= n; i++, printf("\n"))
		for(j = 0; j <= n; j++){
			printf("%d  ", a[i][j]);
		}
		
	for(i = 1; i < n; i++){
		if(a[i][n] == a[i - 1][n])
			continue;
		else
			break;	
	}
	
	for(j = 1; j < n; j++){
		if(a[n][j] == a[n][j - 1])
			continue;
		else
			break;	
	}
	
	if(i == j && j == n)
		printf("YES");
	else
		printf("NO");
	
	return 0;
}

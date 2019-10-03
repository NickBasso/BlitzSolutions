#include <stdio.h>

void main(){
	freopen("input.txt", "r", stdin);
	
	int n, m, i, j, k, a[100][100], tmp, sl, sr, su, sd;
	int used[100][100] = {0};
	
	// input
	scanf("%d", &n);
	
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)	
			scanf("%d", &a[i][j]);
	
	sl = sr = su = sd = 0;
	
	// sum left triangle
	k = n / 2;
	for(i = 0, j = 1; i <= n / 2 + 1; i++, k--, j = i + 1)
		for(; j <= k + 1; j++)
			sl += a[j][i];		
	printf("Sum left =  %d\n", sl);
	
	// sum right triangle
	k = n / 2;				
	for(i = n - 1, j = 1; i > n / 2; i--, k--, j = n % 2 ? i - 1 : i - 2)
		for(; j <= k + 1; j++)
			sr += a[j][i];
	
	
	printf("Sum right = %d\n", sr);
	
	// sum upper triangle
	k = (n + 1) / 2;				
	for(i = 0, j = 1; i < (n + 1) / 2; i++, j = i + 1)
		for(; j < n - i - 1; j++)
			su += a[i][j];
	printf("Sum upper = %d\n", su);
	
	// sum down triangle
	k = (n + 1) / 2;				
	for(i = n - 1, j = 1; i > n / 2; i--, j -= n % 2 ? 2 : 3)
		for(; j < i; j++)
			sd += a[i][j];
	printf("Sum down = %d\n", sd);
	
	//sd = 30;
	
	if(sl >= sr && sl >= su && sl >= sd){
		for(i = 1; i <= (n - 1) / 2; i++, printf("\n"))
			for(j = 0; j < (n - 1) / 2 - 1 + i - 1; j++)
				printf("%d ", a[i][j]);
		for(i = (n - 1) / 2 + 1; i <= (n - 1); i++, printf("\n"))
			for(j = 0; j < n - i - 1; j++)
				printf("%d ", a[i][j]);
	}
	else if(sr >= sl && sr >= su && sr >= sd){
		for(i = 1, j = n - i; i <= (n - 1) / 2; i++, j = n - i, printf("\n"))
			for(; j <= n - 1; j++)
				printf("%d ", a[i][j]);
		for(i = (n - 1) / 2 + 1; i < (n - 1) ; i++, printf("\n"))
			for(j = n - (n - 4) + i - ((n - 1) / 2 + 1); j <= n - 1; j++)
				printf("%d ", a[i][j]);
	}
	else if(su >= sl && su >= sr && su >= sd){
		for(i = 0, j = 1; i <= (n - 1) / 2; i++, j = i + 1,printf("\n"))
			for(; j <= n / 2 + 1 - i; j++){
				int k = 0;
				while(k < n / 2 + 1 - (n / 2 + 1 - i))
					printf("  "), k++;
				printf("%d ", a[i][j]);
			}
	}
	else{
		for(i = n / 2 + 1, j = n / 2; i <= n - 1; i++, j = i - 3, printf("\n"))
			for(; j <= n / 2 + i - (n / 2 + 1); j++){
				int k = i - (n / 2 + 1) + i;
				while(k <= n / 2 + 1)
					printf("  "), k++;
				printf("%d ", a[i][j]);
			}
	}
}

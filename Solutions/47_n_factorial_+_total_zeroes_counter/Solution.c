#include <stdio.h>

#define N 10000

int main(){
	freopen("input.txt", "r", stdin);
	
	char a[N] = {0}, b[N] = {0};
	int res[N] = {0}, ia[N] = {0}, ib[N] = {0};			// ia - integer array of a	|  ib - integer array of b
	int n, i, j, k;
	int len1, len2, maxLen, temp;
	
	scanf("%d", &n);
	
	a[0] = '1'; b[0] = '2';
	ia[0] = 1; ib[0] = 2;
	
	for(k = 2; k <= n; k++){
			// Number length calculation and output
		for(i = 0; a[i] != 0; i++)
			0;
		len1 = i;
	
		for(i = 0; b[i] != 0; i++)
			0;
		len2 = i;
		
		// maximum length out of two numbers
		maxLen = len1 < len2 ? len2 : len1;
		
		// main algo implementation
		i = 0, j = 0; 
		int rem = 0, curCol = 0;
		
		for(i = 0; i < maxLen; i++)
			for(j = 0; j < maxLen || rem; j++){
				curCol = res[i + j] + ia[i] * (j < len2 ? ib[j] : 0) + rem;
				rem = curCol / 10;
				res[i + j] = curCol % 10;
			}
			
		int tmp = k + 1;
		i = 0;
		while(tmp){
			b[i] = tmp % 10 + '0';
			ib[i] = tmp % 10;
			i++;
			tmp /= 10;
		}	
			
		i = 0;
		while(i < maxLen + 1){
			a[i] = res[i] + '0';
			ia[i] = res[i];	
			i++;
		}	
			
		if(k < n)
			for(i = 0; i < 1000; i++)
				res[i] = 0;
				
		//printf("\n\n");
	}
	
	while(res[i] == 0)
		i--;
	
	k = i;
	int ans = 0;
	
	for(i; i >= 0; i--)
		printf("%d", res[i]);
			
	for(i = k; i >= 0; i--)
		if(res[i] == 0)
			ans++;
			
	printf("  %d", ans);
				
	return 0;
}

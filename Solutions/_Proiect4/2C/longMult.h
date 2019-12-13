#define N 10000
#include <cstdio>

char* multTwo(char *a, char *b){
	int res[N] = {0}, ia[N] = {0}, ib[N] = {0};			
	int i, j;
	int len1, len2, maxLen, temp;
	bool add;
	
	char at[N] = {0}, bt[N] = {0};
	for(int i = 0; i < N; i++){
		at[i] = a[i];
		bt[i] = b[i];
	}
	
	for(i = 0; at[i] != 0; i++)
		0;
	len1 = i;

	for(i = 0; bt[i] != 0; i++)
		0;
	len2 = i;
	
	maxLen = len1 < len2 ? len2 : len1;
	
	reverse(at, len1);
	moveCharArrToInt(at, ia, len1);
	
	reverse(bt, len2);
	moveCharArrToInt(bt, ib, len2);

	i = 0, j = 0; 
	int rem = 0, curCol = 0;
	
	for(i = 0; i < maxLen; i++)
		for(j = 0; j < maxLen || rem; j++){
			curCol = res[i + j] + ia[i] * (j < len2 ? ib[j] : 0) + rem;
			rem = curCol / 10;
			res[i + j] = curCol % 10;
		}
	i--;
	while(res[i + 1] != 0)
		i++;
	
	int n = i;
	char t[N] = {0};
	for(i; i >= 0; i--)
		t[n - i] = res[i] + '0';
		
	return &t[0];
}

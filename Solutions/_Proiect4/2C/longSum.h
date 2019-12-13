#define N 10000
#include <cstdio>

char* sumTwo(char *a, char *b){
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

	i = 0; 
	int rem = 0, sumTwo;
	
	for(i = 0; i < maxLen; i++){
		sumTwo = ia[i] + ib[i] + rem;
		rem = (sumTwo / 10) % 10;
		
		if(rem)
			res[i] = sumTwo % 10 + add;
		else
			res[i] = sumTwo;
	}
	
	if(rem)
		res[i] = 1;
	else
		i--;
	
	int n = i;
	char t[N] = {0};
	for(i; i >= 0; i--)
		t[n - i] = res[i] + '0';
				
	return &t[0];
}

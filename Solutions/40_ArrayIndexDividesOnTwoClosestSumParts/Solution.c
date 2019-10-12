#include <stdio.h>

#define lli long long int
#define N 100000

lli abs(lli num){
	return (num < 0 ? -num: num);
}

// ans position index includes the value on that index

int main(){
	freopen("input.txt", "r", stdin);
	
	int i, j, ans, n;
	lli a[N] = {0}, dp[N] = {0}, bestDiff = (int)(1e17), curDiff;
	
	scanf("%d%d", &n, &a[1]);
	
	dp[1] = a[1];
	for(i = 2; i <= n; i++){
		scanf("%d", &a[i]);
		dp[i] = dp[i - 1] + a[i];
	}
	
	for(i = 2; i <= n; i++){
		curDiff = abs((dp[n] - dp[i]) - dp[i]); 
		if(curDiff < bestDiff){
			bestDiff = curDiff;
			ans = i; 	
		}
	}
	
	printf("Index dividing the input array on two parts with the closest sums\nincluding value at the index which goes to the first part:\n%d", ans);
	
	return 0;
}

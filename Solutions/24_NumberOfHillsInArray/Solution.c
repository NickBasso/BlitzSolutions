#include <stdio.h>

int main(){
	freopen("input.txt","r", stdin);
	
	int i, j; 
	int n, ans = 0, a[100] = {0};
	
	scanf("%d", &n);
	
	for(i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	
	for(i = 1; i < n - 1; i++){
		if(a[i] > a[i - 1] && a[i] > a[i + 1])
			ans++;
	}
	
	printf("%d\n", ans);
	
	return 0;
}

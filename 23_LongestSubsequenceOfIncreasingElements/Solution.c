#include <stdio.h>

int main(){
	freopen("input.txt","r", stdin);
	
	int i, j; 
	int n, ans = 1, a[100] = {0}, counter = 1, from = 1;
	
	scanf("%d", &n);
	
	for(i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	
	for(i = 0; i < n - 1; i++){
		if(a[i] < a[i - 1]){
			counter++;
		}
		else
			counter = 1;
			
		if(counter > ans){
			ans = counter;
			from = i;
		}
	}
	
	printf("%d\n", ans);
	
	i = from;
	printf("%d ", a[from]);
	while(i < n - 1 && a[i] <= a[i + 1]){
		printf("%d ", a[(i++) + 1]);		// i++ operation after a[i + 1]
	}
	
	return 0;
}

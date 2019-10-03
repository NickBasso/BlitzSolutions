#include <stdio.h>

int main(){
	freopen("input.txt","r", stdin);
	
	int i, j; 
	int n, ans = 1, a[100] = {0}, counter = 1, to = 1;
	
	scanf("%d", &n);
	
	for(i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	
	for(i = 0; i < n; i++){
		if(a[i] == a[i - 1]){
			counter++;
		}
		else
			counter = 1;
			
		if(counter > ans){
			ans = counter;
			to = i;
		}
	}
	
	printf("%d\n", ans);
	
	i = to;
	printf("%d ", a[to]);
	while(i > 0 && a[i] == a[i - 1]){
		printf("%d ", a[i--]);
	}
	
	return 0;
}

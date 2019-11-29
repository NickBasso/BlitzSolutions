#include <iostream>

using namespace std;

int main(){
	freopen("input.txt", "r", stdin);
	
	int a[1000] = {0};
	
	int i = 0, n, s, x;
	
	scanf("%d %d", &n, &s);
	
	printf("%d %d\n", n, s);
	
	for(; i < n; i++){
		scanf("%d", &x);		// a[i] = *(&a) = *(&a[0])
		a[i] = x;
	}
	printf("\n");
	
	i = n - 1;
	int sum = 0;
	int envelopes = 0;
	
	while(sum < s && i >= 0){
		sum += a[i];
		envelopes++;
		i--;
	}
	
	if(i < 0){
		printf("Not enough money!");
	}
	else{
		printf("%d %d", envelopes, sum);	
	}
	
	return 0;
}

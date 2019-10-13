#include <stdio.h>

unsigned long long intpow(unsigned long long x, unsigned long long times){
	int i = 0;
	unsigned long long tmp = 1;
	
	for(; i < times; i++){
		tmp *= x;
	}
	
	return tmp;
}

int main(){
	freopen("input.txt", "r", stdin);
	
	unsigned long long int n, i, j, ans = 0, powOf5[20];
	
	scanf("%d", &n);
	
	printf("%d\n\n", n);
	
	for(i = 0; i < 14; i++){
		powOf5[i] = pow(5, i);
		printf("%d  ->  %d\n", i, powOf5[i]);
	}
	
	for(j = 1; j < 10; j++){
		ans += n / powOf5[j];
	}
	
	printf("\n%d", ans);

	return 0;
}

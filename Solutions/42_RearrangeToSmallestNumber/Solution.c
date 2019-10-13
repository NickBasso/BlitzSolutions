#include <stdio.h>

typedef long long lli;

int main(){
	freopen("input.txt", "r", stdin);
	
	int i, j, n, tmp;
	lli num;
	int a[100] = {0};
	
	scanf("%d", &num);
	
	i = 0;
	while(num){
		a[i++] = num % 10;
		num /= 10;	
	}
	
	n = i;
	i = j = 0;
	
	for(i = 0; i < n - 1; i++)
		for(j = 0; j < n - 1; j++){
			if(a[j] > a[j + 1]){
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	
	for(i = 0; i < n; i++)
		printf("%d", a[i]);
	
	return 0;
}

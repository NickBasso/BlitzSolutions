#include <stdio.h>

int main(){
	
	long long int n, i, root;
	
	scanf("%lld", &n);
	
	root = sqrt(n);
	
	for(i = 2; i <= root; i++)
		if(n % i == 0){
			printf(" is not prime");
			break;
		}
				
	if (i > root)
		printf(" is prime");
	
	return 0;
}

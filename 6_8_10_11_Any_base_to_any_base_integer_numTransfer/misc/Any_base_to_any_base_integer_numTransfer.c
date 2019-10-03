#include <stdio.h>

int power(int num, int times);

main(){
	freopen("input.txt", "r", stdin);
	
	int num, base1, base2, x, x10;
	int i, j;
	int res[256] = {};
	char resc[256] = {};
	
	printf("%d\n\n", '0');
	printf("%d\n\n", (int)('A'));
	
	scanf("%d%d%d", &num, &base1, &base2);
	
	x = num;
	x10 = 0;
	i = j = 0;
	
	while(x > 0){
		int curDigit = x % 10;										// curDigit  -> current digit
		x10 += (curDigit) * power(base1, i);
		x /= 10;
		i++;
	}
	
	printf("Number %d from base %d is %d in base 10\n\n", num, base1, x10);
	
	i = 0;
	
	while(x10 > 0){
		res[i] = x10 % base2;
		x10 /= base2;
		i++;
	}
	
	int k=0;
	for(j = i - 1; j >= 0; j--){
		//printf("%d", res[j]);
		resc[k++] = res[j] + 48;		
	}
	
	printf("\n%s", resc);
	
	return 0;
}

int power(int num, int times){
	int res = 1, i;
	
	for(i = 0; i < times; i++)
		res *= num;
		
	return res;
}

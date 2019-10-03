#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int power(int num, int times){
	int res = 1, i;
	
	for(i = 0; i < times; i++)
		res *= num;
		
	return res;
}

void main(){
	freopen("input.txt", "r", stdin);
	
	long long int base1, base2, x, x10, temp;
	int i, j;
	char res[256] = {};
	char resc[256] = {};
	
	int len;
	char num[100];
	long long int t[100];
	long long int ind[100] = {0};
	long long int rem[100] = {0};
	
	for(i = '0'; i <= '9'; i++)
		ind[i] = i - 48;
	for(i = 'A'; i <= 'Z'; i++)
		ind[i] = i - 55;
	
	printf("%d\n", '0');
	printf("%d\n\n", (int)('A'));
	
	i = 0;
	gets(num);
		
	scanf("%d %d", &base1, &base2);
	printf("%d %d\n\n", base1, base2);
	
	printf("%s\n\n", num);
	
	int l = strlen(num);
	
	for(i = 0; i < l; i++)
		t[i] = ind[num[i]];
		
	for(i = 0; i < l; i++)
		printf("%d ", t[i]);
	printf("\n\n");
		
	len = l - 1;
		
	x10 = 0;
		
	while(len >= 0){
		x10 += t[len] * power(base1, l - len - 1);
		len--;
	}
	
	x = x10; i = 0;
	int nl = 0;
	int o=x,p;
	
	*str baza(int o,p){
		
	if (o>0){
		if(o%p>9){baza=baza(o/p,p)+(char)(o%p+55);
		}
		else {
		baza =baza(o/p)+(char)(o%p+48);}
	}
	 else baza=0;
	}
}

printf("%s ",baza);

	
}

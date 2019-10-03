#include <stdio.h>
#include <string.h>

#define N 100

typedef long long int lli;

lli power(lli num, lli times){
	lli res = 1;
	int i;
	
	for(i = 0; i < times; i++)
		res *= num;
		
	return res;
}

void main(){
	// variable declarations and input
	//freopen("input.txt", "r", stdin);
	
	int base1, base2;
	lli x, x10, temp;
	int i, j;
	char num[100];
	char res[100] = {};
	int len;
	lli t[100];
	lli ind[100] = {0};
	lli rem[100] = {0};
	
	// integer analogs for our ASCII chars('0'-'9' and 'A'-'Z' -> (1-36))
	for(i = '0'; i <= '9'; i++)
		ind[i] = i - 48;
	for(i = 'A'; i <= 'Z'; i++)
		ind[i] = i - 55;
	
	printf("Index of char '0' in ASCII is:  %d\n", '0');
	printf("Index of char 'A' in ASCII is:  %d\n\n", 'A');
	
	i = 0;
	gets(num);
		
	scanf("%d %d", &base1, &base2);
	printf("Input base1:  %d   |   Input base2:  %d\n", base1, base2);
	printf("Input number string interpretation:   %s\n\n", num);
	
	int l = strlen(num);	// get the length of char array filled with data
	
	for(i = 0; i < l; i++)
		t[i] = ind[num[i]];	// integer interpretation of char values in num array ('0' is 0, 'A' is 10 etc.)
		
	printf("integer interpretation of char values in num array:   ");	
	for(i = 0; i < l; i++)
		printf("%d ", t[i]);
	printf("\n\n");
	
	// convert num to base 10 and save it in x10	
	len = l - 1;
		
	x10 = 0;
		
	while(len >= 0){
		x10 += t[len] * power(base1, l - len - 1);
		len--;
	}
	
	printf("In base 10: %d\n\n", x10);
	
	// convert num from base 10 to base2
	x = x10; i = 0;
	int nl = 0;
	
	while(x > 0){
		rem[i] = x % base2;
		nl++;
		x /= base2;
		i++;
	}
	
	for(i = 0; i < nl; i++)
		printf("%d ", rem[i]);	
	printf("\n\n");
	
	/*
		here we inverse the rem array values,
		as the remainders have to be used in the opposite direction
	*/
	for(i = 0; i < nl / 2; i++){
		temp = rem[i];			
		rem[i] = rem[nl - i - 1];
		rem[nl - i - 1] = temp;
	}
	
	for(i = 0; i < nl; i++)
		printf("%d ", rem[i]);
	printf("\n\n");
	
	/*
		convert the array of integers answer representation to array of chars representation 
	*/
	for(i = 0; i < nl; i++){
		if(rem[i] <= 9){
			res[i] = rem[i] + 48;
		}
		else{
			res[i] = rem[i] + 55;
		}
	}
	
	printf("Converstion result:   ");
			
	for(i = 0; i < nl; i++)
		printf("%c", res[i]);
}

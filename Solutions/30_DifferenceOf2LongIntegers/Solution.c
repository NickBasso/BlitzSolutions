#include <stdio.h>

#define N 10000
const char false = 0;
const char true = 1;

typedef char bool;

void swap(char *a, char *b){
	char temp = *a;
	*a = *b;
	*b = temp;
}

void reverse(char *pointerCharArray, int length){
	int i;
	for(i = 0; i < (length + 1) / 2; i++){
		swap(pointerCharArray + i, pointerCharArray + (length - 1 - i));		
	}		
}

void moveCharArrToInt(char *pointerCharArray, int *pointerIntArray, int length){
	int i;
	for(i = 0; i < length; i++){
		*(pointerIntArray + i) = *(pointerCharArray + i) - (int)('0');
	}
}

int main(){
	
	// input
	freopen("input.txt", "r", stdin);
	
	char a[N] = {0}, b[N] = {0}, t;
	int res[N] = {0}, ia[N] = {0}, ib[N] = {0};			// ia - integer array of a	|  ib - integer array of b
	int i, j;
	int len1, len2, maxLen, temp;
	bool ALessThanB = false;
	
	scanf("%s %s", a, b);
	
	// number 1 length
	for(i = 0; a[i] != 0; i++)
		0;
	len1 = i;
	printf("The number's   %s   length is:   %d\n", a, len1);

	// number 2 length
	for(i = 0; b[i] != 0; i++)
		0;
	len2 = i;
	printf("The number's   %s   length is:   %d\n\n", b, len2);
	
	// maximum length out of two numbers
	maxLen = len1 < len2 ? len2 : len1;
	
	//
	if(len1 < len2){
		ALessThanB = true;
	}
	else if(len1 == len2){
		i = 0;
		while(i < maxLen && a[i] == b[i])
			i++;
			
		if(a[i] < b[i]){
			ALessThanB = true;
		}
	}
	
	if(ALessThanB == true){	
		for(j = 0; j < maxLen; j++){
			t = a[j];
			a[j] = b[j];
			b[j] = t;
		}
	}
	
	// reverse number 1 and output it
	reverse(a, len1);
	moveCharArrToInt(a, ia, len1);
	//printf("%s\n", a);
	for(i = 0; i < len1; i++)
		printf("%d", ia[i]);
	printf("\n");
	
	// reverse number 2 and output it
	reverse(b, len2);
	moveCharArrToInt(b, ib, len2);
	//printf("%s\n\n", b);
	for(i = 0; i < len2; i++)
		printf("%d", ib[i]);
	printf("\n\n");
	
	// main algo implementation
	i = 0; 
	int rem = 0, difTwo, difCur;
	
	for(i = 0; i < maxLen; i++){
		difCur = ia[i] - ib[i];
		difTwo = rem + difCur + (difCur + rem < 0 ? 10 : 0);
		rem = difCur + rem < 0 ? -1 : 0;
		res[i] = difTwo % 10;
	}
	
	if(rem)
		res[i] = rem;
	
	while(res[i] == 0)
		i--;

	ALessThanB ? putchar('-') : 0;
	for(i; i >= 0; i--)
		printf("%d", res[i]);
				
	return 0;
}

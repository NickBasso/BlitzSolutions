#define N 10000
/*const char false = 0;
const char true = 1;

typedef char bool;*/

void reverse(char *pointerCharArray, int length){
	int i;
	for(i = 0; i < (length + 1) / 2; i++){	
		char temp = pointerCharArray[i];
		pointerCharArray[i] = pointerCharArray[length - 1 - i];
		pointerCharArray[length - 1 - i] = temp;	
	}		
}

void moveCharArrToInt(char *pointerCharArray, int *pointerIntArray, int length){
	int i;
	for(i = 0; i < length; i++){
		*(pointerIntArray + i) = *(pointerCharArray + i) - (int)('0');
	}
}

char* sumTwo(char *a, char *b){
	//char a[N] = {0}, b[N] = {0};
	int res[N] = {0}, ia[N] = {0}, ib[N] = {0};			// ia - integer array of a	|  ib - integer array of b
	int i, j;
	int len1, len2, maxLen, temp;
	bool add;
	
	//scanf("%s %s", a, b);
	
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
	int rem = 0, sumTwo;
	
	for(i = 0; i < maxLen; i++){
		sumTwo = ia[i] + ib[i] + rem;
		rem = (sumTwo / 10) % 10;
		
		if(rem)
			res[i] = sumTwo % 10 + add;
		else
			res[i] = sumTwo;
	}
	
	if(rem)
		res[i] = 1;
	else
		i--;
	
	int n = i;
	for(i; i >= 0; i--){
		//printf("%d", res[i]);
		a[n - i] = res[i] + '0';
	}
				
	return a;
}

int main(){
	char a[N] = "999999", b[N] = "999999";
	printf("%s", sumTwo(a, b));
	
	return 0;
}

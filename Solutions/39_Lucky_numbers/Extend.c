#include <stdio.h>
#include <string.h>

#define N 1000000

void swap(char *a, char *b){
	char tmp = *a;
	*a = *b;
	*b = tmp;
}

int isLucky(char *s, int length){
	int i, sumOdd = 0, sumEven = 0;
	
	for(i = 0; i < length; i++){
		if((i + 1) % 2 == 1)
			sumOdd += s[i] - 48;
		else
			sumEven += s[i] - 48;
	}
	
	if(sumOdd == sumEven)
		return 1;
	else
		return 2;
}

void permutate(char *s, int l, int r){
	if(l == r){
		if(isLucky(s, strlen(s)) == 1)
			printf("%s\n", s);
	}
	else{
		int i;	
		
		for(i = l; i <= r; i++){
			swap(s + l, s + i);
			permutate(s, l + 1, r);
			swap(s + l, s + i);
		}	
	}
}

void main(){
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int n, i;
	char s[] = {"121"};

	scanf("%d", &n);
	
	for(i = 0; i <= 9; i++)
		printf("%d\n", i);
	
	for(i = 10; i < N; i++){
		int tmp = i, k = 0;
		
		while(tmp){
			s[k] = (tmp % 10) + 48;
			tmp /= 10;
			k++;
		}
		
		permutate(s, 0, k - 1);
	}
}

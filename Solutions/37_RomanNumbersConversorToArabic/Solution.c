#include <stdio.h>

int main(){
	// declarations and input
	FILE *fp = fopen("input.txt", "r");
	
	char s[10] = {0};
	int ASCII_TABLE['Z' + 1];
	int i, j, ans = 0, len;
	
	ASCII_TABLE['I'] = 1;
	ASCII_TABLE['V'] = 5;
	ASCII_TABLE['X'] = 10;
	ASCII_TABLE['L'] = 50;
	ASCII_TABLE['C'] = 100;
	ASCII_TABLE['D'] = 500;
	ASCII_TABLE['M'] = 1000;
	
	fscanf(fp, "%s", s);
	printf("%s\n\n", s);
	
	// Solution
	i = 0;
	while(s[i] != 0)
		i++;
	len = i;
	
	ans += ASCII_TABLE[s[0]];
	
	i = 1;
	while(i < len){
		if(ASCII_TABLE[s[i - 1]] < ASCII_TABLE[s[i]])
			ans += -2 * ASCII_TABLE[s[i - 1]] + ASCII_TABLE[s[i]];
		else
			ans += ASCII_TABLE[s[i]];
		
		i++;
	}
	
	printf("%d", ans);
	
	return 0;
}

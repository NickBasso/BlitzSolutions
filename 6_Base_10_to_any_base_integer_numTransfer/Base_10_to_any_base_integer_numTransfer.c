#include <stdio.h>

main(){
	//freopen("input.txt", "r", stdin);
	
	int num, base, x, r, i = 0, j = 0;
	int res[256] = {};
	
	scanf("%d %d", &num, &base);
	
	x = num;
	
	/*for(i = 0; i < 10; i++)
		printf("%c\n", res[i]);*/
	printf("Number in decimal system: %d\nTransfer number in base %d\n\n", num, base);
	
	while(x > 0){
		res[i] = x % base;
		x /= base;
		i++;
	}
	
	for(j = i - 1; j >= 0; j--)
		printf("%d", res[j]);
	
	return 0;
}

#include <stdio.h>

void main(){
	FILE *fp = fopen("input.txt", "r");
	int n, i, j, a[100] = {0}, t, pos, k = 0;
	
	fscanf(fp, "%d", &n);
	
	for(i = 0; i < n; i++)
		fscanf(fp, "%d", &a[i]);
		
	i = 1;	
	
	while(i < n){ 
		t = a[i];
		j = i - 1;
		//pos = j;
		
		while(j >= 0 && a[j] > t){
			a[j + 1] = a[j];
			j--;
		} 
		
		a[j + 1] = t; 
		
		i++;
	}
	
	for(i = 0; i < n; i++)
		printf("%d ", a[i]);
	
}

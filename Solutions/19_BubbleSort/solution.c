#include <stdio.h>

void main(){
	FILE *fp = fopen("input.txt", "r");
	int n, i, j, a[100] = {0}, t;
	
	fscanf(fp, "%d", &n);
	
	for(i = 0; i < n; i++)
		fscanf(fp, "%d", &a[i]);
		
	i = 0;	
	while(i < n - 1){
		for(j = 0; j < n - 1; j++){
			if(a[j] > a[j + 1]){
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}	
		}
			
		i++;
	}
	
	for(i = 0; i < n; i++)
		printf("%d ", a[i]);
	
}

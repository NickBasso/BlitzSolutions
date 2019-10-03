#include <stdio.h>

void main(){
	FILE *fp = fopen("input.txt", "r");
	int n, i, j, a[100] = {0}, t, min, pos;
	
	fscanf(fp, "%d", &n);
	
	for(i = 0; i < n; i++)
		fscanf(fp, "%d", &a[i]);
		
	i = 0;
	while(i < n - 1){
		min = a[i];
		pos = i;
		
		for(j = i + 1; j < n; j++){
			if(a[j] < min){
				min = a[j];
				pos = j;
			}	
		}
		
		t = a[i];
		a[i] = a[pos]; // a[i++] = min;    same as     a[i] = min; i++;
		a[pos] = t;
		
		i++;
	}
	
	for(i = 0; i < n; i++)
		printf("%d ", a[i]);
	
}

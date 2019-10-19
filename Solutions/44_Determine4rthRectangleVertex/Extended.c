#include <stdio.h>
#include <stdlib.h>

struct Point{
	float x, y;
};

/*int cmp(const void *a, const void *b){
	//return (*(float*)a > *(float*)b ? *(float*)a : *(float*)b);
	return ( *(float*)a - *(float*)b );
}*/

int cmp(const void *a, const void *b){
	struct Point *f = (struct Point *)a;
	struct Point *s = (struct Point *)b;
	
	return ((f->x) - (s->x));
}

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

/*int abs(int *a, int *b){
	return (*a < *b ? *b - *a : *a - *b);
}*/

int main(){
	freopen("input.txt", "r", stdin);
	
	struct Point cds[5];
	int i, j;
	
	for(i = 0; i < 3; i++){
		scanf("%f%f", &cds[i].x, &cds[i].y);
		printf("%f  %f\n", cds[i].x, cds[i].y);
	}
		
	printf("\n\n");		 
		
	qsort(cds, 3, sizeof(struct Point), cmp);
	
	for(i = 0; i < 3; i++){
		printf("%f  %f\n", cds[i].x, cds[i].y);
	}
	printf("\n");
	
	float difx, dify;
	difx = abs(cds[0].x - cds[2].x);
	dify = abs(cds[1].y - cds[2].y);
	
	printf("%f  %f\n\n", difx, dify);
	
	printf("%f  %f", cds[1].x - difx, cds[0].y + dify);
	return 0;
}

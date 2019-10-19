#include <stdio.h>

struct Point{
	int x, y;
};

int main(){
	freopen("input.txt", "r", stdin);
	
	struct Point cords[5];	// cords - coordinates
	int i, j, x1 = 0, x2 = 0, x3 = 0, y1 = 0, y2 = 0, y3 = 0, x4, y4;
	int count[5] = {0};
	
	for(i = 1; i <= 3; i++)
		scanf("%d%d", &cords[i].x, &cords[i].y);
		
	for(i = 1; i <= 3; i++)
		printf("%d  %d\n", cords[i].x, cords[i].y);
		
	puts("\n\n");
		
	if(cords[1].x == cords[2].x)
		printf("%d  ", cords[3].x);
	else if(cords[1].x == cords[3].x){
		printf("%d  ", cords[2].x);
	}
	else{
		printf("%d  ", cords[1].x);
	}
		
	if(cords[1].y == cords[2].y)
		printf("%d  ", cords[3].y);
	else if(cords[1].y == cords[3].y){
		printf("%d  ", cords[2].y);
	}
	else{
		printf("%d  ", cords[1].y);
	}
	
	return 0;
}

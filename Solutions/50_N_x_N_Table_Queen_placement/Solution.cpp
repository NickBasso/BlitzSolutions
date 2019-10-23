#include <bits/stdc++.h>
#define N 8

// print the table
void printSolution(int board[N][N]){
	static int k = 1;
	printf("%d-\n", k++);
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++)
			printf(" %d ", board[i][j]);
		printf("\n");
	}
	
	printf("\n");
}

// check if there are any queens that clash the queen on the (row, col) position
// we are only checking the tiles left to the (row, col) position 
bool isSafe(int board[N][N], int row, int col){
	int i, j;
	
	// check if there no other queens on the same line
	for(i = 0; i < col; i++)
		if(board[row][i])
			return false;
			
	// check if there are no other queens in the upper diagonal
	for(i = row, j = col; i >= 0 && j >= 0; i--, j--)
		if(board[i][j])
			return false;
			
	// check if there are no other queens in the lower diagonal		
	for(i = row, j = col; j >= 0 && i < N; i++, j--)
		if(board[i][j])
			return false;
			
	// none found
	return true;
}

// recursive solution function
bool solveNQUtil(int board[N][N], int col){
	// if all queens are placed then solved
	if(col == N){
		printSolution(board);
		return true;
	}
	
	// consider this column and try placing this queen in all rows consequently
	bool res = false;
	for(int i = 0; i < N; i++){
		// check if a queen can be plaxed on (i,col) position
		if(isSafe(board, i, col)){
			// place the queen on (i,col) position
			board[i][col] = 1;
			
			// true if any placement is possible
			res = solveNQUtil(board, col + 1) || res;
		
			// if solveNQUtil doesnt reach col == N then remove the queen
			// and backtrack
			board[i][col] = 0;
		}
	}
	
	return res;
}

void solveNQ(){
	int board[N][N];
	memset(board, 0, sizeof(board));
	
	if(solveNQUtil(board, 0) == false){
		printf("Solution does not exit");
		return;
	}
	
	return;
}

int main(){
	solveNQ();
	return 0;
}



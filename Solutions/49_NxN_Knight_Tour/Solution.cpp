#include <iostream>

using namespace std;

const int N = 1000;

int n; // number of lines and colums in chess table
int sol[N][N];	// table of numbers of moves
int xMove[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };	// table of x moves possible for the knight 
int yMove[8] = {  1, 2,  2,  1, -1, -2, -2, -1 }; 	// table of y moves possible for the knight

// prints the solution table which consists of moves required to get to the tile (i, j)
void printSolution(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			cout << sol[i][j] << " ";
		cout << "\n";
	}
}

// checks wether we may move to the tile (x, y) (it must be within the table and unvisited)
bool isValidMove(int x, int y){
	if(	x >= 0 && x < n && 
	   	y >= 0 && y < n &&
		sol[x][y] == -1 )
		{
			return true;
		}
	else
		{
			return false;
		}
}

bool solve(int x, int y, int curMove){
	sol[x][y] = curMove;
	
	if(curMove == n * n - 1){
		return true;
	}
	
	for(int k = 0; k < 8; k++){
		int nextX = x + xMove[k];
		int nextY = y + yMove[k];
		
		if(isValidMove(nextX, nextY) == true){	
			if(solve(nextX, nextY, curMove + 1) == true){
				return true;
			}
		}
	}
	
	sol[x][y] = -1;
	
	return false;
}

// first auxilary function invoked to find the solution
bool start(){
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++){
			sol[i][j] = -1;		// define all table tiles unvisited
		}
	
	sol[0][0] = 0;	//moves needed to get to the starting position is none (0)
	
	if(solve(0, 0, 0) == false){
		cout << "There is no solution\n";
		return false;
	}
	else{
		printSolution();
	}	
	
	return true;
}

int main(){
	freopen("input.txt", "r", stdin);
	
	cin >> n;
	
	start();
	
	return 0;
}

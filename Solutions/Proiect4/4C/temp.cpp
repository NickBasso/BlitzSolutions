#include <iostream>
#include <vector>
#include <cmath>

#define mp make_pair
#define pb push_back

using namespace std;

int n, k;

vector < vector < pair < int, char > > > AdjList;
vector < int > level;
vector < char > visited;
int count, passed;
bool found;

findLevel(int vertex, int from){
	visited[vertex] = 1;
	for(int i = 0; i < AdjList[vertex].size(); i++){
		if(!visited[AdjList[vertex][i].first]){
			count++;
			findLevel(AdjList[vertex][i].first, vertex);
		}
		else if(level[vertex] < level[AdjList[vertex][i].first] + 1){
			level[vertex] = level[AdjList[vertex][i].first] + 1;
		}
		
		if(found && passed >= 0 && count - passed > level[vertex]){
			level[vertex] = count - passed;
			passed--;
		}
		else{
			passed = count - level[vertex] - 1;
		}
		
		if(i < AdjList[vertex].size() - 1)                
			count--;
	}
	
	if(!AdjList[vertex].size() && from != -1 && level[from] - 1 > 0){
		level[vertex] = level[from] - 1;
	}
	else if(!AdjList[vertex].size()){
		found = true;
		passed = count;
		level[vertex] = count - passed;
		passed--;
	}
}

findLevel2(int vertex, int from){
	for(int i = 0; i < AdjList[vertex].size(); i++){
		if(level[AdjList[vertex][i].first] >= level[vertex]){
			level[vertex] = level[AdjList[vertex][i].first] + 1;
		}
	}
}

int main(){
	freopen("input.txt", "r", stdin);
	
	cin >> n >> k;
	
	AdjList.resize(n + 1);
	visited.resize(n + 1);
	level.resize(n + 1);
	
	int from, to;
	char side;
	for(int i = 0; i < n - 1; i++){
		cin >> from >> to >> side;
		
		AdjList[from].pb(mp(to, side));
	}
	
	// intermediary output
	for(int i = 0; i <= n; i++){
		cout << i << ":  ";
		for(int j = 0; j < AdjList[i].size(); j++){
			cout << AdjList[i][j].first << " " << AdjList[i][j].second << "  |  ";
		}
		cout << "\n";
	}
	
	for(int i = 1; i <= n; i++){
		if(!visited[i]){
			found = false;
			count = passed = 0;
			findLevel(i, -1);
		}
	}
	
	for(int i = 0; i <= n; i++)
		visited[i] = 0;
		
	for(int i = 1; i <= n; i++){
		findLevel2(i, -1);

	}	
	
	for(int i = 1; i <= n; i++){
		cout << i << ":  " << level[i] << "\n";
	}
	
	return 0;
}

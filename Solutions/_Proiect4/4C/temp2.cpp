#include <iostream>
#include <vector>
#include <cmath>

#define mp make_pair
#define pb push_back

using namespace std;

int n, k;

vector < vector < pair < int, char > > > AdjList;
vector < char > visited;
vector < int > subNodes;

bool found;
int count;
int rootSubNodes = 0;
int rootNumber = 1;

int calls;
int operations;

void countSubTreeVertices(int vertex){
	operations += 8;
	calls++;
	
	int i;
	for(i = 0; i < AdjList[vertex].size(); i++){
		count++;
		countSubTreeVertices(AdjList[vertex][i].first);
	}
}

void setSubTreeCounts(int vertex, int from){
	operations += 20;
	calls++;
	
	visited[vertex] = 1;
	if(from != -1)
		subNodes[vertex] = subNodes[from] - 1;
		
	for(int i = 0; i < AdjList[vertex].size(); i++){
		if(!visited[AdjList[vertex][i].first])
			setSubTreeCounts(AdjList[vertex][i].first, vertex);
	}
}

void sortAdjList(){
	for(int i = 0; i <= n; i++){
		if(AdjList[i].size() == 2 && AdjList[i][0].second == 'D'){
			swap(AdjList[i][0], AdjList[i][1]);
		}
	}
}

void findLeft(int vertex, int level){
	if(level == k && !found){
		cout << vertex;
		found = true;
	}
	
	if(!found){
		for(int i = 0; i < AdjList[vertex].size(); i++){
			findLeft(AdjList[vertex][i].first, level + 1);
		}	
	}
}

void findRight(int vertex, int level){
	if(level == k && !found){
		cout << vertex;
		found = true;
	}
	
	if(!found){
		for(int i = AdjList[vertex].size() - 1; i >= 0; i--){
			findRight(AdjList[vertex][i].first, level + 1);
		}	
	}
}

int main(){
	freopen("input.txt", "r", stdin);
	
	cin >> n >> k;
	
	AdjList.resize(n + 1);
	visited.resize(n + 1);
	subNodes.resize(n + 1);
	
	int from, to;
	char side;
	for(int i = 0; i < n - 1; i++){
		cin >> from >> to >> side;
		
		AdjList[from].pb(mp(to, side));
	}
	
	/*// intermediary output
	for(int i = 0; i <= n; i++){
		cout << i << ":  ";
		for(int j = 0; j < AdjList[i].size(); j++){
			cout << AdjList[i][j].first << " " << AdjList[i][j].second << "  |  ";
		}
		cout << "\n";
	}
	
	cout << "\n\n";*/
	
	for(int i = 1; i <= n; i++){
		count = 0;
		countSubTreeVertices(i);
		subNodes[i] = count;
		if(subNodes[i] > rootSubNodes){
			rootSubNodes = subNodes[i];
			rootNumber = i;
		}
		setSubTreeCounts(i, -1);
	}
	
	/*for(int i = 1; i <= n; i++){
		cout << i << ": " << subNodes[i] << "\n";
	}
	
	cout << "Root number is:  " << rootNumber << "   Subnodes amount in root is:  " << rootSubNodes << "\n\n";*/
	
	sortAdjList();
	
	found = false;
	findLeft(rootNumber, 0);
	cout << " ";
	
	found = false;
	findRight(rootNumber, 0);
	
	//cout << "\n\ncalls: " << calls << "  |  operations: " << operations;
	
	return 0;
}

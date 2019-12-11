#include <iostream>
#include <vector>
#include <set>

using std::cin;
using std::cout;
using std::vector;
using std::set;

int n;

set < vector < int > > arrangements;

/*
	operations:
		1) add last element from entry line to depot
		2) add last element from entry line directly to exit line
		3) add last element from depot to exit line	
*/

void find(vector < int > in, vector < int > depot, vector < int > out){
	
	if(out.size() == n){
		arrangements.insert(out);
		/*// intermediary output
		cout << "New:  ";
		for(auto c : out)
			cout << c << " ";
		cout << "\n\n";
		//*/
	}
		
	vector < int > t_in(in), t_depot(depot), t_out(out);
	
	/*// intermediary output
	for(auto c : t_in)
			cout << c << " ";
		cout << "   |   ";
	for(auto c : t_depot)
			cout << c << " ";
		cout << "   |   ";
	for(auto c : t_out)
			cout << c << " ";
		cout << "\n\n";*/
	
	// add last element from entry line to depot
	if(t_in.size() > 0){
		t_depot.push_back(t_in.back());
		t_in.pop_back();
		find(t_in, t_depot, t_out);
	}
	
	// return to previous values changed in t_depot and t_in
	t_in = in; t_depot = depot; 
	
	// add last element from entry line directly to exit line
	if(t_in.size() > 0){ 
		t_out.insert(t_out.begin(), t_in.back());
		t_in.pop_back();
		find(t_in, t_depot, t_out);
	}
	
	// return to previous values changed in t_in and t_out
	t_in = in; t_out = out;
	
	// add last element from depot to exit line
	if(t_depot.size() > 0){
		t_out.insert(t_out.begin(), t_depot.back());
		t_depot.pop_back();
		find(t_in, t_depot, t_out);
	}
}

int main(){
	freopen("input.txt", "r", stdin);
	
	cin >> n;
	
	vector < int > in(0);
	vector < int > depot(0);
	vector < int > out(0);
	
	for(int i = 1; i <= n; i++){
		in.push_back(n - i + 1); 
	}
		
	find(in, depot, out);
	
	// output the valid arrangements
	set < vector < int > > :: iterator it;
	for(it = arrangements.begin(); it != arrangements.end(); it++){
		vector < int > temp = *it;
		
		for(int val : temp){
			cout << val;
		}
		cout << "\n";
	}
	cout << arrangements.size() << "\n";
	
	return 0;
}

#include <iostream>
#include <vector>

using namespace std;

#define pb push_back

const int SIZE = 100;

int n, m;
int last_add[SIZE];
vector < int > final;

bool check(vector < int > &seq, int pos, int taken, int k){
	for(int i = 0; i < seq.size(); i++)	// intermediary output
		cout << seq[i] << " ";
	cout << "  |  ";
	
	/*if(pos + 1 <= n - 1 && seq[pos + 1] > 0){
		taken++;
		seq[pos + 1]--;
	}
	else if(pos + 1 <= n - 1 && seq[pos + 1] <= 0){
		return false;
	}
	else if(pos + 1 == n - 1 && seq[0] > 0){
		taken++;
		seq[0]--;
	}
	else{
		return false;
	}*/
	taken++;
	pos + 1 <= n - 1 ? seq[pos + 1]-- : seq[0]--;
	
	vector < int > temp = seq;
	
	for(int i = 0; i < temp.size(); i++)	// intermediary output
			cout << seq[i] << " ";
	cout << "  |  taken = " << taken;
	cout << "\n";
	
	int balls = temp[pos] + taken;
	int cnt = balls;
	temp[pos] = 0;
	
	int i = pos + 1 <= n - 1 ? pos + 1 : 0;
	int pos_last = i;
	while(cnt > 0){
		pos_last = i;
		temp[i]++;
		i = i + 1 <= n - 1 ? i + 1 : 0;
		cnt--;
	}

	for(i = 0; i < temp.size(); i++){
		if(temp[i] != final[i]){
			return false;
		}
	}
	
	if(pos_last == k){
		seq[pos] = balls;
		cout << "Found! : ";
		for(int i = 0; i < seq.size(); i++)
			cout << seq[i] << " ";
		cout << "\n";
		
		m--;
		
		return true;
	}	
	else
		return false;
}

int main(){
	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	
	cout << "n = " << n << "  m = " << m << "\n";	// intermediary output
	
	for(int i = 0; i < n; i++){
		int quantity;
		cin >> quantity;
		final.pb(quantity);
		
		cout << quantity << " ";	// intermediary output
	}
	cout << "\n";	// intermediary output
			
	for(int i = 0; i < m; i++){
		cin >> last_add[i];
		cout << last_add[i] << " ";	// intermediary output
	}
	cout << "\n\n"; 	// intermediary output
		
	
	vector <int> seq = final;
	bool not_found = true;
	int i = last_add[m - 1] - 1;
	int taken = -1;
	while(m > 0 && not_found){
		not_found = true;
		
		if(check(seq, i, taken + 1, last_add[m - 1] - 1) == true){
			not_found = false;
			i = last_add[m - 1] - 1;
			taken = -1;
			continue;
		}
		i = i - 1 >= 0 ? i - 1 : n - 1;
		taken++;
	}
	
	
	return 0;
}


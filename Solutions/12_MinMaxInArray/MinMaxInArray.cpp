#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int main(){
	freopen("input.txt", "r", stdin);
	int n, i, min = INT_MAX, max = INT_MIN, a[N] = {0};
	
	//cout << min << "  " << max << "\n\n";
	cin >> n;
	
	for(i = 0; i < n; i++){
		cin >> a[i];
		
		if(a[i] > max)
			max = a[i];
		if(a[i] < min)
			min = a[i];
	}
	
	cout << min << "  " << max;
	
	return 0;
}

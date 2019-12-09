#include <iostream>

using namespace std;

int main(){
	freopen("input.txt", "r", stdin);
	
	int n, i, j, ans = 1;
	
	cin >> n;
	
	int a[n+1] = {0};
	
	for(i = 0; i < n; i++){
		cin >> a[i];
	}
	
	int highest = 0;
	for(i = n - 2; i >= 0; i--){
		if(a[i + 1] > highest){
			highest = a[i + 1];
		}
		
		if(highest < a[i]){
			ans++;
		}
	}
	
	cout << ans;
}

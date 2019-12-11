#include <iostream>

using namespace std;

int main(){
	freopen("input.txt", "r", stdin);
	
	int n, i, j, ans = 1;
	
	cin >> n;
	
	int a[n+1] = {0};
	
	for(i = 0; i < n; i++)
		cin >> a[i];

	int last_predecessor = a[n - 1], pos = n - 1;
	for(i = n - 2; i >= 0; i--){
		if(last_predecessor < a[i])
			ans++;
			
		pos = i;
		last_predecessor = a[i];
	}
	
	cout << ans;
}

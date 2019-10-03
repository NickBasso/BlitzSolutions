#include <iostream>
#include <cmath>

using namespace std;

int main(){
	
	long long int n, i, x = 2, cnt = 0, root;
	
	cin >> n;
	
	while(cnt < n){
		root = sqrt(x);
		
		for(i = 2; i <= root; i++)
			if(x % i != 0){
				continue;
			}
			else{
				break;
			}
			
		if(i > root){
			cout << cnt + 1 << ". " << x << "\n";
			cnt++;
		}
		
		x++;
	}
	
	return 0;
}

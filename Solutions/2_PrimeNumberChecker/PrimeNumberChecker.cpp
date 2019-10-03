#include <iostream>
#include <cmath>

using namespace std;

int main(){
	
	long long int n, i, root;
	
	cin >> n;
	
	root = sqrt(n);
	
	for(i = 2; i <= root; i++)
		if(n % i == 0){
			cout << n << " is not prime";
			break;
		}
				
	if (i > root)
		cout << n << " is prime";
	
	return 0;
}

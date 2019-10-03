#include <iostream>

using namespace std;

int main(){
	int n;
	
	cout << 2352 / 1000 << endl;
	cout << 1352 / 100 % 10 << endl;
	cout << 1352 / 10 % 10 << endl;
	cout << 1352 % 10 << "\n\n\n\n\n\n";
	
	cin >> n;
	
	int t = n, l = 0;
	
	while(t){
		l++;
		t/=10;
	}
	
	cout << "The length of number " << n << " is " << l << "\n\n";
	
	int k = 0;
	
	while(k < l){
		t = n;
		for(int i = 0; i < l - k - 1; i++){
			t /= 10;
		}
		
		t %= 10;
		
		cout << t << "  ";
		
		k++;
	}
	
}

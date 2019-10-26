#include <iostream>

using namespace std;

// In Roman numbers maximum 1 symbol is allowed before the main one
// to decrease the number and 3 after the main to increase the number

int main(){
	freopen("input.txt", "r", stdin);
	
	int n, M, D, C, L, X, V, I, temp;
	string ans;
	
	cin >> n;
	cout << n << "  ";
	
	while(n){
		M = D = C = L = X = V = I = 0;
		
		if(n / 1000){
			M += n / 1000;
			ans += string(M, 'M');
			n -= M * 1000;
		}
		
		if(n >= 900 && n < 1000){
			ans += "CM";
			n -= 900;
		}
		
		if(n / 500){
			D += n / 500;
			ans += "D";
			n -= 500;
		}
		
		if(n >= 400 && n < 500){
			ans += "CD";
			n -= 400;
		}
		
		if(n >= 100 && n < 400){
			C += n / 100;
			ans += "C";
			n -= 100;
		}
		
		if(n >= 90 && n < 100){
			ans += "XC";
			n -= 90;
		}
		
		if(n >= 50 && n < 90) {
			L += n / 50;
			ans += "L";
			n -= 50;
		}
		
		if(n >= 40 && n < 50){
			ans += "XL";
			n -= 40; 
		}
		
		if(n >= 10 && n < 40){
			X += n / 10;
			ans += string(X, 'X');
			n -= 10 * X;
		}
		if(n == 9){
			ans += "IX";
			n -= 9;
		}
		
		if(n >= 5 && n < 9){
			V += n / 5;
			ans += "V";
			n -= 5;
		}
		
		if(n == 4){
			ans += "IV";
			n -= 4;
		}
			
		if(n > 0 && n < 4){
			ans += "I";
			n--;
		}	
	}
	
	cout << ans;
	
	return 0;
}

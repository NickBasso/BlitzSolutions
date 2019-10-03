#include <iostream>

using namespace std;

double sr(double n) 									// sr -> square root
    { 
        double x = n; 
        double y = 1; 
        double e = 0.000001; 							// e -> epsilon
        while (x - y > e) { 
            x = (x + y) / 2; 
            y = n / x; 
        } 
        return x; 
    } 
    
int main(){
	double n;
	
	cin >> n;
	
	cout << "Square root of " << n << " is " << sr(n);
	
	return 0;
}

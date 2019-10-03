#include <iostream>

using namespace std;

long long int gcd_eul(long long int a, long int b)
{
    if (b)
        return gcd_eul(b, a % b);
    else
        return a;
}

int main(){
	
	cout << gcd_eul(-15, -25);
	
	return 0;
}

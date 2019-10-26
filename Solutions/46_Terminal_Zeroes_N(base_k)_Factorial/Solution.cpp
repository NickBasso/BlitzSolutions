#include <iostream>
#include <cmath>

using namespace std;

typedef unsigned long long ull;

ull primeNumbers[100000];		// first 100000 prime numbers
ull prFactN[100000];			// prime factorization elements of input number N 

ull countTerminatingZeroes(ull biggestFactor, ull timesFoundInBasePrimeFactorization, ull n){
	ull k = biggestFactor, count = 0;
	
	while(k <= n){
		count += n / k;			// modify answer
		k *= biggestFactor;		// multiply current degree of biggestFactor by biggestFactor
	}
	
	return count / timesFoundInBasePrimeFactorization;
}

ull timesBiggestFactor(){
	int i = 1, count = 1;
	
	while(prFactN[i] == prFactN[i - 1]){
		count++;
		i++;
	}
		
			
	return count;
}

void primeFactorization(ull n){
	ull i = 10000, j, k = 0;
	
	while(n > 1 && i >= 0){
		if(n % primeNumbers[i] == 0){
			prFactN[k++] = primeNumbers[i];
			n /= primeNumbers[i];
		}
		else{
			i--;
		}
	}
			
	for(i = 0; i < k; i++)
		cout << prFactN[i] << " * ";
}

void calcPrimes(){
	ull k = 0, i, j;
	
	for(i = 2; i < 1000000; i++){
		ull untill = sqrt(i);
		for(j = 2; j <= untill; j++)
			if(i % j == 0){
				break;
			}
		
		if(j == untill + 1){
			primeNumbers[k++] = i;
			//cout << primeNumbers[k - 1] << "\n";
		}	
	}
}

int main(){
	freopen("input.txt", "r", stdin);
	
	ull n, k, times, ans;
	cin >> n >> k;
	
	calcPrimes();
	primeFactorization(k);	
	times = timesBiggestFactor();	
	ans = countTerminatingZeroes(prFactN[0], times, n);
	
	cout << "\n" << ans;
	
	return 0;
}

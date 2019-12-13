#include<iostream> 
#include <cstdio>
#include <cstdlib>
#include "string.h"
#include "longSum.h"
#include "longMult.h"

using namespace std; 

int op = 0;
char d[10000][1000];
char arr[N];

// A recursive function to find nth catalan number 
/*unsigned long int catalan(unsigned int n) 
{ 
op++;
    // Base case 
    if (n <= 1) return 1; 

    // catalan(n) is sum of catalan(i)catalan(n-i-1) 
    unsigned long int res = 0; 
    for (int i = 0; i < n; i++){
    	if(d[i] != 0 && d[n - i - 1])
    		res += d[i] * d[n - i - 1];
		else if(d[i] != 0)
			res += d[i] * catalan(n - i - 1);
		else if(d[n - i - 1] != 0)
			res += catalan(i) * d[n - i - 1];
    	else
			res += catalan(i) * catalan(n-i-1);	
	}
	
	d[n] = res;
    return res; 
}*/
char* catalan(int n) 
{ 
	op++;
    // Base case 
    if (n <= 1) return "1"; 

    // catalan(n) is sum of catalan(i)catalan(n-i-1) 
    
    for(int i = 0; i < N; i++)
    	arr[i] = 0;
    arr[0] = '0';
    	
    char *res = arr;
    // 2 + 
    for (int i = 0; i < n; i++){
    	if(d[i][0] != '0' && d[n - i - 1][0] != '0'){
    		char *tmp = sumTwo(res, multTwo(d[i], d[n - i - 1]));
    		//res = sumTwo(res, multTwo(d[i], d[n - i - 1]));
    		for(int i = 0; i < N; i++){
    			res[i] = tmp[i];
			}
		}
    	 	
    		//res += d[i] * d[n - i - 1]; // res = sumTwo(res, multTwo(d[i], d[n - i - 1]))
		else if(d[i][0] != '0')
			//res += d[i] * catalan(n - i - 1);
			res = sumTwo(res, multTwo(d[i], catalan(n - i - 1)));
		else if(d[n - i - 1][0] != '0')
			//res += catalan(i) * d[n - i - 1];
			res = sumTwo(res, multTwo(catalan(i), d[n - i - 1]));
    	else
			//res += catalan(i) * catalan(n-i-1);	
			res = sumTwo(res, multTwo(catalan(i), catalan(n-i-1)));
	}
	
	for(int i = 0; i < N; i++){
		d[n][i] = res[i];
	}
	//d[n] = res;
    return res; 
} 

// Driver program to test above function 
int main() 
{ 
	d[0][0] = d[1][0] = '1';
	char a[N] = "1", b[N] = "1";
	
    for (int i = 0; i < 50000; i++) 
        cout << "catalan " << i << " = " << catalan(i) << "\n\n"; 
        
    cout << op;
    return 0; 
}

#include<iostream> 
#include <cstdio>
#include "string.h"
#include "longSum.h"
#include "longMult.h"

using std::cout;

int op = 0;
char d[N][N];
char arr[N];

char* wagons(int n) 
{ 
	op++;
    if (n <= 1) return "1"; 
    
    for(int i = 0; i < N; i++)
    	arr[i] = 0;
    arr[0] = '0';
    	
    char *res = arr;
    for (int i = 0; i < n; i++){
    	if(d[i][0] != '0' && d[n - i - 1][0] != '0'){
    		char *tmp = sumTwo(res, multTwo(d[i], d[n - i - 1]));
    		for(int i = 0; i < N; i++){
    			res[i] = tmp[i];
			}
		}
	}
	
	for(int i = 0; i < N; i++){
		d[n][i] = res[i];
	}

    return res; 
} 

int main() 
{ 
	d[0][0] = d[1][0] = '1';
	
    for (int i = 0; i < 50000; i++) 
        cout << "wagons " << i << " = " << wagons(i) << "\n\n"; 
        
    cout << op;
    return 0; 
}

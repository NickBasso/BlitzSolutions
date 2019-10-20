#include <iostream>

using namespace std;

int main(){
	freopen("input.txt", "r", stdin);
	
	int n, i, j, tmp, x, ans = 0;
	
	cin >> n;
	
	int base1 = 10, base2;				
	char res[100] = {};							// array of result after conversion in char form
	int len;									// length
	bool digitSetN10[100], digitSetN_X[100];	// digit set of number in base 10 and digit set of number in base X
	int rem[100] = {0};							// array of division remainders
	
	for(int num = 1; num <= n; num++){
		for(int i = 0; i < 100; i++)
		digitSetN10[i] = false;
		
		//cout << "Input number in base 10 is  ->  " << n << "    ";
		
		int l = 0;	// get the length of the number
		
		tmp = num;
		while(tmp){
			digitSetN10[tmp % 10] = true;
			tmp /= 10;
			l++;
		}
		
		for(int base2 = 2; base2 <= 16; base2++){
			if(base2 == 10)
				continue;
			// convert num from base 10 to base2
			for(int i = 0; i < 100; i++)
				digitSetN_X[i] = false;
		
			x = num; i = 0;
			int nl = 0;
			
			while(x > 0){
				rem[i] = x % base2;
				nl++;
				x /= base2;
				i++;
			}
			
			/*
				here we inverse the rem array values,
				as the remainders have to be used in the opposite direction
			*/
			for(i = 0; i < nl / 2; i++){
				tmp = rem[i];			
				rem[i] = rem[nl - i - 1];
				rem[nl - i - 1] = tmp;
			}
			
			/*
				convert the array of integers answer representation to array of chars representation 
			*/
			for(i = 0; i < nl; i++){
				if(rem[i] <= 9){
					res[i] = rem[i] + 48;
				}
				else{
					res[i] = rem[i] + 55;
				}
			}
			
			cout << "Conversion result of  " << num << " in base  " << base2 << "  is  ";
					
			for(i = 0; i < nl; i++)
				printf("%c", res[i]);
				
			for(i = 0; i < nl; i++)
				digitSetN_X[rem[i]] = true;
			
			i = 0;
			while(i <= 16 && digitSetN10[i] == digitSetN_X[i])
				i++;
				
			if(i == 17){
				ans++;
				cout << "   YES!!!\n\n";
				break;
			}
			cout << "\n\n";
		}
	}
	
	
	cout << "\n\n" << ans;
	
	return 0;
}

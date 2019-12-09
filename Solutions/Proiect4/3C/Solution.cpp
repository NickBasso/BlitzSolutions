#include <iostream>

using namespace std;

char operationPriority[255] = {0};
	
int calculate(char *s){
	int i = 0;
	int curPr = 0;
	int pos = 0;
	int bracketsCounter = 0;
	char operation = 0;
	
	while(s[i] != 0){
		if(s[i] == '(')
			bracketsCounter++;
		if(s[i] == ')')
			bracketsCounter--;
		
		if(bracketsCounter == 0 && operationPriority[s[i]] <= curPr){
			curPr = operationPriority[s[i]];
			pos = i;
		}	
		
		i++;
	}
	
	if(curPr < 0){
		operation = s[pos];
		s[pos] = 0;
		
		switch(operation){
			case '|' : return ((calculate(s)) | (calculate(s + pos + 1)));
			case '^' : return ((calculate(s)) ^ (calculate(s + pos + 1)));
			case '&' : return ((calculate(s)) & (calculate(s + pos + 1)));
			case '!' : return !(calculate(s + pos + 1));
		}
	}
	else if(isInBrackets(s, i) == true){
		return calculateInBrackets(s, i);
	}
	else if(isAlgebraicFunction(s) == true){
		return calculateAlgebraicExpression(s);
	}
	else if(isNumber(s) == true){
		return StringToDouble(s);
	}
	else{
		Throw_Exception();
	}
}

int main(){
	freopen("input.txt", "r", stdin);
	
	char s[1000] = {0};
	
	gets(s);
	printf("%s\n", s);
	
	// set operation priority for the main algorithm logic
	operationPriority['|'] = -4;
	operationPriority['^'] = -3;
	operationPriority['&'] = -2;
	operationPriority['!'] = -1;
	
	// remove all spaces and print the string again 
	if(RemoveSpaces(s) == true){
		printf("\nNormalized form of the expression:\n%s\n\n", s);
	}
	
	// calculate the expression value
	int ans = calculate(s);
	
	
	return 0;
}

#include <iostream>

using namespace std;

char vars[255] = {0};
char operationPriority[255] = {0};

int calculate(char *s);
char isInBrackets(char *s, int size);
char isNumber(char *s);
int StringToInt(char *s);
int PowerOfX(int num, int exponent);
int Throw_Exception();
void RemoveSpaces(char *s);
int StringLength(char *s);

int StringLength(char *s){
	int i = 0;
	
	while(s[i] != '\0'){
		i++;
	}
	
	return i;
}

void RemoveSpaces(char *s){
	int i = 0;
	int len = StringLength(s);
	
	for(i = 0; i < len; i++){
		if(s[i] == ' '){
			int j = i + 1;
			
			while(s[j] == ' '){
				j++;
			}
			
			s[i] = s[j];
			s[j] = ' ';
		}
	}
	
	i = 0;
	while(s[i] != '\0'){
		i++;
	}
}

int Throw_Exception(){
	puts("Incorrect logic expression entered!");
	exit(0);	
}

int PowerOfX(int num, int exponent){
	int i = 0;
	int result = 1;
	
	for(i = 0; i < exponent; i++){
		result *= num;
	}	
	
	return result;
}

int StringToInt(char *s){	
	int i = 0;
	int dots = 0;
	int dotPosition = -1;
	
	while((s[i] >= '0' && s[i] <= '9') ^ s[i] == '.'){
		if(s[i] == '.'){
			dots++;
			dotPosition = i;
		}
			
		i++;
	}
	
	int length = i;
	
	if(dots == 0){
		dotPosition = length;
	}
	
	int number = 0;
	int integralPart = 0;
	int fractionalPart = 0;
	int curDigit;
	
	int k = 0;
	int j;
	
	
	k = 0;
	
	for(i = dotPosition - 1; i >= 0; i--){
		curDigit = (s[i] - '0') % 10;

		integralPart += PowerOfX(10, k) * curDigit;
		
		k++;
	}
	
	number = integralPart;
	
	return number;
}

char isNumber(char *s){
	int dotsCount = 0;
	
	if(s[0] >= '0' && s[0] <= '9'){
		int i = 0;
		
		while((s[i] >= '0' && s[i] <= '9') || s[i] == '.'){
			i++;
		}
		
		if(dotsCount < 2){
			return true;
		}			
	}
	else if(s[0] == 0){
		return true;
	}
	else{
		return false;
	}
}

char isInBrackets(char *s, int size){
	if(s[0] == '(' && s[size - 1] == ')'){
		return true;
	}
	else{
		return false;
	}
}

int calculateInBrackets(char *s, int size){
	s[0] = 0;
	s[size - 1] = 0;
	return calculate(s + 1);
}
	
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
			case '|' : return ((calculate(s)) || (calculate(s + pos + 1)));
			case '^' : return ((calculate(s)) ^ (calculate(s + pos + 1)));
			case '&' : return ((calculate(s)) && (calculate(s + pos + 1)));
			case '!' : return (!(calculate(s + pos + 1)));
		}
	}
	else if(isInBrackets(s, i) == true){
		return calculateInBrackets(s, i);
	}
	else if(isNumber(s) == true){
		return StringToInt(s);
	}
	else{
		Throw_Exception();
	}
}

int main(){
	freopen("input.txt", "r", stdin);
	
	printf("Operation precedence:\nNOT > AND > XOR > OR\n\n");
	printf("NOT -> !\n");
	printf("AND -> &\n");
	printf("XOR -> ^\n");
	printf("OR -> |\n");
	
	char s[1000] = {0};
	
	gets(s);
	printf("\n%s\n", s);
	
	// set operation priority for the main algorithm logic
	operationPriority['|'] = -4;
	operationPriority['^'] = -3;
	operationPriority['&'] = -2;
	operationPriority['!'] = -1;
	
	// remove all spaces and print the string again 
	RemoveSpaces(s);
		printf("\nNormalized form of the expression:\n%s\n\n", s);
	
	// find all the distinct variables in our function	
	int size = StringLength(s);
	int num_vars = 0;
	for(int i = 0; i < size; i++){
		if(((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) && (vars[s[i]] == 0)){
			vars[s[i]] = 1;
			num_vars++;
		}
	}
	
	printf("The number of distinct variables in the logic expression is ->	%d\n\n", num_vars);
	
	// store all variable names consequently in the array with indexes starting at 0
	char final[10] = {0};
	int j = 0;
	for(int i = 0; i < 255; i++){
		if(vars[i] == 1){
			final[j] = (char)(i);
			j++;
			cout << final[j - 1] << "\n";
		}	
	}
	cout << "\n\n";
	
	// make all option blanks equal to our initial function
	int num_options = PowerOfX(2, num_vars);
	char options[num_options][size+1];
	for(int i = 0; i < num_options; i++){
		for(int j = 0; j < size; j++){
			options[i][j] = s[j];
		}
		options[i][size]='\0';
		cout << options[i] << "\n";
	}
	cout << "\n\n";
	for(int i = 0; i < num_options; i++){
		cout << options[i] << "\n";
	}
	cout << "\n\n";
	
	// first option is when all variable values equal to 0
	int k = 0;
	for(int l = 0; l < size; l++){
		if((options[k][l] >= 'a' && options[k][l] <= 'z') || (options[k][l] >= 'A' && options[k][l] <= 'Z')){
			options[k][l] = '0';
		}
	}
	cout << options[k] << "\n";
	k++;
	
	// generate all value options for our function
	bool isDif;
	for(int i = 0; i < num_options; i++){
		for(int j = 0; j < size; j++){
			options[k][j] = s[j];
		}
		isDif = false;
		for(int j = 0; j < num_vars; j++){
			int rez = i & PowerOfX(2, j);
			if(rez > 0){
				isDif = true;
				for(int l = 0; l < size; l++){
					if(options[k][l] == final[j]){
						options[k][l] = '1';
					}
				}
			}
		}
		
		for(int l = 0; l < size; l++){
			if((options[k][l] >= 'a' && options[k][l] <= 'z') || (options[k][l] >= 'A' && options[k][l] <= 'Z')){
				options[k][l] = '0';
			}
		}
		
		if(isDif == true){
			cout << options[k] << "\n";
			k++;
		}
	}
	cout << "\n\n";
	
	for(int i = 0; i < size + 9; i++)
		cout << "-";
	cout << "\n";
	
	for(int i = 0; i < num_vars; i++){
		cout << "|" << final[i];
	}
	cout << "|  rez |\n";
	
	for(int i = 0; i < size + 9; i++)
		cout << "-";
	cout << "\n";
	
	int minterms[1000] = {0}, maxterms[1000] = {0};
	int min_term = 0, max_term = 0;
	int pmin = 0, pmax = 0;
	for(int i = 0; i < num_options; i++){
		//printf("%s", options[i]);
		cout << "|" << options[i];
		
		char tmp[size+1];
		tmp[size] = 0;
		for(int j = 0; j < size; j++){
			tmp[j] = options[i][j];
		}
		int rez = calculate(tmp);
		cout << "|   " << rez << "  |\n";
		for(int i = 0; i < size + 9; i++)
		cout << "-";
	cout << "\n";
	}
	
	return 0;
}

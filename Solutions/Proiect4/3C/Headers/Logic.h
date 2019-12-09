int operationPriority[255] = {0};

char isInBrackets(char *s, int size);
int calculateInBrackets(char *s, int size);
char isAlgebraicFunction();
double calculateAlgebraicExpression();

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

char isAlgebraicFunction(char *s){
	if(s[0] == 's' && s[1] == 'q' && s[2] == 'r' && s[3] == 't'){
		return true;
	}
	if(s[0] == 's' && s[1] == 'i' && s[2] == 'n'){
		return true;
	}
	else if(s[0] == 'c' && s[1] == 'o' && s[2] == 's'){
		return true;
	}	
	else if(s[0] == 't' && s[1] == 'a' && s[2] == 'n'){
		return true;
	}
	else if(s[0] == 'c' && s[1] == 'o' && s[2] == 't'){
		return true;
	}
	else{
		return false;
	}
}

int calculateAlgebraicExpression(char *s){
	if(s[0] == 's' && s[1] == 'q' && s[2] == 'r' && s[3] == 't'){
		return sqrt(calculate(s + 4));
	}
	if(s[0] == 's' && s[1] == 'i' && s[2] == 'n'){
		return sin(calculate(s + 3));
	}
	else if(s[0] == 'c' && s[1] == 'o' && s[2] == 's'){
		return cos(calculate(s + 3));
	}	
	else if(s[0] == 't' && s[1] == 'a' && s[2] == 'n'){
		return tan(calculate(s + 3));
	}
	else if(s[0] == 'c' && s[1] == 'o' && s[2] == 't'){
		return cot(calculate(s + 3));
	}
}

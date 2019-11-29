#include <iostream>

struct Envelope{
	int money;
	struct Envelope *previous;	
};
struct Envelope *top;

int isEmpty(){
	return top == 0;
}

void push(int val){
	struct Envelope *temp;
	temp = new Envelope();
	temp -> money = val;
	temp -> previous = top;
	top = temp;
}

void pop(){
	if(top == 0){
		printf("Stack is already empty!\n");
		exit(1);
	}

	struct Envelope *temp;
	temp = top;
	top = top -> previous;
	temp -> previous = 0;
	free(temp);
}

int main(){
	freopen("input.txt", "r", stdin);
	int n, s, i, sum = 0, envelopes = 0, val;
	
	scanf("%d %d", &n, &s);
	
	for(i = 0; i < n; i++){
		scanf("%d", &val);
		push(val);
	}
	
	while(sum < s && !isEmpty()){
		sum += top -> money;
		envelopes++;
		pop();
	}
	if(sum < s && isEmpty())
		printf("No money");
	else
		printf("Number of envelopes used to collect money required: %d\nMoney collected %d", envelopes, sum);
	
	return 0;
}



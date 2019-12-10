#include <stdio.h>
#include <stdlib.h>

struct Node{
	int val;
	struct Node *previous;
	struct Node *left, *right;
}Instance, *root, *temp;

int isEmpty(){
	return root == 0;
}

void push(int val){
	struct Node *node;
	node = malloc(sizeof(Instance));
	node -> val = val;
	node -> previous = temp;
	
	if(node -> previous -> val < val){
		node -> previous -> left = node;
	}
	else{
		node -> previous -> right = node;
	}
	
	temp = node;
}

void pop(){
	if(root == 0){
		printf("Binary Search Tree is already empty!\n");
		exit(1);
	}

	struct Node *temp;
	temp = root;
	root = root -> previous;
	temp -> previous = 0;
	free(temp);
}

int main(){
	freopen("input.txt", "r", stdin);
	
	int x;

	printf("Enter the root value: ");
	scanf("%d", &x);

	root = malloc(sizeof(Instance));
	root -> previous = 0;
	root -> left = root -> right = 0;
	root -> val = x;
	
	printf("%d %d %d %d\n", root->val, root->previous, root->left, root->right);
	
	temp = root;
	
	int flag = 1;
	while(flag == 1){
		printf("What do you want to do:\n");
		printf("1)Add a new node\n");
		printf("2)Remove a new node\n");
		printf("3)Search for a node with specific value\n");
		printf("4)Inorder traverse\n");
		printf("5)Preorder traverse\n");
		printf("6)Postorder traverse\n");
		printf("7)Exit the program\n");
		
		int option;
		scanf("%d", &option);
		
		int val;
		switch(option){
			case 1 : scanf("%d", val); push(val); 
			case 7 : flag = 0;
		}
	}
	
	free(root);
	
	return 0;
}

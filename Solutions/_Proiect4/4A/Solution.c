#include <stdio.h>
#include <stdlib.h>

struct Node{
	int val;
	struct Node *left, *right;
}*root;

int size;

struct Node* findNode(struct Node *node, int val){
	if(node == NULL || node->val == val)
		return node;
	
	if(node->val > val)
		return findNode(node->left, val);
	
	return findNode(node->right, val);
}

struct Node* createNode(int val){
	struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
	temp->val = val;
	temp->left = temp->right = NULL;
	size++;
	return temp;
}

struct Node* insertNode(struct Node *node, int val){
	if(node == NULL)
		return createNode(val);
	
	if(val < node->val)
		node->left = insertNode(node->left, val);
	
	else if(val > node->val)
		node->right = insertNode(node->right, val);
	
	return node;
}

void inorderTraversal(struct Node *node){
	if(node != NULL){
		inorderTraversal(node->left);
		printf("%d ", node->val);
		inorderTraversal(node->right);
	}
}

struct Node* findSmallest(struct Node *node){
	struct Node* temp = node;
	
	while(node != NULL && temp->left != NULL)
		temp = temp->left;
		
	return temp;
}

struct Node* deleteNode(struct Node *node, int val){
	if(node == NULL)
		return node;
	
	if(val < node->val)
		node->left = deleteNode(node->left, val);
	else if(val > node->val)
		node->right = deleteNode(node->right, val);
	else{
		if(node->left == NULL){
			struct Node *temp = node->right;
			free(node);
			size--;
			return temp;
		}
		else if(node->right == NULL){
			struct Node *temp = node->left;
			free(node);
			size--;
			return temp;
		}
		
		struct Node *temp = findSmallest(node->right);
		node->val = temp->val;
		node->right = deleteNode(node->right, temp->val);
	}
	return node;
}

int main(){
	//freopen("input.txt", "r", stdin);
	
	int val;

	printf("Enter the root value: ");
	scanf("%d", &val);
	
	root = NULL;
	root = insertNode(root, val);
	
	printf("What do you want to do with the current BST(press the corresponding digit):\n");
		printf("1) Add new node\n");
		printf("2) Remove node\n");
		printf("3) Search for a node with specific value\n");
		printf("4) Output the inorder traversal\n");
		printf("5) Output the size of BST:\n");
		printf("6) Exit the program\n");
	
	int flag = 1;
	while(flag == 1){
		printf("What do you want to do with the current BST(press the corresponding digit):\n");
		
		int option;
		scanf("%d", &option);
		
		switch(option){
			case 1: 
				printf("\n->Enter the value of the new node: ");
				scanf("%d", &val); 
				insertNode(root, val); 
			break;
				
			case 2:
				printf("\n->Enter the value of the node to be deleted: ");
				scanf("%d", &val); 
				deleteNode(root, val); 
			break;
			
			case 3:
				printf("\n->Enter the value of the node to be found: ");
				scanf("%d", &val);
				if(findNode(root, val) == NULL)
					printf("->No such node found!\n");
				else
					printf("->The node is in the BST on its right place!\n");
			break;
			
			case 4:
				printf("\n->Inorder traversal of the BST:\n");
				inorderTraversal(root);
				printf("\n");
			break;
			
			case 5:
				printf("\n->The size of the BST is: %d\n", size);
			break;
			
			default:
				flag = 0;
				printf("\n->Press any key to close the program.");
		}
		option = -1;
		printf("\n");
	}
	
	free(root);
	
	return 0;
}

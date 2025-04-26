// binary search tree--- arranges the given values in a sequentil order wrt to root

#include<stdio.h>
#include <stdlib.h>
struct BinaryTree{
	int val;
	struct BinaryTree* left;
	struct BinaryTree* right;
};
typedef struct BinaryTree Node;
Node* CreateANode(int val){
	Node*newnode = (Node*)malloc(sizeof(Node));
	newnode->val=val;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}
Node *insert(int val,Node* root){
	//base case
	if(root==NULL) {
		return CreateANode(val);
	}
	// if val<root->data
	if(val<root->val){
		root->left=insert(val,root->left);
	}
	// if val >root->data
	else if(val>root->val){
		root->right=insert(val,root->right);
	}
	return root;
}
void inorder(Node* root){
	if(root == NULL) return;
	inorder(root->left);
	printf("%d ",root->val);
	inorder(root->right);
}
int main(){
	int n;
	scanf("%d",&n);
	// here n is no of terms
	Node* root =NULL;
	int val;
	scanf("%d",&val);
	//to get intial value to root
	root=insert(val,root);
	int i;
	for(i = 1;i<n;i++){
//		int val;
//     for remaining values we use this scanf statement
		scanf("%d",&val);
		insert(val,root);
	}
	//to print the elments we are using the inorder way
	inorder(root);
	
}

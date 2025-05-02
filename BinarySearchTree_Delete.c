//deletion of the node in a binary search tree
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
Node *FindMin(Node* root){
	if(root== NULL){
        return NULL;
    }
    if(root->left != NULL) return FindMin(root->left);
    return root;
}
Node *delete(Node* root,int val){
	if(root==NULL){
		return NULL;
	}
	else if(val<root->val){
		root->left=delete(root->left,val);// recrusive call
	}
	else if(val>root->val){
		root->right=delete(root->right,val);//recrusive call
	}
	else{
		// having the atleast 2 children
		//1)having no children
		if(root->left==NULL && root->right==NULL){
			free(root);
			return NULL;			
		}
		// one children
		else if(root->left==NULL || root->right ==NULL){//either left node may be null or right node may be null
			Node *temp=NULL;//creating a temporary node 
			if(root->left==NULL){
				temp = root->right;//stores the right node
				free(root);
			}
			else{
				temp =root->left;//stores the left node
				free(root);//free means deleted
			}
			return temp;
		}
		//3)having the two children
		else{
			Node *temp = FindMin(root->right); 
			root->val = temp ->val;
			root->right=delete(root->right,temp->val);
		}
	}
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
	scanf("%d",&val);
	delete(root,val);
	//to print the elments we are using the inorder way
	inorder(root);
	
}

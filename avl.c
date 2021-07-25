#include<stdio.h>
struct node{
	int data;
	struct node* left;
	struct node* right;
	int h;
};
int max(int a,int b);
int height(struct node* n){
	if(n==NULL)
	return 0;
	return n->h;
}
int max(int a,int b){
	return (a>b)?a:b;
}
struct node* createnode(int x){
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=x;
	newnode->left=NULL;
	newnode->right=NULL;
	newnode->h=1;
	return newnode;
}
struct node* rightrot(struct node* y){
	struct node* x=y->left;
	struct node* t2=x->right;

	x->right=y;
	y->left=t2;

	y->h=max(height(y->left),height(y->right))+1;
	x->h=max(height(x->left),height(x->right))+1;

	return x;
}
struct node* leftrot(struct node* x){
	struct node* y=x->right;
	struct node* t2=y->left;

	
	y->left=x;
	x->right=t2;

	x->h=max(height(x->left),height(x->right))+1;
	y->h=max(height(y->left),height(y->right))+1;
	
	return y;
}
int balance(struct node* n){
	if(n==NULL)
	return 0;
	return height(n->left)-height(n->right);
}
struct node* insert(struct node* root,int x){
if(root==NULL)
return(createnode(x));
if(x < root->data)
root->left=insert(root->left,x);
else if(x > root->data)
root->right=insert(root->right,x);
else
return root;
root->h=1+max(height(root->left),height(root->right));

int b=balance(root);

if(b>1 && x < root->left->data)
return rightrot(root);

if(b<-1 && x > root->right->data)
return leftrot(root);

if(b>1 && x > root->left->data)
{
	root->left=leftrot(root->left);
	return rightrot(root);
}

if(b<-1 && x < root->right->data)
{
	root->right=rightrot(root->right);
	return leftrot(root);
}
return root;
}
void preorder(struct node* root){
if(root==NULL)
return;
printf("%d ",root->data);
preorder(root->left);
preorder(root->right);
}
void inorder(struct node* root){
if(root==NULL)
return;
inorder(root->left);
printf("%d ",root->data);
inorder(root->right);
}
void postorder(struct node* root){
	if(root==NULL)
return;
postorder(root->left);
postorder(root->right);
printf("%d ",root->data);
}
int main(){
int n,k;
struct node* root=NULL;
scanf("%d",&n);
while(n--){
	scanf("%d",&k);
	root=insert(root,k);
}
inorder(root);
printf("\n");
preorder(root);
printf("\n");
postorder(root);
}

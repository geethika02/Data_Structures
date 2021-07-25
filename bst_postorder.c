#include<stdio.h>
struct node{
	int data;
	struct node* left;
	struct node* right;
};
struct node* newnode(int x){
	struct node* t=(struct node*)malloc(sizeof(struct node));
	t->data=x;
	t->left=NULL;
	t->right=NULL;
	return t;
}
struct node* insert(struct node* root,int x){
if(root==NULL)
return newnode(x);
else if(x<root->data)
root->left=insert(root->left,x);
else if(x>root->data)
root->right=insert(root->right,x);

return root;

}
void postorder(struct node* root){
if(root==NULL)
return;
postorder(root->left);
postorder(root->right);
printf("%d ",root->data);
}
int main(){
	struct node* root=NULL;
int u;
while(scanf("%d",&u)!=(EOF)){
	root=insert(root,u);
}
postorder(root);
}

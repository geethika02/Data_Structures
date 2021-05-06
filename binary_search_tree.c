//finding height and insertion
#include <stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left,*right;
};
struct node* newnode(int k)
{
	struct node* t=(struct node*)malloc(sizeof(struct node));
	t->data=k;
	t->left=NULL;
	t->right=NULL;
	return t;
}
struct node* insert(struct node* root,int k)
{    
	if(root==NULL)
	return newnode(k);

	else if(k < root->data)
	root->left = insert(root->left,k);
	else if(k > root->data)
    root->right = insert(root->right,k);

	return root;

}
int height(struct node* root)
{
	if(root==NULL)
	return 0;
	else{
		int l=height(root->left);
		int r=height(root->right);
		if(l>r)
		return l+1;
		else
		return r+1;
	}
}
int main(){
	int t,n,p;
	scanf("%d",&t);
	struct node* root=NULL;
	while(t--){
		scanf("%d",&n);
		if(n==0)
		{
			scanf("%d",&p);
			root=insert(root,p);
		}
		if(n==1)
		{
			int h=height(root);
			if(h>0)
			printf("%d\n",h);
			else
			printf("-1\n");
		}

	}
}

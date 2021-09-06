#include <stdio.h>
void insert(int a[],int x,int s){
for(int i=0;i<s;i++)
{
int q=(x+i)%s;
if(a[q]==-1)
{
	a[q]=x;
	break;
}
}
}
void del(int a[],int y,int s){
int b[s];
for(int i=0;i<s;i++)
{
int q=(y+i)%s;
if(a[q]==y)
{
	a[q]=-1;
	break;
}
}
int j=0;
for(int i=0;i<s;i++)
{
	if(a[i]!=-1)
	{
		b[j++]=a[i];
		a[i]=-1;
	}
}
for(int i=0;i<j;i++)
insert(a,b[i],s);
}
int main(){
	int s,t;
	scanf("%d", &s);
	int a[s];
	for(int i=0;i<s;i++)
	a[i]=-1; 
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		if(n==1)
		{	int x;
			scanf("%d",&x);
			insert(a,x,s);
		}
		if(n==2)
		{
			int y;
			scanf("%d",&y);
			del(a,y,s);
		}
		if(n==3)
		{
			for(int i=0;i<s;i++)
			printf("%d ",a[i]);

			printf("\n");
		}
	}
}             	

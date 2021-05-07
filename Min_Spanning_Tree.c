#include <stdio.h>
#define t 100
#define infinity 100000
int value[t];
int visited[t];
int parent[t];
int graph[t][t];
int min(int n)
{
	int i,mini=infinity,vertex;
	for(i=0;i<n;i++)
	{
		if(visited[i]==0 && value[i]<=mini)
		{
			vertex=i;
			mini=value[i];
             
		}
	}
return vertex;
}
int mst(int n)
{
	int i,j,sum=0;
	for(i=0;i<n;i++)
	{
		value[i]=infinity;
		visited[i]=0;
		parent[i]=-1;
	}
	value[0]=0;
	for(i=0;i<n-1;i++)
	{
       int u=min(n);
	   visited[u]=1;

	   for(j=0;j<n;j++)
	   {
		   if(graph[u][j]!=0 && visited[j]==0 && value[j]>graph[u][j])
		   {
			   value[j]=graph[u][j];
			   parent[j]=u;
		   }
	   }
	}
	for(i=0;i<n;i++)
	{
      sum=sum+value[i];
	}
	return sum;
}
int main(){
	int n,e,x,y,w,i,j;
	scanf("%d",&n);
	scanf("%d",&e);
	while(e--)
	{
		scanf("%d",&x);
		scanf("%d",&y);
		scanf("%d",&w);
		graph[x][y]=w;
		graph[y][x]=w;
	}
	int h=mst(n);
	printf("%d",h);
}

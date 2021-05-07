#include <stdio.h>
#define t 100
#define infinity 100000
int parent[t];
int value[t];
int visited[t];
int mat[t][t];
int min(int n)
{
int vertex,i,mini=infinity;
for(i=0;i<n;i++)
{
	if(visited[i]==0 && value[i]<=mini)
	{
        mini=value[i];
		   vertex=i;
	}
}
return vertex;
}
void dij(int n)
{
	int q,s,d,i,j;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&s);
		scanf("%d",&d);
		for(i=0;i<n;i++)
		{
			value[i]=infinity;
			parent[i]=-1;
			visited[i]=0;
		}
		value[s]=0;
		int y=s;
		while(y!=d)
		{
			y=min(n);
			visited[y]=1;

			for(j=0;j<n;j++)
			{
				if(visited[j]==0 && mat[y][j]!=0 && value[y]+mat[y][j]<value[j])
				{
					parent[j]=y;
					value[j]=value[y]+mat[y][j];
				}
			}
		}
		printf("%d\n",value[d]);
	}
}
int main(){
	int n,q,u,v;
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&mat[i][j]);
		}
	}
dij(n);
}
	

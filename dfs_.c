#include<stdio.h>
#include<limits.h>
int g[1001][1001]={0};
int dfs(int v,int l,int visit[],int* level)
{
    int i;
    visit[v]=1;
    level[v]=l;
    for(i=0;i<1001;i++)
    {
        if(visit[i]==0 && g[v][i]==1)
        {
            dfs(i,l+1,visit,level);
        }
    }
}
int main(){
int n,i;
scanf("%d",&n);
for(i=0;i<n-1;i++)
{
    int a,b;
    scanf("%d %d",&a,&b);
    g[a][b]=1;
}
int visit[1001]={0};
int level[1001]={-1};
dfs(1,0,visit,level);
int q;
scanf("%d",&q);
int m=INT_MAX,index=INT_MAX;
while(q--){
    int r;
    scanf("%d",&r);
    if(level[r]<=m && r<index){
        m=level[r];
        index=r;
    }

}
printf("%d\n",index);
}

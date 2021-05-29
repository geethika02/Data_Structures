#include <stdio.h>
#include<stdlib.h>
struct node
{
    int vertex;
    struct node* next;
};
struct graph
{
    int vertices;
    int *visited;
    struct node **adjlist;
};
void dfs(struct graph* g,int vertex)
{
    struct node* adj=g->adjlist[vertex];
    struct node* temp=adj;
    g->visited[vertex]=1;
    printf("%d ",vertex);
    
    while(temp!=NULL)
    {
        int connectedvertex=temp->vertex;
        if(g->visited[connectedvertex]==0)
        {
            dfs(g,connectedvertex);
        }
        temp=temp->next;
    }
}
struct node* createvertex(int e){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->vertex=e;
    newnode->next=NULL;
    return newnode;
}
struct graph* creategraph(int v){
    struct graph* ng=(struct graph*)malloc(sizeof(struct graph));   
    ng->vertices=v;
    ng->visited=(int *)malloc(v*sizeof(int));
    ng->adjlist=(struct node*)malloc(v*sizeof(struct node));
    for(int i=0;i<v;i++)
    {
        ng->adjlist[i]=NULL;
        ng->visited[i]=0;
    }
    return ng;
}
void addedge(struct graph* g,int src,int dest){
    struct node* n=createvertex(dest);
    n->next=g->adjlist[src];
    g->adjlist[src]=n;//from source to dest
    
    struct node* nn=createvertex(src);
    nn->next=g->adjlist[dest];
    g->adjlist[dest]=nn;//from dest to source
}
void print(struct graph* g)
{
 for(int i=0;i<g->vertices;i++)
 {
     printf("%d -> ",i);
    struct node* temp=g->adjlist[i];
    while(temp!=NULL)
    {
        printf("%d ",temp->vertex);
        temp=temp->next;
    }
    printf("\n");
 }
}
int main()
{
   struct graph* g=creategraph(4);
   addedge(g,0,1);
   addedge(g,0,2);
   addedge(g,1,2);
   addedge(g,2,3);
   print(g);
   printf("Visited vertices are:\n");
   dfs(g,2);
}

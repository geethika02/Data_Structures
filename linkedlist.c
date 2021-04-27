//single linked list
#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next; 
}*head;
void beg(int x){
  struct node* newnode=(struct node*)malloc(sizeof(struct node));
  newnode->data=x;
  newnode->next=head;
  head=newnode;
}
void pos(int x,int p)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    if(p==1)
    beg(x);
    else{
        newnode->data=x;
     struct node* temp=head;
     for(int i=2;i<p;i++)
     {
         temp=temp->next;
     }
    newnode->next=temp->next;
    temp->next=newnode;
    }
    }
void end(int x)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    struct node* temp=head;
    newnode->data=x;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
       temp->next=newnode;
        newnode->next=NULL;
}
void delbeg()
{
    struct node* temp=head;
    head=temp->next;
    free(temp);
}
void delpos(int p)
{
    struct node* temp=head;
    if(p==1)
    delbeg();
    else{
        for(int i=2;i<p;i++)
        {
         temp=temp->next;   
        }
       struct node* temp1=temp->next;
       temp->next=temp1->next;
       free(temp1);
    }
}
void delend()
{
    struct node* temp=head;
    while((temp->next)->next !=NULL)
    {
        temp=temp->next;
    }
    struct node* temp1=temp->next;
    temp->next=NULL;
    free(temp1);
}
void print()
{   
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main()
{
    head=NULL;
    int n,x; 
   beg(2);
   beg(3);
   beg(4);
   pos(5,2);
   end(8);
    print();
    delbeg();
    print();
    delpos(2);
    print();
    delend();
    print();
}

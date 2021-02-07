#include <stdio.h> 
int linearsearch(int a[], int n, int key) 
{ 
	for(int i=0;i<n;i++) 
		{
		    if (a[i]==key) 
		       return i; 
           }
	     return -1; 
} 
int main() 
{ 
	int n,key,k,i;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    scanf("%d",&key);
	k=linearsearch(a, n, key); 
	if(k==-1)
        printf("Element is not found");
    else
        printf("Element is found");
	return 0; 
}







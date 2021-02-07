#include<stdio.h>
void mergesort(int a[],int low,int high)
{
       if(low<high)
           {
                  int m=low+(high-low)/2;
                  mergesort(a,low,m);
                  mergesort(a,m+1,high);
                  merge(a,low,m,high);
             }
}
void merge(int a[],int low,int m,int high)
{
int i,j,k,n1,n2;
n1=m-low+1;
n2=high-m;
int l[n1],r[n2];
for(i=0;i<n1;i++)
      l[i]=a[low+i];
for(j=0;j<n2;j++)
      r[j]=a[m+1+j];
i=0;j=0;k=low;
while(i<n1 && j<n2)
{
         if(l[i]<=r[j])
               {
                      a[k]=l[i];
                      i++;
                }
          else
               {
                      a[k]=r[j];
                      j++;
                }
         k++;
}
while(i<n1)
{
       a[k]=l[i];
       i++;
       k++;
}
while(j<n2)
{
        a[k]=r[j];
        j++;
        k++;
}
}
int main()
{
       int n,i;
       scanf("%d",&n);
       int a[n];
       for(i=0;i<n;i++)
       scanf("%d",&a[i]);
       mergesort(a,0,n-1);
       printf("Sorted order is: ");
       for(i=0;i<n;i++)
       printf("%d ",a[i]);
}
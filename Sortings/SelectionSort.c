#include<stdio.h>
void selectionsort(int a[],int n)
{
      int i,j,min;
      for(i=0;i<n;i++)
          {    min=i;
                for(j=i+1;j<n;j++)
                   {
                         if(a[min]>a[j])
                           {
                                min=j;
                             }
                   }
                 if(min!=i)
                    {  
                                int t;
                                 t=a[min];
                                 a[min]=a[i];
                                 a[i]=t;
                      }
            }
}
int main()
{
       int n,i;
       scanf("%d",&n);
       int a[n];
       for(i=0;i<n;i++)
       scanf("%d",&a[i]);
       selectionsort(a,n);
       printf("Sorted order is: ");
       for(i=0;i<n;i++)
       printf("%d ",a[i]);
}
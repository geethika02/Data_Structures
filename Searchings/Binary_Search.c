#include <stdio.h> 

int binarysearch(int a[], int low, int high, int key)
 
{ 
    
        int flag=0;
   
        while(high>=low) 
         { 

                 int mid=(low+high)/2; 

                 if(a[mid]==key) 
                 {
                    flag=1;
		
                    break;
	
	}
	
	else if(a[mid]>key)
	
	{
		
                     high=mid-1;
	
	}
		
                  else
		
                      low=mid+1;
    
        }
 
     if(flag==1)
    
              printf("Element is found");

     else
   
             printf("Element is not found");
 
   } 
 

int main()

{
     
      int n,key,i;
  
      scanf("%d",&n);
 
      int a[n];
    
      for(i=0;i<n;i++)
   
      scanf("%d",&a[i]);
   
      scanf("%d",&key);
 
      binarysearch(a,0,n-1,key);

}
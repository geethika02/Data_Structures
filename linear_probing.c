#include <stdio.h>
void insert(long long int a[],long long int e,long long int n)
{
long long int l=e%n;
while(a[l]!=-1 && l<n)
{
	l++;
}
a[l]=e;
}
void delete(long long int a[],long long int d,long long int n){
	int i;
for(i=0;i<n;i++)
{
	if(a[i]==d){
	a[i]=-1;
	break;
	}
}
}
void print(long long int a[],long long int n)
{long long int i;
for(i=0;i<n;i++)
printf("%d ",a[i]);
}
int main(){
	long long int n,t,m,e,d,i;
	scanf("%d",&n);
	long long int a[n];
	for(i=0;i<n;i++)
	a[i]=-1;
	scanf("%d",&t);
	while(t--){
	scanf("%d",&m);
	if(m==1)
	{
		scanf("%d",&e);
		insert(a,e,n);
	}
	else if(m==2)
	{
		scanf("%d",&d);
		delete(a,d,n);
	}	
	else if(m==3)
	{
		print(a,n);
		printf("\n");
	}
	}

}

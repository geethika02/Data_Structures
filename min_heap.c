#include<stdio.h>
int c=0;
void swap(int *a,int *b){
    int t=*b;
    *b=*a;
    *a=t;
}
void heapify(int a[],int c,int i){
    int smallest=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<c && a[l]<a[smallest])
    smallest=l;

    if(r<c && a[r]<a[smallest])
    smallest=r;

    if(smallest!=i){
        swap(&a[i],&a[smallest]);
        heapify(a,c,smallest);
    }


}
void insert(int a[],int r){
    if(c==0)
    {
        a[0]=r;
        c++;
    }
    else{
        a[c]=r;
        c++;
        for(int i=c/2-1;i>=0;i--){
            heapify(a,c,i);
        }
    }
}
void deleted(int a[]){
    swap(&a[0],&a[c-1]);
    c=c-1;
    for(int i=c/2-1;i>=0;i--){
            heapify(a,c,i);
        }
}
int main(){
	int q;
    scanf("%d",&q);
  int a[100];
    while(q--){
        int n;
        scanf("%d",&n);
        if(n==1){
            int b;
            scanf("%d",&b);
            insert(a,b);
        }
        if(n==2)
        {
            deleted(a);   
        }    
         if(n==3)
        {
            printf("%d\n",c);
        }
       if(n==4)
        {
            printf("%d\n",a[0]);
        }

    }
}

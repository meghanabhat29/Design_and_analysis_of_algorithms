#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int h[50];
void heapify(int h[],int n)
{
    int heap,i,j,k,v;
    for(i=n/2;i>=1;i--)
    {
       k=i;
       v=h[k];
       heap=0;
       while(!heap && (2*k)<=n)
       {
           j=2*k;
           if(j<n)
           {
               if(h[j]<h[j+1])
               {
                   j=j+1;
               }
           }
           if(v>=h[j])
           {
               heap=1;
           }
           else
           {
               h[k]=h[j];
               k=j;
           }
       }
       h[k]=v;
    }
}
void main()
{
    int i,j,temp,n,size;
    clock_t start,end;
    double total;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    printf("Enter the elements : ");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&h[i]);
    }
    start=clock();
    heapify(h,n);
    printf("Elements heapified :\n");
    for(i=1;i<=n;i++)
        printf("%d\t",h[i]);
    for(i=n;i>=1;i--)
    {
        temp=h[1];
        h[1]=h[i];
        h[i]=temp;
        size=i-1;
        heapify(h,size);
    }
    printf("\nElements sorted : \n");
    for(i=1;i<=n;i++)
    {
        printf("%d\t",h[i]);
    }
    end=clock();
    total=(double)(end-start)/CLOCKS_PER_SEC;
    printf("\nThe total time taken = %lf seconds");
}

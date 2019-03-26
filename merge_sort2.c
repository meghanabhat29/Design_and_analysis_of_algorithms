//This program displays the time taken to merge sort elements in an array
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void merge(int a[],int low,int mid,int high)
{
    int i=low,j=mid+1,k=0;
    int c[low+high];
    while(i<=mid && j<=high)
    {
        if(a[i]<=a[j])
        {
            c[k++]=a[i++];
        }
        else
        {
            c[k++]=a[j++];
        }
    }
    while(i<=mid)
    {
        c[k++]=a[i++];
    }
    while(j<=high)
    {
        c[k++]=a[j++];
    }
    k=0;
    for(i=low;i<=high;i++)
    {
        a[i]=c[k++];
    }
}
void mergesort(int a[],int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}
void main()
{
    int n,i,n1,n2;
    clock_t start,end;
    double total;
    printf("Enter the range  : ");
    scanf("%d %d",&n1,&n2);
    for(n=n1;n<=n2;n+=100)
    {
        int a[n];
        for(i=0;i<n;i++)
        {
            a[i]=rand();
        }
    
    start=clock();
    mergesort(a,0,n-1);
    end=clock();
    
    total=(double)(end-start)/CLOCKS_PER_SEC;
    printf("%d : %lf seconds\n",n,total);
    }
}

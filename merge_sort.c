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
    int n,i;
    clock_t start,end;
    double total;
    printf("Enter the size of the array : ")
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    start=clock();
    mergesort(a,0,n-1);
    end=clock();
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    total=(double)(end-start)/CLOCKS_PER_SEC;
    printf("Time taken = %lf seconds\n",total);
}

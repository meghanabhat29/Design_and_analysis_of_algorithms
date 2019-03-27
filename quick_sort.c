#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int partition(int a[],int low,int high)
{
    int i,j,temp,pivot;
    i=low+1;
    j=high;
    pivot=low;
    while(1)
    {
        while(i<high && a[pivot]>=a[i])
        {
            i++;
        }
        while(j>low && a[pivot]<a[j])
        {
            j--;
        }
        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
        else
        {
            temp=a[low];
            a[low]=a[j];
            a[j]=temp;
            return j;
        }
    }
}
void quicksort(int a[],int low,int high)
{
    int pos;
    if(low<high)
    {
        pos=partition(a,low,high);
        quicksort(a,low,pos-1);
        quicksort(a,pos+1,high);
    }
}
void main()
{
    int n,i;
    clock_t start,end;
    double total;
    printf("Enter the size : ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    start=clock();
    quicksort(a,0,n-1);
    end=clock();
    total=(double)(end-start)/CLOCKS_PER_SEC;
    printf("The sorted array is : ");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n Time taken = %lf seconds",total);
}

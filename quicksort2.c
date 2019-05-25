#include<stdio.h>
#include<stdlib.h>
int partition(int a[],int low,int high)
{
    int i,j,p,temp;
    i=low;
    j=high;
    p=low;
    while(i<j)
    {
        while(a[i]<=a[p] && i<high)
        {
            i++;
        }
        while(a[j]>a[p] && j>low)
        {
            j--;
        }
        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    temp=a[j];
    a[j]=a[p];
    a[p]=temp;
    return j;
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
    printf("Enter size:");
    scanf("%d",&n);
    int a[n];
    printf("Enter elements : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    quicksort(a,0,n-1);
    printf("\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}

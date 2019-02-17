#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main()
{
    int n,i,j,temp,min;
    clock_t start,end;
    double total;
    printf("Enter the size of the array : ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    start=clock();
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
            {
                min=j;
            }
        }
        temp=a[i];
        a[i]=a[min];
        a[min]=temp;
    }
    end=clock();
    total=(double)(end-start)/CLOCKS_PER_SEC;
    printf("The sorted array is : ");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
    printf("\n%d : %lf seconds",n,total);
    
}

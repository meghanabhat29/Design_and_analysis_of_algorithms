#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main()
{
    int n,i,j,temp;
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
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    end=clock();
    total=(double)(end-start)/CLOCKS_PER_SEC;
    printf("The sorted array is : ");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
    printf("\n%d : %lf seconds",n,total);
    
}

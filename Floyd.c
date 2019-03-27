#include<stdio.h>
#include<stdlib.h>
int min(int a,int b)
{
    if(a<b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
void main()
{
    int i,j,k,n;
    printf("Enter the size of the matrix : ");
    scanf("%d",&n);
    int a[n][n];
    printf("nter the elements : ");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
            }
        }
    }
    printf("The shortest path of all pairs:\n ");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}

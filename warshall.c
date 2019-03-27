#include<stdio.h>
#include<stdlib.h>
void main()
{
    int n,i,j,k;
    printf("Enter the size of the square matrix : ");
    scanf("%d",&n);
    int a[n][n];
    printf("Enter the elements : ");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            for(k=0;k<n;k++)
            {
                if(a[i][k]==1 || a[i][k]==1&&a[k][j]==1)
                {
                    a[i][j]=1;
                }
            }
        }
    }
    printf("Output : \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}

#include<stdio.h>
#include<stdlib.h>
int max(int a, int b)
{
    if(a>b)
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
    int w[100],v[100],m[100][100],n,cap,i,j;
    printf("Enter the size of the list : ");
    scanf("%d",&n);
    v[0]=0;
    w[0]=0;
    printf("\nEnter the weight of each item : ");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&w[i]);
    }
    printf("\nNow enter the value of each item: ");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&v[i]);
    }
    printf("Enter the maximum capacity : ");
    scanf("%d",&cap);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=cap;j++)
        {
            if(j-w[i]>=0)
            {
                m[i][j]=max(m[i-1][j],(m[i-1][j-w[i]]+v[i]));
            }
            else
            {
                m[i][j]=m[i-1][j];
            }
        }
    }
    printf("The maximum value is : %d\n",m[n][cap]);
    printf("The knapsack table :\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=cap;j++)
        {
            printf("%d\t",m[i][j]);
        }
        printf("\n");
    }
    j=cap;
    int x[100];
    for(i=0;i<n;i++)
    {
        x[i]=0;
    }
    for(i=n;i>=1;i--)
    {
        if(m[i][j]!=m[i-1][j])
        {
            x[i]=1;
            j=j-w[i];
        }
    }
    printf("Item set : ");
    for(i=1;i<=n;i++)
    {
        if(x[i]==1)
        {
            printf(" Item %d\t",i);
        }
    }
     
}

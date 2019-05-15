#include<stdio.h>
int ne=1,min_cost;
void main()
{
    int n,a,b,min,i,j,source,visited[20],cost[20][20];
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    printf("Enter the cost matrix : \n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);
        }
    }
    for(i=1;i<=n;i++)
    {
        visited[i]=0;
    }
    printf("Enter the source node: "); 
    scanf("%d",&source);
    visited[source]=1;
    printf("The minimum spanning tree: \n");
    while(ne<n)
    {
        min=999;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(cost[i][j]<min)
                {
                    if(visited[i]==0)
                    {
                        continue;
                    }
                    else
                    {
                        min=cost[i][j];
                        a=i;
                        b=j;
                    }
                }
            }
        }
       if(visited[a]==0||visited[b]==0)
       {
            printf("\nEdge %d\t(%d-->%d)=%d \n",ne++,a,b,min);
            min_cost=min_cost+min;
            visited[b]=1;
       }
        
        cost[a][b]=cost[b][a]=999;
    }
    printf("The minimum cost=%d\n",min_cost);
    
}

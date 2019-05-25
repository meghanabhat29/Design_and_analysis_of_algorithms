#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int table[200];
void shifttable(char p[])
{
    int m=strlen(p);
    int i,j;
    for(i=0;i<200;i++)
    {
        table[i]=m;
    }
    for(j=0;j<=m-2;j++)
    {
        table[p[j]]=m-j-1;
    }
    
}
int horspool(char p[],char t[])
{
    int i,j,k,m,n;
    shifttable(p);
    m=strlen(p);
    n=strlen(t);
    i=m-1;
    while(i<=n-1)
    {
        k=0;
        while(k<=m-1 && p[m-1-k]==t[i-k])
        {
            k=k+1;
        }
        if(k==m)
        {
            return i-m+1;
        }
        else
        {
            i=i+table[t[i]];
        }
    }
    return -1;
}
void main()
{
    char p[25],t[25];
    int index;
    printf("Enter the text : ");
    scanf("%s",t);
    printf("Enter the pattern : ");
    scanf("%s",p);
    index=horspool(p,t);
    if(index!=-1)
    {
        printf("\nThe pattern is found at position %d",index+1);
    }
    else
    {
        printf("The pattern is not found.\n");
    }
    
}

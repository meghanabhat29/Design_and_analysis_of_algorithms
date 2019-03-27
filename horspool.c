#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int table[200];
void shifttable(char p[])
{
    int i,m,j;
    m=strlen(p);
    for(i=0;i<200;i++)
    {
        table[i]=m;
    }
    for(j=0;j<m-1;j++)
    {
        table[p[j]]=m-1-j;
    }
}
int horspool(char t[],char p[])
{
    int n=strlen(t);
    int m=strlen(p);
    shifttable(p);
    int i=m-1,k;
    while(i<n)
    {
        while(k<m && t[i-k]==p[m-1-k])
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
    char t[100],p[100];
    printf("Enter the text : ");
    scanf("%s",t);
    printf("Enter the pattern : ");
    scanf("%s",p);
    int r;
    r=horspool(t,p);
    if(r==-1)
    printf("the pattern is not found\n");
    else
    {
        printf("The pattern is found at position %d",r+1);
    }
}

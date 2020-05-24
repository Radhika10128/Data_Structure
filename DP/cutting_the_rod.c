#include<stdio.h>
int main()
{
    int m,n;
    scanf("%d %d",&m,&n);
    int len[m],price[n];
    for(int i=0;i<m;i++)
    scanf("%d",&len[i]);
     for(int i=0;i<n;i++)
    scanf("%d",&price[i]);

    int arr[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i==0)
            arr[i][j]=j+1;
            else
            arr[i][j]=0;
        }
    }
    int d;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(j+1<len[i])
            arr[i][j]=arr[i-1][j];
            else if(i==j)
            arr[i][j]=price[i];
            else{
            if(arr[i-1][j]>(arr[i][j-len[i]]+price[i]))
            arr[i][j]=arr[i-1][j];
            else
            {
            arr[i][j]=arr[i][j-len[i]]+price[i];
            }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            printf("%d  ",arr[i][j]);
        }
        printf("\n");
    }
}

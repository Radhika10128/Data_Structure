#include<stdio.h>
int min(int a, int b)
{
    return (a<b)? a: b;
}
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    int arr[n+1][k+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=min(i,k);j++)
        {
            if(j==0 || j==i)
            arr[i][j]=1;
            else
            arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
        }
    }
    printf("%d",arr[n][k]);
}

#include<stdio.h>
int max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}
int main()
{
    int n;
    printf("Enter number of elements\n");
    scanf("%d",&n);
    int arr[n],result[n+1];
    printf("Enter the elements");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    result[0]=0;
    result[1]=arr[0];
    result[2]=arr[0]+arr[1];
    for(int i=3;i<=n;i++)
    {
        result[i]=max(max(result[i-1], result[i-2]+arr[i-1]), result[i-3]+arr[i-2]+arr[i-1]);
    }
    printf("%d",result[n]);
}

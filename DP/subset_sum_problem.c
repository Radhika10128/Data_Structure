#include<stdio.h>
struct elem
{
    int val;
}elem;
int comparator(const   void* a,const void* b)
{
    int l=((struct elem*)a)->val;
    int r=((struct elem*)b)->val;
    return l-r;
}
int main()
{
    int n,sum;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    scanf("%d",&sum);
    int arr[n][sum+1];
    qsort(a,n,sizeof(a[0]),comparator);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            if(j==a[i])
            arr[i][j]=1;
            else
            arr[i][j]=0;
        }
    }
    int sum1=a[0];
    for(int i=1;i<n;i++)
    {
        sum1=sum1+a[i];
        int min=sum1;
        if(min>(sum+1))
            min=sum+1;
        for(int j=0;j<=min;j++)
        {
            if(a[i]>j)
            arr[i][j]=arr[i-1][j];
            else if(a[i]==j)
                arr[i][j]=1;
            else
            {
            if(arr[i-1][j]==1)
            arr[i][j]=1;
            else{
            int v=j-a[i];
            if(arr[i-1][v]==1)
            arr[i][j]=1;
            }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            printf("%d  ",arr[i][j]);
        }
        printf("\n");
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i][sum]==1)
        {
        printf("True");
        break;
        }
    }
}

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
    int n;
    scanf("%d",&n);
    int arr[n];
    int sum;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    scanf("%d",&sum);
    int val[n][sum+1];
      qsort(arr,n,sizeof(arr[0]),comparator);
      int d=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            if(j==0)
            val[i][j]=0;
            else if(i==0)
            {
                if(j%arr[0]==0)
                    val[i][j]=d++;
                else
                    val[i][j]=0;
            }
            else
                val[i][j]=0;
        }
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            if(arr[i]>j)
                val[i][j]=val[i-1][j];
            else if(arr[i]==j)
                val[i][j]=1;
            else
            {
                int v=j-arr[i];
                val[i][j]=val[i][v]+1;
            }
        }
    }
    int min=val[0][sum];
        for(int i=1;i<n;i++)
        {
            if(min>val[i][sum])
           min=val[i][sum];
        }
         printf("Minimum coins is %d",min);
}

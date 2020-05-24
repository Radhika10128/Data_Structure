#include<stdio.h>
int main()
{
  int sum;
  scanf("%d",&sum);
  int val[]={1,2,3};
  int arr[4][sum];
  for(int i=0;i<4;i++)
  {
    for(int j=0;j<sum;j++)
    {
        if(i==1)
        arr[i][j]=1;
        else
        arr[i][j]=0;
    }
  }

  for(int i=2;i<4;i++)
  {
      for(int j=0;j<sum;j++)
      {
          if(j<val[i-1])
          arr[i][j]=arr[i-1][j];
          else
          arr[i][j]=arr[i-1][j]+arr[i][j-(val[i-1])];
      }
  }
  for(int i=0;i<4;i++)
  {
      for(int j=0;j<sum;j++)
      {
          printf("%d  ",arr[i][j]);
      }
      printf("\n");
  }
  printf("%d",arr[3][sum-1]);
}

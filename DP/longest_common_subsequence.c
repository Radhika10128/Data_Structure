#include<stdio.h>
#include<string.h>

int max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}
int lcs( char *X, char *Y, int m, int n )
{
    int t[m+1][n+1];
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0 || j==0)
                t[i][j]=0;
            else if(X[i-1]==Y[j-1])
                t[i][j]=t[i-1][j-1]+1;
            else
                t[i][j]=max(t[i-1][j],t[i][j-1]);
        }
    }
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            printf("%d  ",t[i][j]);
        }
        printf("\n");
    }
    int index=t[m][n];
    char result[index+1];
    result[index]='\0';
    int i=m,j=n;
    while(i>0 && j>0)
    {
        if(X[i-1]==Y[j-1])
        {
            result[index-1]=X[i-1];
            i--;
            j--;
            index--;
        }
        else if(t[i-1][j]>t[j][i-1])
            i--;
        else
            j--;
    }
    printf("Longest Sequence is %s\n",result);
    return t[m][n];
}
int main()
{
    char X[] = "AGGTAB";
  char Y[] = "GXTXAYB";

  int m = strlen(X);
  int n = strlen(Y);
  printf("Length of subsequence is %d", lcs( X, Y, m, n ) );

  return 0;
}

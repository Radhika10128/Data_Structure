#include<stdio.h>
int main()
{
    int n;
    printf("Enter the elements of array\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of array\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int start=0,end,index=0,length=0;
    for(int i=0;i<n-1;i++)
    {
        if((arr[i]>0 && arr[i+1]<0) || (arr[i]<0 && arr[i+1]>0))
        {
            continue;
        }
        else
        {
            end=i;
            int d=end-start;
            if(d>length)
            {
            length=d;
            index=start;
            }
            start=i+1;
        }
    }
    printf("Longest alternating subarray is ");
    for(int i=0;i<=length;i++)
    {
        printf("%d  ",arr[index]);
        index++;
    }
}

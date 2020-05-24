int solve(int A) {
    int i;
    const int mod=1000000007;
    long long count[A+1];
    count[0]=0;
    for(i=1;i<=A;i++)
    {
        if(i>2)
        count[i]=(count[i-1]+count[i-2])%mod;
        else if(i<2)
        count[i]=1;
        else
        count[i]=2;
    }
    return count[A];
}
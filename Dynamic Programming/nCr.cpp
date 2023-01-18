// Here we will use formula C(n,r) = C(n-1, r-1) + C(n-1, r)

int dp[1000][1000];
int p = 1000000007;

int solve(int n, int r)
{
    if(n==1 or r == n)
        return 1;
    if(r==1)
        return n;

    if(dp[n][r]!=-1)
        return dp[n][r];
        
    dp[n][r] = (solve(n-1, r-1) + solve(n-1, r))%p;
    
    return dp[n][r];
}

int nCr(int n, int r){
    // code here
    dp[n+1][r+1];
    if(n<r)
        return 0;
    memset(dp, -1, sizeof(dp));
    return solve(n,min(r, n-r));  // just replacing r eith min(r, n-r) to reduce T.C
}
#include <iostream>
#include <vector>
#define ll long long
#define mod 1000000007;
using namespace std;
 
/**************** Memoised Recursive approach *********/
// vector<vector<ll>> dp; 
// ll solve(ll i, ll j, vector<vector<char>> &grid, ll n)
// {
//     if(i<0 || j<0 || i>=n || j>=n)  return 0;
//     if(i==n-1 && j==n-1 && grid[i][j]!='*')    return 1;
//     if(grid[i][j]=='*')     return 0;
    
//     ll right = dp[i][j+1]!=-1 ? dp[i][j+1] : solve(i,j+1,grid,n);
//     ll down = dp[i+1][j]!=-1  ? dp[i+1][j] : solve(i+1,j,grid,n);
    
//     return dp[i][j] = (right+down)%mod;
// }
 
int main()
{
    ll n;  cin>>n;
    vector<vector<char>> grid(n,vector<char>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cin>>grid[i][j];
    }
    
    if(grid[0][0]=='*' || grid[n-1][n-1]=='*') cout<<0<<endl;
    else
    {
        // dp.resize(n,vector<ll>(n,-1));
        vector<vector<ll>> dp(n,vector<ll>(n,0));
        // dp[n-1][n-1]=1;
        for(int i=n-1; i>=0; i--)
        {
            for(int j=n-1; j>=0; j--)
            {
                if((i==n-1 && j==n-1))    dp[i][j]=1;
                else if(grid[i][j]=='*')    dp[i][j]=0;
                else{
                    ll op1 = (i+1<n) ? dp[i+1][j] : 0;
                    ll op2 = (j+1<n) ? dp[i][j+1] : 0;
                    dp[i][j] = (op1 + op2)%mod;
                }
            }
        }
        cout<<dp[0][0]<<endl;
    }
 
    return 0;
}
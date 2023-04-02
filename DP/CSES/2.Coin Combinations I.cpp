#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int n,x;    cin>>n>>x;
    int coins[n];
    for(int i=0; i<n; i++)  cin>>coins[i];
    long long dp[x+1]={0};
    dp[0]=1;
    for(int i=0; i<=x; i++)
    {
        // int temp=0;
        for(int j=0; j<n; j++){
            if(i-coins[j]>=0)
                dp[i] = (dp[i] + dp[i-coins[j]])%1000000007;
        }
        // dp[i] = temp;
    }
    cout<<dp[x]<<endl;
 
    return 0;
}
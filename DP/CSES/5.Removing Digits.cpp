#include <iostream>
#define ll long long
#define mod 1000000007;
using namespace std;
 
 
/**************** Basic Recursive approach *********/
// ll solve(ll n)
// {
//     if(n==0)    return 0;
//     if(n>=1 && n<=9)   return 1;
//     ll temp = n;
//     ll sub = temp%10;   temp=temp/10;
//     while(temp){
//         sub = max(sub,temp%10);
//         temp = temp/10;
//     }
//     return (1+solve(n-sub))%mod;
// }
 
int main()
{
    ll n;  cin>>n;
    // cout<<solve(n);
    
    /********* Tabulation approach ************/
    ll dp[n+1];
    dp[0]=0;
    for(ll i=1; i<=n; i++)
    {
        ll temp = i;
        ll sub = temp%10;  temp = temp/10;
        while(temp){
            sub = max(sub,temp%10);
            temp = temp/10;
        }
        dp[i] = 1+dp[i-sub];
    }
    cout<<dp[n]<<endl;
 
    return 0;
}
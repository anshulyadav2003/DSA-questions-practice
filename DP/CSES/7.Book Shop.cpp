#include <bits/stdc++.h>
using namespace std;
 
int mod = 1e9 +7; 
int main(){ 
    int n,x; cin>>n>>x; 
    // pair<int,int> h[n];
    int price[n];   int pages[n];
 
    for(int i=0;i<n;i++){
        // cin>>h[i].first;
        cin>>price[i];
    }
    for(int i=0;i<n;i++){
        // cin>>h[i].second;
        cin>>pages[i];
    }
    int dp[n+1][x+1];
    dp[0][0]=0;
    for(int i=0;i<=n;i++){
        dp[i][0] = 0;
    }
    for(int i=0;i<=x;i++){
        dp[0][i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=x;j++){
            if(j>=price[i-1]){
                dp[i][j] = max(dp[i-1][j- price[i-1]]+pages[i-1], dp[i-1][j]);
            } else{
                dp[i][j] = dp[i-1][j];
            }
            dp[i][j] %= mod;
        }
    }
    cout<<dp[n][x]<<"\n"; 
    return 0;
}
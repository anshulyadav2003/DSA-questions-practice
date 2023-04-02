#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,x;    cin>>n>>x;
    int coins[n];
    for(int i=0; i<n; i++){
        cin>>coins[i];
    }
    vector<long long> dp(x+1,INT_MAX);
    dp[0]=0;
    for (int i = 1; i <= n; i++) {
        for (int weight = 1; weight <= x; weight++) {
            if (weight - coins[i - 1] >= 0) {
                dp[weight] = min(dp[weight], dp[weight - coins[i - 1]] + 1);
            }
        }
    }
    cout << (dp[x] == INT_MAX ? -1 : dp[x]) << '\n';
}
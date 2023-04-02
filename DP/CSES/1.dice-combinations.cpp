#include <iostream>

using namespace std;
int main()
{
    int n;  cin>>n;
    int dp[n+1];
    dp[0]=1;
    for(int i=1; i<n+1; i++)
    {
        int temp=0;
        for(int k=1; k<=6; k++){
           if(i-k>=0)    temp = (temp+dp[i-k])%1000000007;
        }
        dp[i]=temp;
    }
    cout<<dp[n]<<endl;
    return 0;
}
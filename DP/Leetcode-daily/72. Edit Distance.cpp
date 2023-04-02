class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m=word2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1; i<m+1; i++)    dp[0][i]=i;
        for(int i=1; i<n+1; i++)    dp[i][0]=i;

        for(int i=1; i<n+1; i++)
        {
            for(int j=1; j<m+1; j++)
            {
                if(word1[i-1]!=word2[j-1]){
                    // delete : (i-1,j)
                    // insert : (i,j-1)
                    // replace: (i-1,j-1)
                    dp[i][j] = 1+min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]);
                } else{
                    // if match: nothing to do, just replace with (i-1,j-1) content 
                    dp[i][j] = dp[i-1][j-1];
                }
            }
        }
        return dp[n][m];
    }
};
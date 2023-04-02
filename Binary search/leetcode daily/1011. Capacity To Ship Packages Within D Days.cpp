class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int low=0,high=0;
        for(auto it:weights){
            high+=it;
            low = max(low, it);
        }
        
        int res=high;
        while(low<high)
        {
            int m = (high+low)/2;
            int curr=0, needDays=1;
            for(int i=0; (i<n && needDays<=days); curr += weights[i++]){
                if(curr+weights[i] > m){
                    curr=0; needDays++;
                }
            }

            if(needDays > days) 
                low = m+1;
            else{
                high=m;
                res = min(res, m);
            }
        }
        return res;


        // int sum=0;
        // for(auto it:weights)    sum+=it;
        // int dp[n+1][days+1] = {{0}};
        // for(int i=0; i<days+1; i++)
        //     dp[0][i]=0;
        // for(int i=0; i<n+1; i++){
        //     dp[i][0]=INT_MAX-1;
        //     dp[i][1]=sum;
        // }

        // int curr = 0;
        // for(int i=1; i<n+1; i++)
        // {
        //     for(int j=1; j<days+1; j++)
        //     {
        //         curr += weights[i-1];
                
        //         dp[i][j] = min(dp[i-1][j], dp[i-1][j-1]);
        //     }
    }
};
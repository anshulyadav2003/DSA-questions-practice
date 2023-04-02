class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int n = prices.size();
        int buy = prices[0];
        for(int i=0; i<n; i++)
        {
            buy = min(buy, prices[i]);
            
            int currProfit = prices[i]-buy;
            ans = max(ans, currProfit);
            
            
        }
        
        return ans;
        
    }
};
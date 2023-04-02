class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n = nums.size();
        int mini=INT_MAX, maxi=INT_MIN;
        for(int i=0; i<n; i++)
        {
            // maximising all odd numbers
            if(nums[i]%2 != 0)  nums[i] = 2*nums[i];

            maxi = max(maxi,nums[i]);
            mini = min(mini,nums[i]);
        }
        int diff = maxi - mini;

        priority_queue<int> pq;
        for(auto it:nums)   pq.push(it);

        while(pq.top()%2==0)
        {
            int top = pq.top();
            pq.pop();
            diff = min(diff,top-mini);
            top = top/2;
            mini = min(mini,top);
            pq.push(top);
        }
        diff = min(diff, (pq.top()-mini));
        return diff;
    }
};
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int reach = 0, curr=0;
        int jump=0;
        for(int i=0; i<n-1; i++)
        {
            reach = max(reach, i+nums[i]);
            
            if(i==curr){
                curr = reach;
                jump++;
            }
        }
        
        return jump;
    }
};
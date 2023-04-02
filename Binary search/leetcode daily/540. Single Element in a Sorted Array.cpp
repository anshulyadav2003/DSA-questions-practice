class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low=0, high=n-1;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            int x;
            if(mid-1>=0 && nums[mid]==nums[mid-1]){
                x = ((mid-2)-low+1);
                if(x%2==0)  low = mid+1;
                else        high = mid-2;
            }
            else if(mid+1<n && nums[mid]==nums[mid+1]){
                x = (high-(mid+2)+1);
                if(x%2==0)  high = mid-1;
                else        low = mid+2;
            }
            else    
                return nums[mid];
        }
        return -1;
    }
};
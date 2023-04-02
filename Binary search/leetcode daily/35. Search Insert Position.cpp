class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int i=1;
        if(nums[0]==target) return 0;
        if(target<nums[0])  return 0;
        for(i=1; i<n; i++){
            if(nums[i]==target) return i;
            if(target>nums[i-1] && target<nums[i])
                break;
        }
        return i;

        // int l=0,h=n-1;
        // while(l<=h)
        // {
        //     int mid = l/2 + (h-l)/2;
        //     if(nums[mid]==target)   return mid;
        //     else if(nums[mid]<target)   l=mid+1;
        //     else    h=mid-1;
        // }
        // return l+1;
        // int i;
        // for(i=1; i<n; i++){
        //     if(target>nums[i-1] && target<nums[i])
        //         break;
        // }
        // return i;
    }
};



/**************** LOWER_BOUND() approach ***************/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        auto it = lower_bound(nums.begin(), nums.end(), target);
        return (it-nums.begin());
    }
};
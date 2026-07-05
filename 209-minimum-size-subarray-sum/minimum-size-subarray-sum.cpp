class Solution {
public:

    int minSubArrayLen(int target, vector<int>& nums) {
        int low = 0;
        int high = 0;

        int n = nums.size();
        int sum = 0;
        int res =INT_MAX;

        for(high = 0;high<n;high++){
            sum += nums[high];

            while(sum>=target){
                res = min(res,high-low+1);
                sum-= nums[low];
                low++;
            }

        }
        if(res==INT_MAX)
            return 0;
        return res;
    }
   
};
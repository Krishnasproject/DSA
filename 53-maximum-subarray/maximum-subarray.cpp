class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int i = 0 ;
       int best_end = nums[0];
       int ans = nums[0];
       for(i=1;i<nums.size();i++){
        int v1 = best_end + nums[i];
        int v2 = nums[i];

        best_end = max(v1,v2);
        ans = max(ans,best_end);
       }
       return ans;
    }
};
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        int best_answer = nums[0];
        int ans = nums[0];

        for(int i = 1;i<n;i++){
            int v1 = best_answer + nums[i];
            int v2 = nums[i];

            best_answer = max(v1,v2);
            ans = max(best_answer,ans);
        }
        return ans;
    }
};
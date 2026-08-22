class Solution {
public:

    int findFirst(vector<int>&nums,int target){
        int n = nums.size();
        int low= 0;
        int high = n-1;
        int ans = -1;
        while(low<=high){
            int guess = low + (high - low)/2;

            if(nums[guess]>target)
                high = guess - 1;
            else if(nums[guess]<target)
                low = guess+1;
            else
                {
                    ans = guess;
                    high = guess -1;
                }
        }
        return ans;
    }

    int findLast(vector<int>&nums,int target){
        int n = nums.size();
        int low= 0;
        int high = n-1;
        int ans = -1;
        while(low<=high){
            int guess = low + (high - low)/2;

            if(nums[guess]>target)
                high = guess - 1;
            else if(nums[guess]<target)
                low = guess+1;
            else
                {
                    ans = guess;
                    low = guess+ 1;
                }
        }
        return ans;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>res(2,-1);

        res[0] = findFirst(nums,target);
        res[1] = findLast(nums,target);

        return res;
    }
};
class Solution {
public:

    bool func(vector<int>&nums, int n , int guess,int k ){
        int k1 = 1;
        int sum = 0;

        for(int i = 0;i<n;i++){
            if(sum+nums[i]<=guess)
            {
                sum += nums[i];
            }
            else
            {
                k1++;
                sum = nums[i];

                if(k1>k)
                    return false;
            }
            
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();

        if(n<k)
            return -1;

        int low = 0,high = 0 ;
        int res = -1;
        for(int i =0;i<n;i++){
            low = max(low,nums[i]);
            high += nums[i];
        }

        while(low<=high){
            int guess = low + (high - low)/2;

            if(func(nums,n,guess, k ))
            {
                res = guess;
                high = guess - 1;
            }
            else{
                low = guess + 1;
            }
        }
        return res;
    }
};
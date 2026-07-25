class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        int n = nums.size();
        int l =0;
        int r = n-1;

        while(l<r)
        {
            swap(nums[l],nums[r]);
            l = l+1;
            r = r-1;
        }

        l = 0,r= k-1;

        while(l<r)
        {
             swap(nums[l],nums[r]);
            l = l+1;
            r = r-1;
        }
        
        l = k,r = n-1;

        while(l<r)
        {
            swap(nums[l],nums[r]);
            l = l+1;
            r = r-1;
        }
    }

};
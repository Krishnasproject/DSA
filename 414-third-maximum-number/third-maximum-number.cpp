class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long first = LLONG_MIN;
        long long second = LLONG_MIN;
        long long third = LLONG_MIN;

        int n = nums.size();

        for(int i =0;i<n;i++){
            if(first == nums[i] || second == nums[i] || third == nums[i])
                continue;
            
            if(nums[i]>first){
                third = second;
                second = first;
                first = nums[i];
            }
            else if(nums[i]>second){
                third = second;
                second = nums[i];
            }
            else if (nums[i]>third){
                third = nums[i];
            }
        }
        if(third == LLONG_MIN)
            return first;
        return third;
    }
};
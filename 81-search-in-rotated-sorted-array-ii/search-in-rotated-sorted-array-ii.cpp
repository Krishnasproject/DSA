class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;

        while (low <= high) {
            int guess = low + (high - low) / 2;

            if (nums[guess] == target) {
                return true;
            }
            if (nums[low] == nums[guess] && nums[guess] == nums[high]) {
                    low++;
                    high--;
            }
            else if (nums[low] <= nums[guess]) {
                // left half [low..guess] is sorted
                if (nums[low] <= target && target < nums[guess])
                    high = guess - 1;
                else
                    low = guess + 1;
            }
            else {
                // right half [guess..high] is sorted
                if (nums[guess] < target && target <= nums[high])
                    low = guess + 1;
                else
                    high = guess - 1;
            }
        }
        return false;
    }
};
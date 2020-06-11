class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0, two = 0, n = nums.size(), idx = 0;
        while (idx < n-two) {
            if (nums[idx] == 2) {
                swap(nums[idx], nums[n-two-1]);
                ++two;
            } else if (nums[idx] == 1) {
                ++idx;
            } else {
                swap(nums[idx], nums[zero]);
                ++zero;
                ++idx;
            }
        }
    }
};
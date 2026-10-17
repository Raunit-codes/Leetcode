class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());

        int count = 0;
        int prev = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (count == 0 || nums[i] != prev) {
                count++;
                prev = nums[i];
            }

            if (count == 3) {
                return nums[i];
            }
        }

        return nums[0];
    }
};

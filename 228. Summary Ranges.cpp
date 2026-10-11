class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int left = 0;
        int right = 0;
        vector<string> ans;
        while (left < nums.size()) {
            while (right + 1 < nums.size() &&
                   nums[right + 1] == nums[right] + 1) {
                right++;
            }

            if (left == right) {
                ans.push_back(to_string(nums[left]));
            } else {
                ans.push_back(to_string(nums[left]) + "->" + to_string(nums[right]));
            }

            left = right + 1;
            right = left;
        }
        return ans;
    }
};

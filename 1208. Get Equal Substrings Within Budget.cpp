class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int left = 0;
        int currCost = 0;
        int ans = 0;

        for (int right = 0; right < s.size(); right++) {
            currCost += abs(t[right] - s[right]);
            while (currCost > maxCost) {
                currCost -= abs(t[left] - s[left]);
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int n = s.size();
        int m = p.size();

        if (m > n) return ans;

        int target[26] = {0};
        int window[26] = {0};

        for (char c : p) {
            target[c - 'a']++;
        }

        for (int i = 0; i < m; i++) {
            window[s[i] - 'a']++;
        }

        if (equal(target, target + 26, window)) {
            ans.push_back(0);
        }

        for (int right = m; right < n; right++) {
            window[s[right - m] - 'a']--;
            window[s[right] - 'a']++;

            if (equal(target, target + 26, window)) {
                ans.push_back(right - m + 1);
            }
        }

        return ans;
    }
};

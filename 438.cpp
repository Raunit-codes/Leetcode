
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int n = s.size();
        int m = p.size();

        if (m > n) return ans;

        int target[26] = {0};

        for (char c : p) {
            target[c - 'a']++;
        }

        for (int i = 0; i <= n - m; i++) {
            int freq[26] = {0};

            for (int j = i; j < i + m; j++) {
                freq[s[j] - 'a']++;
            }

            bool isAnagram = true;

            for (int c = 0; c < 26; c++) {
                if (freq[c] != target[c]) {
                    isAnagram = false;
                    break;
                }
            }

            if (isAnagram) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};

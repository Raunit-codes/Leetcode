class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }

        unordered_map<int, int> target;
        for (char ch : s1) {
            target[ch]++;
        }

        int left = 0;
        int k = s1.size();
        unordered_map<int, int> window;
        for (int right = 0; right < s2.size(); right++) {
            window[s2[right]]++;
            if (right - left + 1 > k) {
                window[s2[left]]--;
                if (window[s2[left]] == 0) {
                    window.erase(s2[left]);
                }
                left++;
            }
            if (right - left + 1 == k) {
                if (window == target) {
                    return true;
                }
            }
        }
        return false;
    }
};

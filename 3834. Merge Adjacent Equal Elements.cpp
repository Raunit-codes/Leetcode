class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        stack<long long> s;

        for (int num : nums) {

            long long current = num;

            while (!s.empty() && s.top() == current) {
                current = current + s.top();
                s.pop();
            }

            s.push(current);
        }

        vector<long long> ans;

        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

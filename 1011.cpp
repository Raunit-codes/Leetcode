class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);
        for (int capacity = left; capacity <= right; capacity++) {
            int daysRequired = 1;
            int currentLoad = 0;
            for (int i = 0; i < weights.size(); i++) {
                if (currentLoad + weights[i] <= capacity) {
                    currentLoad += weights[i];
                } else {
                    daysRequired++;
                    currentLoad = weights[i];
                }
            }
            if (daysRequired <= days) {
                return capacity;
            }
        }
        return right ;
    }
};

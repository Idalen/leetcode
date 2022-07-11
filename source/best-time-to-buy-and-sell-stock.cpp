class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_diff = 0, min_value = prices[0];
        int diff;
        for(int i=1; i<prices.size(); i++){
            diff = prices[i] - min_value;
            max_diff = max(max_diff, diff);
            min_value = min(min_value, prices[i]);
        }
        return max_diff;
    }
};
#define SIZE 400

class Solution {
public:

    int dp[SIZE];

    int rec(int val, vector<int> *nums, int pos){
        
        if (pos >= nums->size())
            return val;

        if(dp[pos] != -1)
            return dp[pos];

        int ret;

        ret = max(
            rec(val, nums, pos+1), 
            rec(val, nums, pos+2) + nums->at(pos));

        dp[pos] = ret;

        return ret;
    }

    int rob(vector<int>& nums) {
        
        for(int i=0; i<nums.size(); i++)
            dp[i] = -1;
       
        int money = rec(0, &nums, 0); 
        
        return money;
    }
};
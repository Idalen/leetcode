class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> res = {};
        for(int x : nums)
            res.push_back(nums[x]);
        return res;
    }
};
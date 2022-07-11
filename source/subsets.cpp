class Solution {
public:
    void rec(vector<int> *nums, int index, vector<int> temp, vector<vector<int>> *res){
        if(index==nums->size()){
            res->push_back(temp);
            return;
        }
        
        rec(nums, index+1, temp, res);
        temp.push_back(nums->at(index));
        rec(nums, index+1, temp, res);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        
        rec(&nums, 0, temp, &res);
        
        return res;
    }
};
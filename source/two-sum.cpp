using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> solution = {0, 0};
        for(int i = 0; i<nums.size(); i++){
            for(int j = i+1; j<nums.size(); j++){
                if(nums.at(i)+nums.at(j) == target){
                    solution = {i, j};
                    return solution;
                }
            }
        }
        return solution;
    }
};
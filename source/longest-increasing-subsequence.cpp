class Solution {
public:
    

    int lengthOfLIS(vector<int>& nums) {
        int mem[nums.size()], maximum=0;
        for(int i=0;i<nums.size(); i++)
            mem[i] = 1;
        
        for(int i=0; i<nums.size(); i++){
            for(int j=i; j>=0; --j){
                if(nums[i] > nums[j])
                    mem[i] = max(mem[i], mem[j]+1);
            }
            maximum = max(mem[i], maximum);
        }
        
        return maximum; 
    }
};
class Solution {
public:
    int jump(vector<int>& nums) {
        int mem[nums.size()];
        
        for(int i=1; i<nums.size(); i++)
            mem[i]=INT_MAX;
        mem[0]=0;
        
        for(int i=0; i<nums.size(); i++)
            for(int j=i+1; j<=i+nums[i]&&j<nums.size(); j++)
                mem[j] = min(mem[j], mem[i]+1);
        
        return mem[nums.size()-1];
    }
};
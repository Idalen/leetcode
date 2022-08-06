class Solution {
public:
    
    int add(int sum, vector<int>* v, int *mem){
        
        if(sum<0)
            return 0;
        
        if(sum == 0)
            return 1;
        
        
        if(mem[sum]!=-1)
            return mem[sum];
        
        int res=0;
        for(int x: *v){
            if(x > sum) break;
            res+=add(sum-x, v, mem);
        }
        
       
        return  mem[sum] = res;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        int mem[target+1];
        for(int i=0; i<=target; i++)
            mem[i] = -1;
        
        sort(nums.begin(), nums.end());
        
        return add(target, &nums, mem);
            
    }
};
class Solution {
public:
    bool rec(vector<int>* nums, int index, int* mem){
        
        if(mem[index]!=-1) return mem[index];
        
        bool ans = false;
        
        if(index==nums->size()-1) 
            ans = true;
        else
            for(int i=index+1; i<=index+nums->at(index)&&i<nums->size(); i++){
                ans = ans || rec(nums, i, mem);
                if(ans) break;
            }
        
        mem[index]=ans;
                
        
        return ans;
        
    }
    
    bool canJump(vector<int>& nums) {
        int mem[nums.size()];
        for(int i=0; i<nums.size(); i++)
            mem[i] = -1;
        
        rec(&nums, 0, mem);
        
        // for(int i=0; i<nums.size(); i++)
        //     cout << mem[i] << " ";
        // cout << endl;
        
        return rec(&nums, 0, mem);       
    }
};
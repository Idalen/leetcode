class Solution {
public:
    
    int rec(vector<int>* nums, int begin, int end, int* target){
        
        if(begin == end-1)
            return begin + (*target > nums->at(begin));
        
        int mid = (begin+end)/2;
        
        if(nums->at(mid) >= *target)
            return rec(nums, 0, mid, target);
        else
            return rec(nums, mid, end, target);
    }
    
    int searchInsert(vector<int>& nums, int target) {
        return rec(&nums, 0,nums.size(), &target);
    }
};
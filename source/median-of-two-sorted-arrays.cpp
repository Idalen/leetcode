class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        int even = (1+len1+len2)%2;
        int index = (len1+len2)/2;
        
        vector<int> nums3; 
        
        for(int i=0; i<(len1+len2)/2+1; i++){
            if(nums1.empty()){
                nums3.push_back(nums2.back());
                nums2.pop_back(); 
            }
            else if(nums2.empty()){
                nums3.push_back(nums1.back());
                nums1.pop_back();
            }
            else if(nums1.back() > nums2.back()){
                nums3.push_back(nums1.back());
                nums1.pop_back();
            }else{
                nums3.push_back(nums2.back());
                nums2.pop_back(); 
            }
        }
        
        double result = (nums3[nums3.size()-1] + nums3[nums3.size()-1-even])/2.0;
        
        return result;
    }
};
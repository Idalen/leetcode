const long int MAXINT = 9999999999999;

class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long int sum1 = 0, sum2=0, min_val=MAXINT, tmp, min_index=0;

        for(int x: nums)
            sum2+=x;
        
        for(int i=0;i<nums.size(); i++){
            sum1 += nums[i];
            sum2 -= nums[i];

            if(nums.size()==(i+1))
                tmp = sum1/(i+1);
            else tmp = sum1/(i+1)-sum2/(nums.size()-(i+1));

            if(abs(tmp) < min_val){
                min_val = abs(tmp);
                min_index = i;
            }
            //cout << sum1 <<"/"<< (i+1) << " " << sum2<<"/"<<(nums.size()-(i+1)) << " " <<tmp << endl;
            
        }

        return min_index;

    }
};
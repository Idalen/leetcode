class Solution {
public:
    bool validMountainArray(vector<int>& arr) {

        int state = -1;
        for(int i =1; i<arr.size(); i++){
            int past_x = arr[i-1];
            int curr_x = arr[i];
            
            if (state == -1){
                if(curr_x <= past_x){
                    return false;
                }
                state = 0;
            }
            else if(state == 0){
                if(curr_x == past_x){
                    return false;   
                }else if(curr_x < past_x){
                    state=1;
                }
            }
            else if(state == 1){
                if(curr_x >= past_x){
                    return false;
                }
            }
            
        }   
        return state==1 ? true : false;
    }
    
};
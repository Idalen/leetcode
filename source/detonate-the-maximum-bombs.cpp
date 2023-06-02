class Solution {
public:

    vector<int> dp;

    double distance(const vector<int>& a, const vector<int>& b){
        return sqrt(pow(a[0]-b[0], 2) + pow(a[1]-b[1], 2)); 
    }

    int rec(vector<vector<int>>& bombs, vector<int>& ctrl, int pos){
        if (ctrl[pos] == 1) return 0;

        if (dp[pos] == -1){ 

        ctrl[pos] = 1;
        int ret = 0;

        for(int i=0;i<bombs.size();i++)
            if(distance(bombs[pos], bombs[i]) <= bombs[pos][2])
                ret += rec(bombs, ctrl, i);
        
        dp[pos] = ret;
        }

        return 1+dp[pos];
    }
    
    int maximumDetonation(vector<vector<int>>& bombs) {
        int ret = 0;
        vector<int> ctrl;
        
        for(int i=0;i<bombs.size();i++){
            dp = vector(bombs.size(), -1);
            ctrl = vector(bombs.size(), 0);
            ret = max(rec(bombs, ctrl, i), ret);
        }

        return ret;
    }
};

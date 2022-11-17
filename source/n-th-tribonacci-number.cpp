class Solution {
public:
    int tribonacci(int n) {
        int sum;
        vector<int> t{0,1,1};
        if(n < 3)
            return t[n];
        
        for(int i=2; i < n; i++){
            sum = t[t.size()-1] + t[t.size()-2] + t[t.size()-3];
            t.push_back(sum);
        }

        return t[t.size()-1];
    }
};
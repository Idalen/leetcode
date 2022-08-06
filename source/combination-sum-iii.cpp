class Solution {
public:
    
    void add(int k, int n, int index, vector<vector<int>>* results, vector<int> history){
        if(n<0||history.size()==k+1) return;
        if(n==0 && history.size()==k){
            results->push_back(history);
            return;
        }
        
        
        for(int i=index; i<=9; i++){
            if(i>n) break;
            history.push_back(i);
            add(k, n-i,(i+1), results, history);
            history.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> v;
        vector<int> history;
        
        add(k, n, 1, &v, history);
        
        return v;
    }
};
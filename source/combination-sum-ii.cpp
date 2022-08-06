class Solution {
public:
    
   void add(int sum, vector<int>* v, int index, vector<int> history, vector<vector<int>>* result){
        
         
        if(sum == 0){ 
            result->push_back(history);
            return;
        }
        
        if(sum<0)
           return;
    
        
        for(int i=index; i<v->size(); i++){
            if(v->at(i)>sum) break;
            if(i-index&&v->at(i)==v->at(i-1)) continue;
            history.push_back(v->at(i));
            add(sum-v->at(i), v, i+1, history, result);
            history.pop_back();
        }
                   
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> v;
        vector<int> aux;
        
        sort(candidates.begin(), candidates.end());
        
        add(target, &candidates, 0, aux, &v);
        
        return v;
    }
};
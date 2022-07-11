class Solution {
public:
    
    int min(int a, int b){
        return a>b?b:a;
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        string output = "";
        
        int minlen = INT_MAX;
        for(int i=0; i<strs.size(); i++){
            minlen = min(strs[i].size(), minlen);
        }
        
        for(int i=0; i<minlen; i++){
            for(int j=1; j<strs.size(); j++){
                if(strs[j][i] != strs[j-1][i])
                    return output;
            }
            output.push_back(strs[0][i]);
            
        }
        
        return output;
    }
};
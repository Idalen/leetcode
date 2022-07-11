class Solution {
public:
    bool notin(char c, vector<char> memory){
        bool in = false;
        for(auto x : memory){
            if (c == x) 
                in = true;
        }
        
        return !in;
        
    }
    
    int lengthOfLongestSubstring(string s) {
        vector<char> mem;
        int curr_max = 0;
        
        for(int i = 0; i<s.size(); i++){
            int j = 0;
            while((j+i)<s.size() && notin(s[j+i],mem)){
                mem.push_back(s[j+i]);
                j++;
            }
            curr_max = max(j, curr_max);
            mem.clear();
        }
        
        return curr_max;
    }
};
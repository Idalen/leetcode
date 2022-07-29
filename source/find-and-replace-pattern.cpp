class Solution {
public:
    
    string mask(string s){
        
        int dict[26];
        memset(dict, -1, 26*4);
        
        int mask = 0;
        for(char c: s)
            if (dict[(int)c-97] == -1)
                dict[(int)c-97] = (mask++) + 97;
        
        for(int i=0; i<s.size(); i++)
            s[i] = dict[(int)s[i]-97];
               

        return s;
        
    }
    
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        vector<string> results;
        string masked_word;
        string masked_pattern = mask(pattern);
        
        for(string word: words){
            masked_word = mask(word);
            
            if (masked_word == masked_pattern)
                results.push_back(word);
        }
        
        return results;
        
    }
};
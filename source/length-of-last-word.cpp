class Solution {
public:
    int lengthOfLastWord(string s) {
            
        int acc = 0;
        
        for(int i=s.size()-1; i>=0; --i){
            
            if(s[i]==' '){
                if(acc>0)
                    break;
                else
                    continue;
            }else
                acc++;
        }
        
        return acc;
    }
};
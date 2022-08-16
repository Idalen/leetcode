class Solution {
public:
    
    vector<int> findSubstring(string s, vector<string>& words) {
        
        bool match;
        int n=words[0].size(), j, acc;
        unordered_map<string, int> map, count;
        vector<int> res;
            
        for(string word: words)
            if(count.find(word)==count.end())
                count[word] = 1;
            else
                count[word]++;
        
        int limit = (int)s.size()-n*(int)words.size();
        for(int i=0;i<=limit;i++){
            
            acc=words.size();
            map=count;
            j=i;
            
            for(int word=0; word<words.size();++word){
                
                if(map[words[word]]==0)
                    continue;
                match = words[word] == s.substr(j,n);
                map[words[word]]-=(int)match;
                if(match){ 
                    j+=n; 
                    if(!--acc||j>s.size()-n) break;
                    word=-1; 
                }
                
            }
            
            if(!acc){res.push_back(i);}
            
        }
        
        return res;
    }
};
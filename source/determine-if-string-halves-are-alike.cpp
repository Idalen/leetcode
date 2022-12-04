class Solution {
public:
    bool halvesAreAlike(string s) {
        int count=0;
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

        for(int i = 0; i<s.size()/2; i++)
            if (find(vowels.begin(),vowels.end(), s[i]) != vowels.end())
                count++;

        for(int i = s.size()/2; i<s.size(); i++)
            if (find(vowels.begin(),vowels.end(), s[i]) != vowels.end())
                count--;

        return count == 0;
            
        
    }
};
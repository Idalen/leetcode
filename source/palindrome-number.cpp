class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        
        std::string str = std::to_string(x);
        
        bool ans = true;
        for(int i = 0, j = str.size()-1; i <j; i++, j--){
            if(str.at(i) != str.at(j)){
                ans = false;
                break;
            }
        }
        
        return ans;
    }
};
class Solution {
public:
    
    string vowels = "aeiou";
    map<char, int> index;
    
    
    int combination(int n, string* history, int* mem){
        
        
        if(n==history->size())
            return 1;
        
        if(!history->empty()&&mem[this->index[history->back()]*n + (history->size()-1)] != -1) 
            return mem[this->index[history->back()]*n + (history->size()-1)];
        
        long long int res=0;
        
        if (history->empty()){
            for(char c: this->vowels){
                history->push_back(c);
                res+=combination(n, history, mem);
                history->pop_back();
            }
        }
        else if(history->back()=='a'){
            history->push_back('e');
            res+=combination(n, history, mem);
            history->pop_back();
        }
        else if(history->back()=='e'){
            history->push_back('a');
            res+=combination(n, history, mem);
            history->pop_back();
            history->push_back('i');
            res+=combination(n, history, mem);
            history->pop_back();
        }
        else if(history->back()=='i'){
            for(char c: this->vowels){
                if(c=='i') continue;
                history->push_back(c);
                res+=combination(n, history, mem);
                history->pop_back();
            }
        }
        else if(history->back()=='o'){
            history->push_back('i');
            res+=combination(n, history, mem);
            history->pop_back();
            history->push_back('u');
            res+=combination(n, history, mem);
            history->pop_back();
        }else{
            history->push_back('a');
            res+=combination(n, history, mem);
            history->pop_back();
        }
        
        res%=(long long)pow(10,9)+7;
        
        if(!history->empty())
            mem[this->index[history->back()]*n + (history->size()-1)] = res;
        
        return res;
                
    }
    
    int countVowelPermutation(int n) {
        int mem[5*n];
        
        for(int i=0; i<this->vowels.size(); i++)
            this->index[this->vowels[i]] = i;
        
        for(int i=0; i<5; i++)
            for(int j=0; j<n; j++)
                mem[n*i+j]=-1;
        
        string history;
        return combination(n, &history, mem);
    }
};
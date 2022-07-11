class TrieNode{
public:    
    TrieNode* children[26];
    bool eow = false;
    
    TrieNode(){
        for(int i =0; i<26; i++)
            this->children[i] = NULL;
    }
};




class WordDictionary {
public:
    TrieNode* root = new TrieNode();
    
    WordDictionary() {
        
    }
    
    void find(TrieNode* node, int index, string word, bool* found){
        
        if(index==word.size()){
            if(node->eow == true)
                *found = true;
            return;
        }
        
        char c = word.at(index);
        
        if(c == '.'){
            for(int i=0; i<26; i++){
                if(node->children[i]){
                    find(node->children[i], index+1, word, found);
                }
            }
        }
        else{
            if(node->children[c-'a']){
                find(node->children[c-'a'], index+1, word, found);    
            }
        }
        
        return;
    }
    
    void addWord(string word) {
        TrieNode* curr = this->root;
        for(char c: word){
            if(!curr->children[c-'a'])
                curr->children[c-'a'] = new TrieNode();
            curr = curr->children[c-'a'];
            
        }
        curr->eow = true;
    }
    
    bool search(string word) {
        bool found = false;
        
        find(root, 0, word, &found);
        
        return found;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
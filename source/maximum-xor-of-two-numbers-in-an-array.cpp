class TrieNode{
public:
    TrieNode* children[2];
    
    TrieNode(){
        this->children[0] = NULL;
        this->children[1] = NULL;
    }
};

class Trie{
public:
    TrieNode* root = new TrieNode();
    
    void insert(uint32_t number){
        TrieNode* curr_node = root;
        
        uint32_t mask = pow(2, 31);
        for(int i =32; i>0; i--){
            
            uint32_t n = (number&mask) >> (i-1);
            
            if(!curr_node->children[n]){
                curr_node->children[n] = new TrieNode();
            }
            
            curr_node = curr_node->children[n];
            mask /=2;
        }
    }
    
    uint32_t getMaxXor(uint32_t number){
        TrieNode* curr_node = root;
        uint32_t maxXor = 0;
        
        uint32_t mask = pow(2, 31);
        
        for(int i =32; i>0; i--){
            uint32_t n = (number&mask) >> (i-1);
            n = (n+1)%2;
            
            if(!curr_node->children[n])
                n = (n+1)%2;
            
            curr_node = curr_node->children[n];
            maxXor += mask*n;  
            mask /= 2;
        }
        
        cout << maxXor << endl;
        return maxXor;
    }
};



class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie* trie = new Trie();
        for(int n: nums){
            trie->insert(n);
        }
        
        int maximun = 0, aux;
        for(int n : nums){
            aux = trie->getMaxXor(n);
            maximun = max(maximun,(aux^n));
        }
        
        
        return maximun;
    }
};
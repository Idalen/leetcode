/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void getTreeElements(TreeNode* node, vector<int> *elements){
        if(node==NULL){
            return;
        }
        
        getTreeElements(node->left, elements);
        elements->push_back(node->val);
        getTreeElements(node->right, elements);
    }
    
    vector<int> joinVectors(vector<int> *a,  vector<int> *b){
        int i=0, j=0;
        int len_a = a->size();
        int len_b = b->size();
        vector<int> ret = {};
        
        while(true){
            
            if(i == len_a && j == len_b){
                break;
            }
            else if(i == len_a){
                ret.push_back(b->at(j));
                j++;
            }
            else if(j == len_b){
                ret.push_back(a->at(i));
                i++;
            }
            else if(a->at(i) < b->at(j)){
                ret.push_back(a->at(i));
                i++;
            }else{
                ret.push_back(b->at(j));
                j++;
            }
        }
        
        return ret;
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> elements1 = {};
        vector<int> elements2 = {};
        
        getTreeElements(root1, &elements1);
        getTreeElements(root2, &elements2);
        
        
        return joinVectors(&elements1, &elements2);
    }
    
};
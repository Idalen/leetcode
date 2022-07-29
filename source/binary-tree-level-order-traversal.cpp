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
    
    void rec(TreeNode* node, vector<vector<int>>* v, int level){
        
        if (node == nullptr)
            return;
        
        if (v->size() <= level){
            vector<int> inner_vector; 
            v->push_back(inner_vector);
        }
        
        v->at(level).push_back(node->val);
            
        
        rec(node->left, v, level+1);
        rec(node->right, v, level+1);
        
        
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        
        rec(root, &v, 0);
        
        return v;
        
    }
};
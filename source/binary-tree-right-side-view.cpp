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
using namespace std;

class Solution {
public:
    
    void rec(TreeNode* node, vector<int>* v, int acc){
        
        if (node == nullptr)
            return;
        
        if (acc >= v->size())
            v->push_back(node->val);
        
        rec(node->right, v, acc+1);
        rec(node->left, v, acc+1);
    
    }
    
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> v;
        
        rec(root, &v, 0);
            
        
        return v;
    }
};
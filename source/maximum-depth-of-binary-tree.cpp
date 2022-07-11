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
    void rec(TreeNode* root, int count, int *res){
        count++;
        
        if(root == NULL)
            return;
        
        if(count > *res){
            *res = count;
        }
        
        rec(root->left, count, res);
        rec(root->right, count, res);
        
        return;
        
    }
    
    int maxDepth(TreeNode* root) {
        int res=0;
        rec(root, 0, &res);
        return res;
    }
};
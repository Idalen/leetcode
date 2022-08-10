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
 0..3 -> 0..1 1..3
 */
class Solution {
public:
    
    void build(TreeNode *tree, vector<int>* nums, int begin, int end){
        int mid = (begin+end)/2;
        
        tree->val = nums->at(mid);
        
        if(begin!=mid){
            tree->left = new TreeNode();
            build(tree->left,nums,begin, mid);
        }
            
        if(end!=mid+1){
            tree->right = new TreeNode();
            build(tree->right,nums,mid+1, end);
        }
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* tree = new TreeNode();
        
        build(tree, &nums, 0, nums.size());
        
        return tree;
        
        
    }
};
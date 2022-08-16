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
    
    bool check(TreeNode* node, vector<int>* nums){
        
        bool res = true;
        
        if(node->left!=nullptr) res &= check(node->left, nums);
        nums->push_back(node->val);
        if(nums->size() > 1 && nums->at(nums->size()-2) >= nums->at(nums->size()-1))
            res = false;
        else if(node->right!=nullptr)
            res &= check(node->right, nums);
        
        return res;
        
    }
    
    bool isValidBST(TreeNode* root){
        vector<int> nums;
        return check(root, &nums);

    }
};
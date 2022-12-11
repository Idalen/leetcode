class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root == nullptr) return 0;

        //cout << root -> val << endl;

        return (root->val < low || root->val > high ? 0 : root->val) 
                + (root->val <= low ? 0 : rangeSumBST(root->left, low, high)) 
                + (root->val >= high ? 0: rangeSumBST(root->right, low, high));
    }
};
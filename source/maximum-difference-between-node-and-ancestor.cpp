#define MAXINT 10000001

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

    int rec(TreeNode* node, int minimum, int maximum){
        if (node == nullptr) return maximum-minimum;

        if(node->val > maximum) maximum = node->val;
        if(node->val < minimum) minimum = node->val;

        return max(rec(node->left, minimum, maximum), rec(node->right, minimum, maximum)); 
    }

    int maxAncestorDiff(TreeNode* root) {
        return rec(root, MAXINT, 0);
    }
};
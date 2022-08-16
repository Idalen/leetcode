/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        TreeNode* auxp=root, *auxq=root, *last;
        
        while(auxp->val==auxq->val){
            last = auxp;
            
            if(p->val>auxp->val) auxp=auxp->right;
            else if(p->val<auxp->val) auxp=auxp->left;
            
            if(q->val>auxq->val) auxq=auxq->right;
            else if(q->val<auxq->val) auxq=auxq->left;
        }
        
        return last;
    }
};
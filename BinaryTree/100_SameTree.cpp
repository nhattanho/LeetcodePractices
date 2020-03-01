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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!(p&&q)) return !(p||q);
        if(p->val == q->val){
            bool leftCheck = isSameTree(p->left,q->left);
            bool rightCheck = isSameTree(p->right,q->right);
            return leftCheck&&rightCheck;
        }
        else return false;
    }
};

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
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int leftVal =  minDepth(root->left);
        int rightVal = minDepth(root->right);
        if(leftVal == 0) return rightVal+1;
        if(rightVal == 0) return leftVal+1;
        return 1+ min(leftVal, rightVal);
    }
};

/*==> optimizing solution*/
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int leftVal =  minDepth(root->left);
        int rightVal = minDepth(root->right);
	if(leftVal == 0 || rightVal == 0) return max(leftVal, rightVal) + 1;
        return 1+ min(leftVal, rightVal);
    }
};

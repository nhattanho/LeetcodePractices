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
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int lefVal = maxDepth(root->left);
        int rightVal = maxDepth(root->right);
        return max(lefVal, rightVal)+1;
    }
};

/*==> using one line:*/
class Solution {
public:
    int maxDepth(TreeNode* root) {
	return root?(1 + max(maxDepth(root->left), maxDepth(root->right))):0;
    }
};



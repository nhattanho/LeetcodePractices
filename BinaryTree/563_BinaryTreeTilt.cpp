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
    
    int getSum(TreeNode* root, int& tilt ){
        if(root == NULL) return 0;
        int left = getSum(root->left, tilt);
        int right = getSum(root->right, tilt);
        tilt += abs(left-right);
        return (left+right+root->val);
    }
    
    int findTilt(TreeNode* root) {
        int tilt = 0;
        int a = getSum(root, tilt);
        return tilt;
    }
};

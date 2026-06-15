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
    int getLongest(TreeNode* root, int& ans){
        if(root == NULL) return 0;
        int left = getLongest(root->left, ans);
        int right = getLongest(root->right, ans);
        /*Because it's possible that the diameter does not go through
        the root, we need to check the diameter on each subtree.*/
        ans = max(ans,left+right);
        return max(left,right)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        int get = getLongest(root, ans);
        return ans;
    }
};

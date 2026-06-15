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
    void getSumleaf(TreeNode* root, vector<int>& saveNode){
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL){
            saveNode.emplace_back(root->val);
            return;
        }
        getSumleaf(root->left, saveNode);
        getSumleaf(root->right, saveNode);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf1, leaf2;
        getSumleaf(root1, leaf1);
        getSumleaf(root2, leaf2);
        return (leaf1==leaf2)?true:false;
    }
};

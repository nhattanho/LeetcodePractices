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
    TreeNode* childTree(TreeNode* root){
        if(root == NULL) return NULL;
        if(root->left == NULL && root->right == NULL){
            return root;
        }
        TreeNode* treeLeft = childTree(root->left);
        TreeNode* treeRight = childTree(root->right);
        root->left = treeRight;
        root->right = treeLeft;
        return root;
    }
    
    TreeNode* invertTree(TreeNode* root) {
       if (root == NULL) return root;
       return childTree(root);
    }
};

/*Optimizing DFS-Depth Fisrt Search code*/
class Solution {
public:
    TreeNode* temp;
    void DFS(TreeNode* root){
        if(root == NULL) return;
        temp = root->left;
        root->left = root->right;
        root->right = temp;
        DFS(root->left);
        DFS(root->right);
    }

    TreeNode* invertTree(TreeNode* root) {
        DFS(root);
        return root;
    }
};


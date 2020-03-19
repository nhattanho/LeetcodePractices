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
    vector<int> Nodes;
    void saveInOrder(TreeNode* root){
        if(root == NULL) return;
        saveInOrder(root->left);
        Nodes.emplace_back(root->val);
        saveInOrder(root->right);
    } 
    
    TreeNode* restructure(int left, int right){
        if(left > right) return NULL;
        int mid = (left+right)/2;
        TreeNode *newRoot = new TreeNode(Nodes[mid]);
        newRoot->left = restructure(left, mid-1);
        newRoot->right = restructure(mid+1, right);
        return newRoot;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        saveInOrder(root);
        int size = Nodes.size();
        return restructure(0, size - 1);
    }
};

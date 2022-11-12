class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return NULL;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* top = q.front(); q.pop();
            TreeNode* left = top->left;
            TreeNode* right = top->right;
            top->left = right;
            top->right = left;
            if(top->left != NULL) q.push(top->left);
            if(top->right != NULL) q.push(top->right);
        }
        return root;
    }
};

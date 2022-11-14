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

class Solution {
public:
    void dfs(TreeNode* root){
        if(root == NULL) return;

        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        dfs(root->left);
        dfs(root->right);
    }

    TreeNode* invertTree(TreeNode* root) {
        dfs(root);
        return root;
    }
};

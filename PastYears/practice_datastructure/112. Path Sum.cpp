class Solution {
public:
    bool hasPathSum(TreeNode* root, int target) {
        if(root == NULL) return false;
        target -= root->val;
        queue<pair<TreeNode*, int>>q;
        q.push({root, target});

        while(!q.empty()){
            pair<TreeNode*, int>top = q.front(); q.pop();
            TreeNode* tmp = top.first;
            int remain = top.second;
            if(tmp->left == NULL && tmp->right == NULL && remain == 0) return true;
            if(tmp->left!=NULL) q.push({tmp->left, remain-tmp->left->val});
            if(tmp->right!=NULL) q.push({tmp->right, remain-tmp->right->val});
        }
        return false;
    }
};

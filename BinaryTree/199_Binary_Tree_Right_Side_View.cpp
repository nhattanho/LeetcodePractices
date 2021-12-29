class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL) return {};
        vector<int>v;
        queue<TreeNode*>q; /*Space O(n) <=> diameter of the tree*/
        
        q.push(root);
        
        while(!q.empty()){ /*Time O(n)*/
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode* top = q.front();
                q.pop();
                if(top->left != NULL) q.push(top->left);
                if(top->right != NULL) q.push(top->right);
                if(i == size-1) v.push_back(top->val);
            }
        }
        return v;
    }
};

class Solution {
public:
    vector<vector<int>>v;
    
    void getNodes(TreeNode* root, int level){
        if(root == NULL) return;
        if(v.size() < level+1)
            v.push_back({});
        getNodes(root->left, level+1);
        getNodes(root->right, level+1);
        v[level].push_back(root->val);
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL) return {};
        getNodes(root, 0);
        //while(v.back().size() == 0) v.pop_back();
        return v;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL) return {};
        queue<TreeNode*>q;
        vector<vector<int>>v;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int>tmp;
            for(int i = 0; i < size; i++){
                TreeNode* top = q.front();
                q.pop();
                tmp.push_back(top->val);
                if(top->left!=NULL) q.push(top->left);
                if(top->right!=NULL) q.push(top->right);
            }
            v.push_back(tmp);
        }
        return v;
    }
};


class Solution {
public:
    
    void getResult(TreeNode* root, int level, vector<vector<int>>& v){
        if(root == NULL) return;
        
        if(v.size() <= level)
            v.push_back({});
        
        v[level].push_back(root->val);
        getResult(root->left, level+1, v);
        getResult(root->right, level+1, v);
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        int level = 0;
        vector<vector<int>>v;
        getResult(root, level, v);
        return v;
    }
};

/*BFS*/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL) return {};
        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>>v;/*Saved all nodes => Space O(n)*/
        int level = 0;
        while(!q.empty()){ /*Time complexity: O(N) since each node is processed exactly once*/
            int size = q.size();
            v.push_back({});
            for(int i = 0; i < size; i++){
                TreeNode *top = q.front();
                q.pop();
                v[level].push_back(top->val);
                if(top->left != NULL) q.push(top->left);
                if(top->right != NULL) q.push(top->right);
            }
            level++;
        }
        return v;
    }
};

/*DFS, time = space complexity = O(n)*/
class Solution {
public:
    vector<vector<int>>v;
    
    void getNodes(TreeNode* root, int level){
        if(root == NULL) return;
        if(v.size() < level+1)/*only add a new element in vector at the first time visiting each level*/
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

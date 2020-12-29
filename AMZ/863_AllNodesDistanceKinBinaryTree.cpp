/* Time and Space complexity O(n) */
class Solution {
public:
    unordered_map< TreeNode*, TreeNode*>parent;
    unordered_set<TreeNode*> visited;
    
    void findParent(TreeNode* root, unordered_map< TreeNode*, TreeNode*>& parent){
        if(root->left != NULL) {
            parent[root->left] = root;
            findParent(root->left, parent);
        }
         
        if(root->right != NULL){
            parent[root->right] = root;
            findParent(root->right, parent);
        }
    }
    
    void findRes(TreeNode* target, int K, vector<int>&res){
        if(target == NULL) return;
        if(visited.count(target)>0) return;
        visited.insert(target);
        if(K == 0) {
            res.push_back(target->val);
            return;
        }
     
        findRes(target->left, K-1, res);
        findRes(target->right, K-1, res);
        findRes(parent[target], K-1, res);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        if(root == NULL) return {};
        
        vector<int>res;
        
        findParent(root, parent);
        findRes(target, K, res);
        return res;
    }
    
};

class Solution {
public:
    
    void findNode(TreeNode* root, TreeNode* parent, unordered_map<TreeNode*, vector<TreeNode*>>&m){
        if(root == NULL) return;
        m[root].push_back(root);
        if(parent!=NULL) {
            for(auto x: m[parent])
                m[root].push_back(x);
        }
        
        findNode(root->left, root, m);
        findNode(root->right, root, m);
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* parent = NULL;
        unordered_map<TreeNode*, vector<TreeNode*>>m;
        findNode(root, parent, m);
        
        vector<TreeNode*>v1 = m[p];
        vector<TreeNode*>v2 = m[q];
        int l1 = v1.size()-1;
        int l2 = v2.size()-1;
        while(l1>=0&&l2>=0){
            if(v1[l1] == v2[l2]){
                l1--;
                l2--;
            }else break;
        }
        return v1[l1+1];
    }
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int parentVal = root->val;
        int pVal = p->val;
        int qVal = q->val;
        if(pVal > parentVal and qVal > parentVal)
            return lowestCommonAncestor(root->right, p, q);
        if(pVal < parentVal and qVal < parentVal)
            return lowestCommonAncestor(root->left, p, q);
        else return root;
    }
};

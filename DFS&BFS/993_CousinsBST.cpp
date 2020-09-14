class Solution {
public:
    int depth1 = 0, depth2 = 0, flag = 0;
    void depthFind(TreeNode* root, int x, int y, int level){
        if(root == NULL) return;
        if(root->left != NULL && root->right != NULL){
            if( (root->left->val == x && root->right->val == y) 
            || (root->left->val == y && root->right->val == x) ) {
                flag = 1;
                return;
            }
        }
        level++;
        if(root->val == x ) depth1 = level;
        if(root->val == y) depth2 = level;
        depthFind(root->left, x, y, level);
        depthFind(root->right, x, y, level);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        int level = 0;
        if(root == NULL) return false;
        depthFind(root, x, y,level);
        if(depth1 != depth2 || flag == 1) return false;
        return true;
    }
};

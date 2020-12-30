class Solution {
public:
    
    bool checkSum(TreeNode* root, int sum, int count){
        if(root == NULL) return false;
        
        count += root->val;
        if(count == sum && root->left == NULL && root->right == NULL){
            return true;
        }
        
        bool left = checkSum(root->left, sum, count);
        if(left == true) return true;
        bool right = checkSum(root->right, sum, count);
        if(right) return true;
        return false;
    }
    
    bool hasPathSum(TreeNode* root, int sum) {
        return checkSum(root, sum, 0);
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool flag = false;
    bool check(TreeNode* root, TreeNode* lower, TreeNode* upper){
        if(root == NULL) return true;
        
        if(upper != NULL and root->val >= upper->val) return false;
        if(lower != NULL and root->val <= lower->val) return false;
        
        bool left = check(root->left, lower, root);
        bool right = check(root->right, root, upper);
        return left&&right;
    }
    
    bool isValidBST(TreeNode* root) {
        TreeNode *upper = NULL;// <=> +infinity
        TreeNode *lower = NULL;// <=> -infinity
        return check(root, lower, upper);
    }
};

/**/
class Solution {
public:
    bool flag = false;
    bool check(TreeNode* root, TreeNode* lower, TreeNode* upper){
        if(root == NULL) return true;
        
        if( (upper!=NULL && lower != NULL && root->val < upper->val && root->val > lower->val) //for the node in the middle of the tree
           or (upper == NULL and lower == NULL) // for the root node
           or (lower!=NULL and root->val > lower->val and upper == NULL) // for the right most node
           or (upper != NULL and root->val < upper->val and lower == NULL) // for the left most node
         ) {
            bool left = check(root->left, lower, root);
            bool right = check(root->right, root, upper);
            return left&&right;
        }else 
            return false; 
    }
    
    bool isValidBST(TreeNode* root) {
        TreeNode *upper = NULL;// <=> +infinity
        TreeNode *lower = NULL;// <=> -infinity
        return check(root, lower, upper);
    }
};

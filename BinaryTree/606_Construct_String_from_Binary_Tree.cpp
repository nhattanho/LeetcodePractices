/*
preorder traversal way ==> focus on the order: node -> left -> right
I this problem, the simply way to construct string is string = node(lelft)(right)
*/

class Solution {
public:
    
    string buildString(TreeNode *root){
        if(root == NULL) return "()";
        string res = "";
        
        res += to_string(root->val);
        
        string left = buildString(root->left);
        string right = buildString(root->right);
        
        if(right != "()"){
            right = "(" + right + ")";
            if(left != "()") left = "(" + left + ")";
            res += (left+right);
        } else if (left != "()"){
            left = "(" + left + ")";
            res += left;
        }
        
        return res;
    }
    
    string tree2str(TreeNode* root) {
        return buildString(root);
    }
};

/*More readable code*/
class Solution {
public:
    
    string buildString(TreeNode *root){
        if(root == NULL) return "()";
        string res = "";
        res += to_string(root->val);
        
        string left = buildString(root->left);
        string right = buildString(root->right);
        
        if(left != "()") left = "(" + left + ")";
        
        if(right != "()"){
            right = "(" + right + ")";
            res += (left+right);
        } else if (left != "()")
            res += left;

        return res;
    }
    
    string tree2str(TreeNode* root) {
        return buildString(root);
    }
};

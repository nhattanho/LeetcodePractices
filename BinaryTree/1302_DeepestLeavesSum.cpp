/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*Version1: Passing level to find the max deepth during of process*/
class Solution {
public:
    int max_level = -1, sum = 0;
    void sumOfNodesAtMaxDepth(TreeNode *ro,int level) 
    { 
        if(ro == NULL) return; 
        if(level > max_level) 
        { 
            sum = ro -> val; 
            max_level = level; 
        } 
        else if(level == max_level) sum = sum + ro -> val;  
        sumOfNodesAtMaxDepth(ro -> left, level + 1); 
        sumOfNodesAtMaxDepth(ro -> right, level + 1);  
    } 
    int deepestLeavesSum(TreeNode* root) {
        sumOfNodesAtMaxDepth(root, 0);
        return sum;
    }
};

/*Version2: Find the deepest Node first, then calculate the sum*/
class Solution {
public:
    int deepLevel(TreeNode* root){
        if(root == NULL) return 0;
        int leftVal = deepLevel(root->left);
        int rightVal = deepLevel(root->right);
        return max(leftVal, rightVal) + 1;
    }

    void getRes(TreeNode* root, int max, int& sum){
       if(root == NULL) return;
        if(max == 1){
            sum += root->val;
            return;
        }
        getRes(root->left, max - 1, sum);
        getRes(root->right, max - 1, sum);
    }

    int deepestLeavesSum(TreeNode* root){

        int sum = 0;
        int max = deepLevel(root);
        getRes(root, max, sum);
        return sum;
    }
};

/*Version3: Using map/unordered_map to optimize problem*/
class Solution {
public:
    unordered_map<int,int>data; //<level,sum>
    void getSum(TreeNode* root, int level){
        if(root == NULL) return;
        data[level] += root->val;
        getSum(root->left, level+1);
        getSum(root->right, level+1);
    }

    int deepestLeavesSum(TreeNode* root){
        int sum = 0;
        getSum(root,0);
        return data[data.size()-1];
    }
};

class Solution {
    int sum = 0;
public:
    void findSum(TreeNode* root, string temp){
        //base case
        if(root == NULL) return;
        temp += to_string(root->val);
        if(root->left == NULL && root->right == NULL){
            sum += stoi(temp);
            return;
        }

        findSum(root->left, temp);
        findSum(root->right, temp);
    }
    int sumNumbers(TreeNode* root) {
        if (root == NULL ) return 0;
        findSum(root, "");
        return sum;
    }
};

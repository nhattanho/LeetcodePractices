class Solution {
public:
    TreeNode* mergeTrees(TreeNode* r1, TreeNode* r2) {
        if(r1 == NULL) return r2;
        if(r2 == NULL) return r1;
        stack<vector<TreeNode*>>st;
        st.push({r1,r2});
        while(!st.empty()){
            vector<TreeNode*>t = st.top();
            st.pop();
            TreeNode* tmp1 = t[0];
            TreeNode* tmp2 = t[1];
            if(tmp1 && tmp2){
                tmp1->val += tmp2->val;
                /*We stop merging but need to reconstruct the r1*/
                if(tmp1->left == NULL && tmp2->left != NULL){
                    tmp1->left = tmp2->left;
                }
                /*We only continue the merging when both node are
                not equal to null*/
                else if(tmp1->left && tmp2->left){
                    st.push({tmp1->left, tmp2->left});
                }
                if(tmp1->right == NULL && tmp2->right != NULL){
                    tmp1->right = tmp2->right;
                }
                else if(tmp1->right && tmp2->right){
                    st.push({tmp1->right, tmp2->right});
                }
            }
        }
        return r1;
    }
};

/* Using iteration */
class Solution {
public:
    void buildTree(TreeNode* head, int val){
        TreeNode* mov = head;// can use directly head instead of using mov
        TreeNode* temp = new TreeNode(val);
        while(mov != NULL){
            if(temp->val < mov->val){
                if(mov->left == NULL){
                    mov->left = temp;
                    return;
                }
                else mov = mov->left;
            } else {
                if(mov->right == NULL){
                    mov->right = temp;
                    return;
                }
                else mov = mov->right;
            }
        }
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int len = preorder.size();
        TreeNode* head = NULL;
        for(int i = 0; i < len; i++){
            TreeNode* temp = new TreeNode(preorder[i]);
            if (head == NULL) head = temp;
            else
                buildTree(head, preorder[i]);
        }
        return head;
    }
};

/* Using recursive */
class Solution {
public:
    void buildTree(TreeNode* head, TreeNode*& temp){
        if (head == NULL) return;
        if (temp->val < head->val) {
            buildTree(head->left, temp);
            head->left = temp;
        } else {
            buildTree(head->right, temp);
            head->right = temp;
        }
        temp = head;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int len = preorder.size();
        TreeNode* head = NULL;
        for(int i = 0; i < len; i++){
            TreeNode* temp = new TreeNode(preorder[i]);
            if (head == NULL) head = temp;
            else{
                TreeNode* temp = new TreeNode(preorder[i]);
                buildTree(head, temp);
            }
        }
        return head;
    }
};

/* Using stack for checking from bottom to root */
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int len = preorder.size();
        TreeNode* head = NULL;
        stack<TreeNode*>st;
        for (int i = 0; i < len; i++) {
            TreeNode* temp = new TreeNode(preorder[i]); // create a new node
            if (head == NULL){
                head = temp;
                st.push(head);
            } else if (temp->val < st.top()->val){
                st.top()->left = temp; //create left link
                st.push(temp); // save address's new node into stack
            } else {
                TreeNode* mov; // create a moving pointer
                while (!st.empty() && temp->val > st.top()->val) {
                    mov = st.top();
                    st.pop();
                }
                mov->right = temp;
                st.push(temp);
            }

        }
        return head;
    }
};

/* Using DFS with time complexity 0(n), space O(1) */
class Solution {
public:
    void countCheck(TreeNode* root, int& count){
        if(root == NULL) return;
        count++;
        countCheck(root->left, count);
        countCheck(root->right, count);
    }

    int countNodes(TreeNode* root) {
        int count = 0;
        countCheck(root, count);
        return count;
    }
};

/* ==> Optimize code for DFS */
public int countNodes(TreeNode* root) {
    if (root == null) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

/* Using BFS with time complexity O(n), space O(n) */
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        queue<TreeNode*>q;
        int count = 0;
        q.push(root);
        while(!q.empty()){
            count++;
            TreeNode* temp = q.front();
            q.pop();
            if(temp->left != NULL) q.push(temp->left);
            if(temp->right != NULL) q.push(temp->right);
        }
        return count;
    }
};

/* Using the relationship of full and complete tree to reduce Time complexity
 * to O( (log(n))^2 ) */
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;
        TreeNode* leftNode = root, *rightNode = root;
        int countL = 0, countR = 0;
        //1 loop: log(n)
        while(leftNode != NULL){
            countL++;
            leftNode = leftNode->left;
        }
        //1 loop: log(n)
        while (rightNode != NULL) {
            countR++;
            rightNode = rightNode->right;
        }
        if (countL == countR) return pow(2,countL) - 1; //has to be full tree
        return 1 + countNodes(root->left) + countNodes(root->right);
        /* worst case runs log(n) times loops */
    }
};

/* Using Morris Traversal */
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;
        TreeNode* cur = root, *move;
        int count = 0;
        while(cur){
            if (cur->left == NULL) {
                count++; //count for the end of left
                cur = cur->right;
            } else {
                move = cur->left;
                while(move->right != NULL and move->right != cur)
                    move = move->right;
                if (move->right == NULL) {
                    move->right = cur;//save link by connecting the end of right link to the current node
                    cur = cur->left;
                }
                else { //starting traversal
                    count++; //count for root
                    move->right = NULL;
                    cur = cur->right;
                }
            }
        }
        return count;
    }
};

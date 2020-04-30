/* Using DFS with Time complexity O(n), Space O(n)*/
class Solution {
public:
    bool test(TreeNode* leftNode, TreeNode* rightNode){
        if(!(leftNode&&rightNode)) return !(leftNode||rightNode);
        if(leftNode->val == rightNode->val){
            bool firstCheck = test(leftNode->left, rightNode->right);
            bool secondCheck = test(leftNode->right, rightNode->left);
            return firstCheck&&secondCheck;
        }
        else return false;
    }
        
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return test(root->left, root->right);
    }
};

/* Using BFS with Time complexity O(n), Space O(n) */
class Solution {
public:
    queue<TreeNode*>leftSave, rightSave;
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        TreeNode* leftNode = root->left, *rightNode = root->right;
        leftSave.push(leftNode);
        rightSave.push(rightNode);
        while(1){
            if(!leftSave.empty() && !rightSave.empty()){
                leftNode = leftSave.front();
                leftSave.pop();
                rightNode = rightSave.front();
                rightSave.pop();
                if(leftNode == NULL && rightNode == NULL) continue;
                else if(leftNode != NULL && rightNode != NULL){
                    if(leftNode->val == rightNode->val){
                        leftSave.push(leftNode->left);
                        leftSave.push(leftNode->right);
                        rightSave.push(rightNode->right);
                        rightSave.push(rightNode->left);
                    }else return false;
                }else return false;
            }
            else if(leftSave.empty() && rightSave.empty()) return true;
            else return false;
        }
    }
};

/* Still using BFS, but less used space */
class Solution {
public:
    queue<TreeNode*>q;
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        TreeNode* leftNode = root->left, *rightNode = root->right;
        q.push(leftNode);
        q.push(rightNode);
        while(!q.empty()){
            leftNode = q.front();
            q.pop();
            rightNode = q.front();
            q.pop();
            if(leftNode == NULL && rightNode == NULL) continue;
            if(leftNode == NULL || rightNode == NULL) return false;
            if(leftNode->val != rightNode->val) return false;
            q.push(leftNode->left);
            q.push(rightNode->right);
            q.push(leftNode->right);
            q.push(rightNode->left);
        }
        return true;
        }
};

/* Funny iterated Solution by using list */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        TreeNode *leftNode = root->left, *rightNode = root->right;
        list<TreeNode*>saveLeft, saveRight;
        while(true){
            if(leftNode == NULL && rightNode == NULL){
                if(saveLeft.empty()&&saveRight.empty()) return true;
                else if(!(saveLeft.empty()||saveRight.empty())){
                    leftNode = saveLeft.front();
                    saveLeft.pop_front();
                    rightNode = saveRight.front();
                    saveRight.pop_front();
                }                        
                else return false;
            }
            else if(leftNode != NULL && rightNode != NULL)
            {
                if(leftNode->val == rightNode->val){
                    if(leftNode->left != NULL || leftNode->right != NULL){
                        saveLeft.emplace_back(leftNode->left);
                        saveLeft.emplace_back(leftNode->right);
                    }
                    if(rightNode->left != NULL || rightNode->right != NULL){
                        saveRight.emplace_back(rightNode->right);
                        saveRight.emplace_back(rightNode->left);
                    }
                    if(saveLeft.empty()&&saveRight.empty()) return true;
                    else if(!(saveLeft.empty()||saveRight.empty())){
                        leftNode = saveLeft.front();
                        saveLeft.pop_front();
                        rightNode = saveRight.front();
                        saveRight.pop_front();
                    }                        
                    else return false;
                }
                else return false;
            }
            else return false;
        }
        return false;
    }
};

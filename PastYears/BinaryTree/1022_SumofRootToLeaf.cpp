/*Sol1: Using DFS to save binary string first
 *and then convert these strings to decimal numbers*/
class Solution {
public:
    vector<string>bin;
    void getBinary(TreeNode* root, string s){
        if(root == NULL) return;
        s += to_string(root->val);
        if(root->left == NULL && root->right == NULL){
            bin.emplace_back(s);
            return;
        }
        getBinary(root->left, s);
        getBinary(root->right, s);
    }
    
    int bintoInt(string binNum){
        int len = binNum.length(), dec = 0;
        for(int i = len-1; i >= 0; i--) dec += (binNum[i]-48)*pow(2,len-i-1);
        return dec;
    }
    
    int sumRootToLeaf(TreeNode* root) {
        string s = "";
        getBinary(root, s);
        int ans = 0;
        for(auto x:bin) ans += bintoInt(x);
        return ans;    
    }
};

/*Sol2: The same technique by using DFS, however
 *instead of saving binary strings, using shift technique
 *to get binary number directly after calling recursion every time*/
class Solution {
public:
    void getBinary(TreeNode* root, int num, int& ans){
        if(root == NULL) return;//example: 0000 0000 ==> 0000 0001
        num <<= 1;//shifting to the left <=> multiply by 2
        if(root->val == 1) num += 1;
        /*
        if(!root->left && !root->right){
            ans += num;
            return;
        }
        */
        getBinary(root->left, num, ans);
        getBinary(root->right, num, ans);
        if(!root->left && !root->right) ans+=num;
    }

    int sumRootToLeaf(TreeNode* root) {
        int ans = 0;
        getBinary(root, 0, ans);
        return ans;
    }
};

/*Sol3: Another way to approach*/
class Solution {
public:
    int getBinary(TreeNode* root,int sum)
    {
        if(root == NULL) return 0;
        sum = 2*sum + root->val;
        if(root->left != NULL || root->right != NULL)
           return getBinary(root->left,sum) + getBinary(root->right,sum);
        return sum;
    }

    int sumRootToLeaf(TreeNode* root) {
        int ans = 0;
        return getBinary(root, ans);
    }
};

class Solution {

    public boolean dfs(TreeNode root, int remain){
        if(root == null) return false;
        if(root != null && root.left == null && root.right == null){
            if(remain == root.val) return true;
            return false;
        } 
        boolean left = dfs(root.left, remain-root.val);
        if(left) return true;
        boolean right = dfs(root.right, remain-root.val);
        return left||right;
    }

    public boolean hasPathSum(TreeNode root, int target) {
        if(root == null) return false;
        return dfs(root, target);
    }
}


class Solution {
    public boolean hasPathSum(TreeNode root, int target) {
        if(root == null) return false;
        if(root.left == null && root.right == null){
            if(target == root.val) return true;
            return false;
        } 
        boolean left = hasPathSum(root.left, target-root.val);
        if(left) return true;
        boolean right = hasPathSum(root.right, target-root.val);
        return left||right;
    }
}

class Solution {
    public boolean dfs(TreeNode root, int target, int count){
        if(root == null) return false;
        count += root.val;
        if(root.left == null && root.right == null) return count == target;

        boolean left = dfs(root.left, target, count);
        if(left) return true;
        boolean right = dfs(root.right, target, count);
        return left||right;
    }

    public boolean hasPathSum(TreeNode root, int target) {
        if(root == null) return false;
        return dfs(root, target, 0);
    }
}

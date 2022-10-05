class Solution {
    public TreeNode mergeTrees(TreeNode r1, TreeNode r2) {
        if(r1 != null && r2 != null) r1.val = r1.val+r2.val;
        else if (r1 != null && r2 == null) return r1;
        else if(r1 == null && r2 != null){
            return r2;
        } else return null;
        
        TreeNode left = mergeTrees(r1.left, r2.left);
        if(left != null) r1.left = left;
        TreeNode right = mergeTrees(r1.right, r2.right);
        if(right != null) r1.right = right;
        return r1;
    }
}

class Solution {
    public TreeNode mergeTrees(TreeNode r1, TreeNode r2) {
        if(r1 == null) return r2;
        if(r2 == null) return r1;
        r1.val += r2.val;
        r1.left = mergeTrees(r1.left, r2.left);
        r1.right = mergeTrees(r1.right, r2.right);
        return r1;
    }
}

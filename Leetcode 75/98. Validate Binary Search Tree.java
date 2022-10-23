/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    
    public boolean check(TreeNode node, TreeNode upper, TreeNode lower){
        if(node == null) return true;
        
        /*Remove special cases that the node's value = MAX or MIN at the beginning tree
            lower: null  max  upper: null      OR:           max                                                                                                                         /                                         
                    /         \                             /
                   2           3                          max
        */
        if(upper != null && node.val >= upper.val) return false;
        if(lower != null && node.val <= lower.val ) return false;
        
        boolean left, right;
        left = check(node.left, node, lower);
        right = check(node.right, upper, node);
        return left&&right;
    }
    
    public boolean isValidBST(TreeNode node) {
        if(node == null) return true;
        TreeNode upper = null, lower = null;
        return check(node, upper, lower);
    }   
}

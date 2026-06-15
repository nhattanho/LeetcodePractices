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
            lower: null max  upper: null      OR:            max                                                                                                                         /                                         
                    /         \                            max
                   2           3
        when the node.val = Min or Max, it is only true if the node is the root of the tree,
        otherwise, it will be false. And when the node is the root, upper = lower = null.
        And other cases, if the node is not a root but has the value = MIN or MAX, it has
        to be false.
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

/**/
public boolean isValidBST(TreeNode node) {
        if(node == null) return true;
        TreeNode upper = null, lower = null;
        Queue<TreeNode[]>q = new LinkedList<>();
        q.add(new TreeNode[]{lower, node, upper});
        while(q.size()!=0){
            TreeNode[] t = q.poll();
            TreeNode l = t[0];
            TreeNode n = t[1];
            TreeNode u = t[2];
            if(n == null) continue;
            if(u!= null && n.val >= u.val) return false;
            if(l!= null && n.val <= l.val) return false;
            q.add(new TreeNode[]{l, n.left, n});
            q.add(new TreeNode[]{n, n.right, u});
        }
        return true;
    }   

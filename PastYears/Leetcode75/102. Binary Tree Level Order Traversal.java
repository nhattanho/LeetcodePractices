class Solution {
    public void helper(TreeNode root, List<List<Integer>>l, int level){
        if(root == null) return;
        
        if(l.size()<=level)
            l.add(new LinkedList<Integer>());
        
        l.get(level).add(root.val);
        helper(root.left, l, level+1);
        helper(root.right, l, level+1);
    }
    
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>>l = new LinkedList<>();
        helper(root, l, 0);
        return l;
    }
}

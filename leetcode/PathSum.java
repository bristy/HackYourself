 /**
 * @author: Brajesh
 * PathSum .java
 */ 

import java.util.*;

public class PathSum {
    public PathSum () {
    }

    public static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        public TreeNode(int val){
            this(val, null, null);
        }

        public TreeNode(int val, TreeNode left, TreeNode right){
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }
    // https://oj.leetcode.com/problems/path-sum/
    public boolean hasPathSum(TreeNode root, int sum) {
        if(root == null){
            return false;
        }
        if(root.left == null && root.right == null){
            return sum == root.val;
        }
        boolean ret = false;
        if(root.left != null){
            ret = hasPathSum(root.left, sum - root.val);
        }
        if(!ret && root.right != null){
            ret = hasPathSum(root.right, sum - root.val);
        }

        return ret;
    }
    
    
    // https://oj.leetcode.com/problems/path-sum-ii/
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        List<List<Integer>> ret = new ArrayList<List<Integer>>();
        pathSum(root, sum, new ArrayList<Integer>(), ret);
        return ret;
    }

    public void pathSum(TreeNode root, int sum, List<Integer> path, List<List<Integer>> ret) {
        if(root == null){
            return ;
        }
        if(root.left == null && root.right == null){
            if(root.val == sum){
                path.add(root.val);
                ret.add(new ArrayList(path));
                path.remove(path.size() - 1);
            }
            return;
        }
        path.add(root.val);
        if(root.left != null){
            pathSum(root.left, sum - root.val, path, ret);
        }
        if(root.right != null){
            pathSum(root.right, sum - root.val, path, ret);
        }
        path.remove(path.size() - 1);
    }

    public static void main(String[] args){
        PathSum sol = new PathSum();
        TreeNode left = new TreeNode(4, new TreeNode(11), null);
        TreeNode right = new TreeNode(8, new TreeNode(13), new TreeNode(7));
        TreeNode root = new TreeNode(5, left, right);
        System.out.println(sol.pathSum(root, 20));

    }
}
//PathSum .java 


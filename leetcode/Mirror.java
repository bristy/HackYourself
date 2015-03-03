 /**
 * @author: Brajesh
 * Mirror .java
 */ 

import java.util.*;

public class Mirror {
    public Mirror () {
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
    public boolean isSymmetric(TreeNode root) {
        if(root == null){
            return true;
        }
        TreeNode left = root.left;
        TreeNode right = root.right;
        if(left == null && right == null){
            return true;
        }

        if(left != )
    }
    
    public boolean isSymmetric(TreeNode root) {
                
    }
    public static void main(String[] args){
        Mirror sol = new Mirror();
        TreeNode left = new TreeNode(4, new TreeNode(11), null);
        TreeNode right = new TreeNode(8, new TreeNode(13), new TreeNode(7));
        TreeNode root = new TreeNode(5, left, right);
        System.out.println(sol.pathSum(root, 20));

    }
}
//Mirror .java 


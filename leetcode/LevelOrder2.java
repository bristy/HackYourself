/**
 * @author: Brajesh
 * LevelOrder2 .java
 */ 
import java.util.*;
public class LevelOrder2 {
    public LevelOrder2 () {
    }

    public static class TreeNode{
        int val;
        TreeNode left;
        TreeNode right;
        public TreeNode(int val, TreeNode left, TreeNode right){
            this.val = val;
            this.left = left;
            this.right = right;
        }

        public TreeNode(int val){
            this(val, null, null);
        }
    }

    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        List<List<Integer>> ret = new LinkedList<List<Integer>>();
        solve(root, 0, ret);
        return ret;
    }

    void solve(TreeNode curr, int level, List<List<Integer>> ret){
        if(curr == null){
            return;
        }
        
        if(level >= ret.size()){
            LinkedList<Integer> link = new LinkedList<Integer>();
            ret.add(0, link);
        }
        ret.get(ret.size() - level - 1).add(curr.val);
        solve(curr.left, level + 1, ret);
        solve(curr.right, level + 1, ret);

    }

    public static void main(String[] args){
        TreeNode left1 = new TreeNode(9);
        TreeNode right1 = new TreeNode(20, new TreeNode(15), new TreeNode(7));
        TreeNode root = new TreeNode(3, left1, right1);
        LevelOrder2 sol = new LevelOrder2();
        System.out.println(sol.levelOrderBottom(root));
        
    }
}
//LevelOrder2 .java 


/**
 * @author: Brajesh
 * ZigZagLevelOrder .java
 */ 
import java.util.*;
public class ZigZagLevelOrder {
    public ZigZagLevelOrder () {
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

    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
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
            ret.add(link);
        }
        if(level % 2 == 0){
            ret.get(level).add(curr.val);
        } else {
            ret.get(level).add(0, curr.val);
        }
        solve(curr.left, level + 1, ret);
        solve(curr.right, level + 1, ret);

    }

    public static void main(String[] args){
        TreeNode left1 = new TreeNode(9);
        TreeNode right1 = new TreeNode(20, new TreeNode(15), new TreeNode(7));
        TreeNode root = new TreeNode(3, left1, right1);
        ZigZagLevelOrder sol = new ZigZagLevelOrder();
        System.out.println(zigzagLevelOrder(root));
        
    }
}
//ZigZagLevelOrder .java 


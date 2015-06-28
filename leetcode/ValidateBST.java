import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x){
        val = x;
    }
}

public class ValidateBST {
    public boolean isValidBST(TreeNode root){

        return isValidBST(root, Long.MIN_VALUE, Long.MAX_VALUE);
    }

    private boolean isValidBST(TreeNode root, long minValue, long maxValue){
        if(root == null){
            return true;
        }
        boolean ans = root.val > minValue && root.val < maxValue;
        return ans && isValidBST(root.left, minValue, Math.min(maxValue, root.val))
            && isValidBST(root.right, Math.max(minValue, root.val), maxValue);
    }
}

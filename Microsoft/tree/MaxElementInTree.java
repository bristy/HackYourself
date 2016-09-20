package tree;

import TreeAlgos.IntegerTreeNode;
import TreeAlgos.Mock;
import TreeAlgos.TreeNode;

/**
 * Created by brajesh.k on 20/09/16.
 */
public class MaxElementInTree {
    public static  int getMaxElem(TreeNode<Integer> root) {

        int maxElem = Integer.MIN_VALUE;
        if (root != null) {
            maxElem = root.getVal();
            int left = getMaxElem(root.getLeft());
            int right = getMaxElem(root.getRight());
            maxElem = Math.max(maxElem, left);
            maxElem = Math.max(maxElem, right);
        }
        return maxElem;
    }

    public static void main(String[] args) {
        TreeNode<Integer> root = Mock.getIntegerBinaryTree();
        System.out.println("max elem is = " + getMaxElem(root));
    }
}

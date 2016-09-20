package tree;

import TreeAlgos.IntegerTreeNode;
import TreeAlgos.Mock;
import TreeAlgos.TreeNode;
import TreeAlgos.TreeTraversal;

/**
 * Created by brajesh.k on 20/09/16.
 */
public class MirrorTree {
    public static <T extends Comparable<T>> TreeNode<T> getMirror(TreeNode<T> root) {
        if (root != null) {
            TreeNode tmp = root.getLeft();
            root.setLeft(root.getRight());
            root.setRight(tmp);
            getMirror(root.getLeft());
            getMirror(root.getRight());
        }
        return root;
    }

    public static void main(String[] args) {
        TreeNode<Integer> root = Mock.getIntegerBinaryTree();
        System.out.println("preOrderRecursion before mirror>>>>>");
        TreeTraversal.preOrderRecursion(root);
        root = getMirror(root);
        System.out.println("preOrderRecursion after mirror>>>>>");
        TreeTraversal.preOrderRecursion(root);

    }
}

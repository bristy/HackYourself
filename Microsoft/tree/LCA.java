package tree;

import mock.Mock;
import TreeAlgos.TreeNode;

/**
 * Created by brajesh.k on 21/09/16.
 */
public class LCA {
    // assumes both keys are present
    public static<T extends Comparable<T>> TreeNode<T> getLCA(TreeNode<T> root, TreeNode<T> one, TreeNode<T> two) {
        if (root == null) {
            return root; // propagate root up
        }
        if (root == one || root == two) {
            return root; // this is LCA
        }

        TreeNode<T> left = getLCA(root.getLeft(), one, two);
        TreeNode<T> right = getLCA(root.getRight(), one, two);
        if (left != null && right != null) {
            return root;
        }
        if (left != null) {
            return left;
        }
        if (right != null) {
            return right;
        }
        return null; // keys not found
    }

    public static void main(String[] args) {
        TreeNode<Integer> root = Mock.getIntegerBinaryTree();
        root = getLCA(root, root.getLeft().getLeft(), root.getLeft().getRight());
        System.out.println(root);
    }
}

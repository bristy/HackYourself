package tree;

import mock.Mock;
import TreeAlgos.TreeNode;

/**
 * Created by brajesh.k on 20/09/16.
 */
public class SizeOfTree {
    public static<T extends Comparable<T>> int getSize(TreeNode<T> root) {
        int size = 0;
        if (root != null) {
            return  getSize(root.getLeft()) + getSize(root.getRight()) + 1;
        }
        return size;
    }

    public static void main(String[] args) {
        TreeNode<Integer> root = Mock.getIntegerBinaryTree();
        System.out.println("size of tree is = " + getSize(root));


    }
}

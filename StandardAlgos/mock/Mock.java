package mock;

import LinkedList.ListNode;
import LinkedList.SLList;
import TreeAlgos.TreeNode;

/**
 * Created by brajesh.k on 20/09/16.
 */
public class Mock {
    public static TreeNode<Integer> getIntegerBinaryTree() {
        // http://www.geeksforgeeks.org/wp-content/uploads/2009/06/tree12.gif
        TreeNode<Integer> root = new TreeNode<>(1);
        root.setLeft(new TreeNode<>(2));
        root.setRight(new TreeNode<>(3));
        root.getLeft().setLeft(new TreeNode<>(4));
        root.getLeft().setRight(new TreeNode<>(5));
        root.getRight().setLeft(new TreeNode<>(6));
        root.getRight().setRight(new TreeNode<>(7));
        return root;
    }

    public static SLList<Integer> getIntegerList() {
        SLList<Integer> slList = new SLList<>();
        slList.push(1);
        slList.push(2);
        slList.push(3);
        slList.push(4);
        slList.push(5);
        slList.push(6);
        return slList;
    }
}

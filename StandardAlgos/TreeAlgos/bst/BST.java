package TreeAlgos.bst;

import TreeAlgos.TreeNode;

/**
 * Created by brajesh.k on 25/09/16.
 */
public class BST<T extends Comparable<T>> {
    TreeNode<T> root;

    private void insert(TreeNode<T> root, T data) {
        int cmp = data.compareTo(root.getVal());
        TreeNode<T> next;
        if (cmp == 0) {
            return;
        } else if (cmp < 0) { // got to left
            if (root.getLeft() == null) {
                root.setLeft(new TreeNode<T>(data));
            } else {
                insert(root.getLeft(), data);
            }
        } else if (cmp > 0) { // go to right
            if (root.getRight() == null) {
                root.setRight(new TreeNode<T>(data));
            } else {
                insert(root.getRight(), data);
            }
        }

    }

    public void insert(T data) {
        if (root == null) {
            root = new TreeNode<T>(data);
            return;
        }
        insert(root, data);
    }

    public void display() {
        display(root);
    }

    private void display(TreeNode<T> root) {
        if (root != null) {
            display(root.getLeft());
            System.out.println(root.getVal());
            display(root.getRight());
        }
    }

    public static void main(String[] args) {
        BST<Integer> bst = new BST<>();
        bst.insert(4);
        bst.insert(2);
        bst.insert(1);
        bst.insert(3);
        bst.insert(6);
        bst.insert(5);
        bst.insert(7);
        bst.display();
    }

}

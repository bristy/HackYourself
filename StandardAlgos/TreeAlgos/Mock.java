package TreeAlgos;

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
}

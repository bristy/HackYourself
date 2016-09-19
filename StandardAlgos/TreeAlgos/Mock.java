package TreeAlgos;

/**
 * Created by brajesh.k on 20/09/16.
 */
public class Mock {
    public static IntegerTreeNode getIntegerBinaryTree() {
        // http://www.geeksforgeeks.org/wp-content/uploads/2009/06/tree12.gif
        IntegerTreeNode root = new IntegerTreeNode(1);
        root.setLeft(new IntegerTreeNode(2));
        root.setRight(new IntegerTreeNode(3));
        root.getLeft().setLeft(new IntegerTreeNode(4));
        root.getLeft().setRight(new IntegerTreeNode(5));
        return root;
    }
}

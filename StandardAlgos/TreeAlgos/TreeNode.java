package TreeAlgos;

public class TreeNode<T extends Comparable<T>> implements Comparable<T> {
    private T val;
    private TreeNode left;
    private TreeNode right;

    public TreeNode(T val) {
        this.val = val;
    }

    public TreeNode(T val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }

    public T getVal() {
        return val;
    }

    public void setVal(T val) {
        this.val = val;
    }

    public TreeNode<T> getLeft() {
        return left;
    }

    public void setLeft(TreeNode<T> left) {
        this.left = left;
    }

    public TreeNode<T> getRight() {
        return right;
    }

    public void setRight(TreeNode<T> right) {
        this.right = right;
    }

    @Override
    public int compareTo(T o) {
        return this.compareTo(o);
    }

    @Override
    public String toString() {
        return String.format("Val = %d" , val);
    }
}


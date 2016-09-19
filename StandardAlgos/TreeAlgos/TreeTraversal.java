package TreeAlgos;

import java.util.Stack;

/**
 * Created by brajesh.k on 20/09/16.
 */
public class TreeTraversal {
    // VLR
    public static <T> void preOrderRecursion(TreeNode<T> root) {
        if (root != null) {
            // process root
            System.out.println(root.getVal());
            // explore left subtree
            preOrderRecursion(root.getLeft());
            // explore right subtree
            preOrderRecursion(root.getRight());
        }
    }


    public static <T> void preOrderNonRecursion(TreeNode<T> root) {
        if (root == null) {
            return;
        }
        Stack<TreeNode<T>> stack = new Stack<TreeNode<T>>();
        while (true) {
            while (root != null) {
                // process root
                System.out.println(root.getVal());
                stack.push(root);
                root = root.getLeft();
            }

            if (stack.isEmpty()) {
                break;
            }
            root = stack.pop().getRight();

        }

    }

    public static <T> void inOrderRecursion(TreeNode<T> root) {
        if(root != null) {
            // explore left subtree
            inOrderRecursion(root.getLeft());
            // visit root
            System.out.println(root.getVal());
            // explore right
            inOrderRecursion(root.getRight());
        }
    }

    public static <T> void inOrderNonRecursion(TreeNode<T> root) {
        if (root == null) {
            return;
        }

        Stack<TreeNode<T>> stack = new Stack<>();
        while (true) {
            while (root != null) {
                stack.push(root);
                root = root.getLeft();
            }
            if (stack.isEmpty()) {
                break;
            }
            root = stack.pop();
            System.out.println(root.getVal());
            root = root.getRight();
        }
    }

    public static <T> void postOrderRecursion(TreeNode<T> root) {
        if (root != null) {
            // explore left
            postOrderRecursion(root.getLeft());
            // explore right
            postOrderRecursion(root.getRight());
            // visit node
            System.out.println(root.getVal());
        }
    }

    public static <T> void postOrderNonRecursion(TreeNode<T> root) {
        if (root == null) {
            return;
        }

        Stack<TreeNode<T>> stack = new Stack<>();
        while (true) {
            while (root != null) {
                // root has right child push on stack and then push root
                if (root.getRight() != null) {
                    stack.push(root.getRight());
                }
                stack.push(root);
                root = root.getLeft();
            }

            // pop top from stack
            root = stack.pop();
            // if root  has right child and current top of stack is equal to right child
            // process first right then root
            if (!stack.isEmpty() && root.getRight() != null && root.getRight() == stack.peek()) {
                // remove right child from stack
                stack.pop();
                // push root on stack for later visit
                stack.push(root);
                root = root.getRight();
            } else {
                System.out.println(root.getVal());
                root = null;
            }
            if (stack.isEmpty()) {
                break;
            }
        }
    }


    // stub to test
    public static void main(String[] args) {

        IntegerTreeNode root = Mock.getIntegerBinaryTree();
        System.out.println("preOrderRecursion >>>>>");
        preOrderRecursion(root);

        System.out.println("preOrderNonRecursion >>>>>");
        preOrderNonRecursion(root);

        System.out.println("inOrderRecursion >>>>>");
        inOrderRecursion(root);

        System.out.println("inOrderNonRecursion >>>>>");
        inOrderNonRecursion(root);

        System.out.println("postOrderRecursion >>>>>");
        postOrderRecursion(root);

        System.out.println("postOrderNonRecursion >>>>>");
        postOrderNonRecursion(root);
    }
}

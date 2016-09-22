package tree;

import mock.Mock;
import TreeAlgos.TreeNode;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by brajesh.k on 20/09/16.
 */
public class AllRootToLeafPaths {
    public static <T extends Comparable<T>> void printRootToLeafPath(TreeNode<T> root, List<TreeNode<T>> path) {
        if (root == null) {
            return;
        }
        // add current node to path
        path.add(root);
        // base case if node is leaf print path
        if (root.getRight() == null && root.getLeft() == null) {
            StringBuilder sb = new StringBuilder();
            for (TreeNode<T> node : path) {
                sb.append(node.getVal() + " ");
            }
            System.out.println(sb);

        } else {
            printRootToLeafPath(root.getLeft(), path);
            printRootToLeafPath(root.getRight(), path);
        }
        // remove current node from path
        path.remove(root);

    }

    public static void main(String[] args) {
        TreeNode<Integer> root = Mock.getIntegerBinaryTree();
        System.out.println("Root to leaf paths are =>>>>>> ");
        printRootToLeafPath(root, new ArrayList<>());
    }
}

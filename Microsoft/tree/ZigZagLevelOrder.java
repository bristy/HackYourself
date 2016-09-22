package tree;

import mock.Mock;
import TreeAlgos.TreeNode;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

/**
 * Created by brajesh.k on 20/09/16.
 */
public class ZigZagLevelOrder {
    public static <T extends Comparable<T>> void zigZagLevelOrder(TreeNode<T> root) {
        if (root == null) {
            return;
        }

        boolean rtl = true;
        List<TreeNode<T>> result = new ArrayList<>();
        Queue<TreeNode<T>> queue = new LinkedList<>();
        queue.add(root);
        queue.add(null); // marker to tell level has finished
        while (!queue.isEmpty()) {
            root = queue.poll();
            if (root == null) { // level has finished
                // flush level buffer
                if (rtl) {
                    for (int i = result.size() - 1; i >= 0;i--) {
                        System.out.print(result.get(i).getVal() + " ");
                    }
                } else {
                    for (int i = 0; i < result.size(); i++) {
                        System.out.print(result.get(i).getVal() + " ");
                    }
                }
                System.out.println();
                result.clear();
                rtl = !rtl;
                if (!queue.isEmpty()) {
                    queue.add(null); // new delimiter
                }
                continue;
            } else { // process node
                result.add(root);
            }
            TreeNode<T> left = root.getLeft();
            TreeNode<T> right = root.getRight();

            if (left != null) {
                queue.add(left);
            }
            if (right != null) {
                queue.add(right);
            }


        }
    }

    public static void main(String[] args) {
        TreeNode<Integer> root = Mock.getIntegerBinaryTree();
        System.out.println("zigZagLevelOrder is >>>>> " );
        zigZagLevelOrder(root);
    }
}


public class BST{
    /**
     * Tree Node for Tree
     */
    public static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        public TreeNode(int val, TreeNode left, TreeNode right){
            this.val = val;
            this.left = left;
            this.right = right;
        }

        public TreeNode(int val){
            this(val, null, null);
        }
        
        @Override
        public String toString(){
            return String.valueOf(val);
        }
    }

    
    private TreeNode root;

    public BST(){
    
    }

    public BST(int val){
        root = new TreeNode(val);
    }
    
    public TreeNode getRoot(){
        return root;
    }

    /**
     * Add a node to BST
     */
    public void add(int val){
        add(new TreeNode(val)); 
    }

    public void add(TreeNode node){
        if(root == null){
            root = node;
            return;
        }
        TreeNode curr = root;
        while(true){
            if(curr.val > node.val){
                if(curr.left == null){
                    curr.left = node;
                    return;
                }
               curr = curr.left;
            } else {
                if(curr.right == null){
                    curr.right = node;
                    return;
                }
                curr = curr.right;
            }
        }
    }

    /**
     * Inorder Traversal
     */
    public void inorder(){
        inorder(root); 
    }

    public void inorder(TreeNode root){
        if(root != null){
            inorder(root.left);
            System.out.println(root.val);
            inorder(root.right);
        }
    }


    /**
     * verify if tree is bst
     */
    public boolean verifyBST(TreeNode root){
        return verifyBST(root, Integer.MIN_VALUE, Integer.MAX_VALUE); 
    }

    public boolean verifyBST(TreeNode root, int min, int max){
        if(root == null){
            return true;
        }
        boolean ans = root.val > min && root.val < max;
        ans = ans && verifyBST(root.left, min, Math.min(root.val, max));
        ans = ans && verifyBST(root.right, Math.max(min, root.val), max);

        return ans;

    }

    
    /**
     * get mirror node of node with value val
     */
    public TreeNode getMirror(int val){
        return getMirror(val, root, root);
    }

    public TreeNode getMirror(int val, TreeNode curr, TreeNode mirror){
       if(curr == null || mirror == null){
           return null;
       }
       if(curr.val == val){
           return mirror;
       }
       TreeNode temp = getMirror(val, curr.left, mirror.right);
       temp = temp == null ? getMirror(val, curr.right, mirror.left) : temp;
       return temp;
    }
    public static void main(String[] args){
        int[] nums = new int[]{4, 5, 2, 3, 1, 7 };
        BST bst = new BST();

        for(int n : nums){
            bst.add(n);
        }
        bst.inorder();
        System.out.println(bst.verifyBST(bst.getRoot()));
        System.out.println(bst.getMirror(7));
    }
}

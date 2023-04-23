
import java.util.LinkedList;
import java.util.Queue;

public class Solution {

    public TreeNode replaceValueInTree(TreeNode root) {
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);

        root.val = 0;
        int sumForAllNodesAtLevelChildren = calculateSumForChildrenOfNode(root);

        while (!queue.isEmpty()) {

            int currentLevelSize = queue.size();
            int sumForAllNodesAtLevelChildrenOfChildren = 0;

            while (currentLevelSize-- > 0) {
                TreeNode current = queue.poll();
                int sumForChildrenOfCurrentNode = calculateSumForChildrenOfNode(current);

                if (current.left != null) {
                    current.left.val = sumForAllNodesAtLevelChildren - sumForChildrenOfCurrentNode;
                    sumForAllNodesAtLevelChildrenOfChildren += calculateSumForChildrenOfNode(current.left);
                    queue.add(current.left);
                }

                if (current.right != null) {
                    current.right.val = sumForAllNodesAtLevelChildren - sumForChildrenOfCurrentNode;
                    sumForAllNodesAtLevelChildrenOfChildren += calculateSumForChildrenOfNode(current.right);
                    queue.add(current.right);
                }
            }
            sumForAllNodesAtLevelChildren = sumForAllNodesAtLevelChildrenOfChildren;
        }
        return root;
    }

    private int calculateSumForChildrenOfNode(TreeNode node) {
        return ((node.left != null) ? node.left.val : 0)
                + ((node.right != null) ? node.right.val : 0);
    }
}

/*
Class TreeNode is in-built in the solution file on leetcode.com. 
When running the code on the website, do not include this class.
 */
class TreeNode {

    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {}

    TreeNode(int val) {
        this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

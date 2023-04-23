
/**
 * @param {TreeNode} root
 * @return {TreeNode}
 */
var replaceValueInTree = function (root) {
    //const {Queue} = require('@datastructures-js/queue');  
    const queue = new Queue();//Queue<TreeNode>
    queue.enqueue(root);

    root.val = 0;
    let sumForAllNodesAtLevelChildren = calculateSumForChildrenOfNode(root);

    while (!queue.isEmpty()) {

        let currentLevelSize = queue.size();
        let sumForAllNodesAtLevelChildrenOfChildren = 0;

        while (currentLevelSize-- > 0) {
            let current = queue.dequeue();
            let sumForChildrenOfCurrentNode = calculateSumForChildrenOfNode(current);

            if (current.left !== null) {
                current.left.val = sumForAllNodesAtLevelChildren - sumForChildrenOfCurrentNode;
                sumForAllNodesAtLevelChildrenOfChildren += calculateSumForChildrenOfNode(current.left);
                queue.enqueue(current.left);
            }

            if (current.right !== null) {
                current.right.val = sumForAllNodesAtLevelChildren - sumForChildrenOfCurrentNode;
                sumForAllNodesAtLevelChildrenOfChildren += calculateSumForChildrenOfNode(current.right);
                queue.enqueue(current.right);
            }
        }
        sumForAllNodesAtLevelChildren = sumForAllNodesAtLevelChildrenOfChildren;
    }
    return root;
};

/**
 * @param {TreeNode} node
 * @return {number}
 */
function calculateSumForChildrenOfNode(node) {
    return ((node.left !== null) ? node.left.val : 0)
            + ((node.right !== null) ? node.right.val : 0);
}

/*
 Function TreeNode is in-built in the solution file on leetcode.com. 
 When running the code on the website, do not include this function.
 */
function TreeNode(val, left, right) {
    this.val = (val === undefined ? 0 : val);
    this.left = (left === undefined ? null : left);
    this.right = (right === undefined ? null : right);
}

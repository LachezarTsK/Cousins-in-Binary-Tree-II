
#include <queue>
using namespace std;

/*
Struct TreeNode is in-built in the solution file on leetcode.com.
When running the code on the website, do not include this struct.
 */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
    
public:
    TreeNode* replaceValueInTree(TreeNode* root) const {
        queue<TreeNode*> queue;
        queue.push(root);

        root->val = 0;
        int sumForAllNodesAtLevelChildren = calculateSumForChildrenOfNode(root);

        while (!queue.empty()) {

            size_t currentLevelSize = queue.size();
            int sumForAllNodesAtLevelChildrenOfChildren = 0;

            while (currentLevelSize-- > 0) {
                TreeNode* current = queue.front();
                queue.pop();
                int sumForChildrenOfCurrentNode = calculateSumForChildrenOfNode(current);

                if (current->left != nullptr) {
                    current->left->val = sumForAllNodesAtLevelChildren - sumForChildrenOfCurrentNode;
                    sumForAllNodesAtLevelChildrenOfChildren += calculateSumForChildrenOfNode(current->left);
                    queue.push(current->left);
                }

                if (current->right != nullptr) {
                    current->right->val = sumForAllNodesAtLevelChildren - sumForChildrenOfCurrentNode;
                    sumForAllNodesAtLevelChildrenOfChildren += calculateSumForChildrenOfNode(current->right);
                    queue.push(current->right);
                }
            }
            sumForAllNodesAtLevelChildren = sumForAllNodesAtLevelChildrenOfChildren;
        }
        return root;
    }

private:
    int calculateSumForChildrenOfNode(TreeNode* node) const {
        return ((node->left != nullptr) ? node->left->val : 0)
                + ((node->right != nullptr) ? node->right->val : 0);
    }
};

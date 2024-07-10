/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> paths;
        vector<int> currentPath;

        pathSumHelper(root, targetSum, currentPath, paths);

        return paths;
    }

private:
    void pathSumHelper(TreeNode* node, int targetSum, vector<int>& currentPath, vector<vector<int>>& paths) {
        if (node == nullptr) {
            return;
        }

        currentPath.push_back(node->val);

        if (node->left == nullptr && node->right == nullptr && node->val == targetSum) {
            paths.push_back(currentPath);
        }

        pathSumHelper(node->left, targetSum - node->val, currentPath, paths);
        pathSumHelper(node->right, targetSum - node->val, currentPath, paths);

        currentPath.pop_back();
    }
};

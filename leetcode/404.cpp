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
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        if (root == nullptr) { // base case
            return sum;
        }
        if (root->left != nullptr) {
            TreeNode* obj = root->left;
            if (obj->left == nullptr && obj->right == nullptr) { // base case
                sum += obj->val;
            }
        }
        sum += sumOfLeftLeaves(root->left);
        sum += sumOfLeftLeaves(root->right);
        return sum;
    }
};

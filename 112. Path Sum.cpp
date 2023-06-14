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
class Solution
{
public:
    bool hasPathSum(TreeNode *root, int targetSum, int ans = 0)
    {
        if (!root)
            return false;
        ans += root->val;
        if (!root->left && !root->right)
        {
            if (ans == targetSum)
            {
                return true;
            }
            return false;
        }
        return hasPathSum(root->left, targetSum, ans) || hasPathSum(root->right, targetSum, ans);
    }
};
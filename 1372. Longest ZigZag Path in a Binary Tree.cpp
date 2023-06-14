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
    int maxlen = 0;
    void helper(TreeNode *root, bool dir, int len)
    {
        if (!root)
            return;
        maxlen = max(len, maxlen);
        helper(root->left, true, dir ? 1 : len + 1);
        helper(root->right, false, dir ? len + 1 : 1);
    }
    int longestZigZag(TreeNode *root)
    {
        helper(root, true, 0);
        helper(root, false, 0);
        return maxlen;
    }
};
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
    void helper(TreeNode *root, int &ans, int curr)
    {
        if (!root->left && !root->right)
        {
            // curr = curr*10 + root->val ;
            ans += curr;
            return;
        }
        if (root->left)
        {
            int newCurr = curr * 10 + root->left->val;
            helper(root->left, ans, newCurr);
        }
        if (root->right)
        {
            int newCurr = curr * 10 + root->right->val;
            helper(root->right, ans, newCurr);
        }
        return;
    }
    int sumNumbers(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        int ans = 0;
        helper(root, ans, root->val);
        return ans;
    }
};
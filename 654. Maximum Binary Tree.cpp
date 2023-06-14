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
    TreeNode *helper(vector<int> &v, int m, int n)
    {
        if (m > n)
            return NULL;
        int k = -1;
        int x = INT_MIN;
        for (int i = m; i <= n; i++)
        {
            if (v[i] > x)
            {
                k = i;
                x = v[i];
            }
        }
        TreeNode *root = new TreeNode(v[k]);
        root->left = helper(v, m, k - 1);
        root->right = helper(v, k + 1, n);
        return root;
    }
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        TreeNode *root = helper(nums, 0, nums.size() - 1);
        return root;
    }
};
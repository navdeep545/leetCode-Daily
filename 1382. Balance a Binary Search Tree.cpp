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
    void inorder(vector<int> &v, TreeNode *root)
    {
        if (!root)
            return;
        inorder(v, root->left);
        v.emplace_back(root->val);
        inorder(v, root->right);
        return;
    }

    TreeNode *builder(vector<int> &v, int start, int end)
    {
        if (start > end)
            return NULL;
        int x = start + (end - start) / 2;
        TreeNode *root = new TreeNode(v[x]);
        if (start == end)
            return root;
        root->left = builder(v, start, x - 1);
        root->right = builder(v, x + 1, end);
        return root;
    }

    TreeNode *balanceBST(TreeNode *root)
    {
        vector<int> v;
        inorder(v, root);
        root = builder(v, 0, v.size() - 1);
        return root;
    }
};
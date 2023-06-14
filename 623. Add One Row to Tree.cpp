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
    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {
        if (!root)
            return NULL;
        if (depth == 1)
        {
            auto newNode = new TreeNode(val);
            newNode->left = root;
            root = newNode;
            return root;
        }
        if (depth == 2)
        {
            auto leftNode = root->left;
            auto rightNode = root->right;
            root->left = new TreeNode(val);
            root->right = new TreeNode(val);
            root->left->left = leftNode;
            root->right->right = rightNode;
            return root;
        }
        root->left = addOneRow(root->left, val, depth - 1);
        root->right = addOneRow(root->right, val, depth - 1);
        return root;
    }
};
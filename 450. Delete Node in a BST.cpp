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
    TreeNode *deleteNode(TreeNode *node, int data)
    {
        if (!node)
            return NULL;
        if (node->val == data)
        {
            if (!node->left && !node->right)
            {
                delete node;
                return NULL;
            }
            if (node->left && node->right)
            {
                auto temp = node->right;
                while (temp->left)
                {
                    temp = temp->left;
                }
                int x = temp->val;
                node->val = x;
                node->right = deleteNode(node->right, x);
                return node;
            }
            if (node->left)
            {
                auto newNode = node->left;
                node->left = NULL;
                delete node;
                return newNode;
            }
            if (node->right)
            {
                auto newNode = node->right;
                node->right = NULL;
                delete node;
                return newNode;
            }
        }
        if (node->val < data)
        {
            node->right = deleteNode(node->right, data);
            return node;
        }
        node->left = deleteNode(node->left, data);
        return node;
    }
};
// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution
// {
// public:
//     int minVal(TreeNode *root)
//     {
//     }

//     int maxVal(TreeNode *root)
//     {
//     }

//     bool isValidBST(TreeNode *root)
//     {
//         if (!root)
//             return true;
//         if (root->right)
//         {
//             if (root->right->val < root->val)
//                 return false;
//         }
//         if (root->left)
//         {
//             if (root->left->val > root->val)
//                 return false;
//         }
//         if (root->val > minVal(root->right))
//             return false;
//         if (root->val < maxVal(root->left))
//             return false;

//         return true;
//     }
// };

class Solution
{
public:
    bool isValidBST(TreeNode *root)
    {
        TreeNode *prev = NULL;
        return validate(root, prev);
    }
    bool validate(TreeNode *node, TreeNode *&prev)
    {
        if (node == NULL)
            return true;
        if (!validate(node->left, prev))
            return false;
        if (prev != NULL && prev->val >= node->val)
            return false;
        prev = node;
        return validate(node->right, prev);
    }
};
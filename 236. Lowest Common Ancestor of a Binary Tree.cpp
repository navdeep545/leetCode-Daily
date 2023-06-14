/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root)
            return NULL;
        if (root->val == p->val || root->val == q->val)
        {
            return root;
        }
        auto temp1 = lowestCommonAncestor(root->left, p, q);
        auto temp2 = lowestCommonAncestor(root->right, p, q);
        if (!temp1)
            return temp2;
        if (!temp2)
            return temp1;
        return root;
    }
};
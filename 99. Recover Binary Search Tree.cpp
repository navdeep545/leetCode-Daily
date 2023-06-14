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
    TreeNode *findMin(TreeNode *root)
    {
        if (!root)
            return NULL;
        auto t = findMin(root->left);
        auto q = findMin(root->right);
        // if(!t && !q) return root  ;
        if (t && q)
        {
            if (root->val < t->val && root->val < q->val)
            {
                return root;
            }
            if (t->val < root->val && t->val < q->val)
            {
                return t;
            }
            if (q->val < root->val && q->val < t->val)
            {
                return q;
            }
        }
        else if (t)
        {
            if (root->val < t->val)
                return root;
            return t;
        }
        else if (q)
        {
            if (root->val < q->val)
                return root;
            return q;
        }
        return root;
    }

    TreeNode *findMax(TreeNode *root)
    {
        if (!root)
            return NULL;
        auto t = findMax(root->left);
        auto q = findMax(root->right);
        // if(!t && !q) return root  ;
        if (t && q)
        {
            if (root->val > t->val && root->val > q->val)
            {
                return root;
            }
            if (t->val > root->val && t->val > q->val)
            {
                return t;
            }
            if (q->val > root->val && q->val > t->val)
            {
                return q;
            }
        }
        else if (t)
        {
            if (root->val > t->val)
                return root;
            return t;
        }
        else if (q)
        {
            if (root->val > q->val)
                return root;
            return q;
        }
        return root;
    }

    void recoverTree(TreeNode *root)
    {
        if (!root)
            return;
        auto p = findMin(root->right);
        auto q = findMax(root->left);
        if (p && q && p->val < q->val)
        {
            int x = p->val;
            p->val = q->val;
            q->val = x;
            return;
        }
        if (p)
        {
            if (p->val < root->val)
            {
                int x = p->val;
                p->val = root->val;
                root->val = x;
                return;
            }
        }
        if (q)
        {
            if (q->val > root->val)
            {
                int x = q->val;
                q->val = root->val;
                root->val = x;
                return;
            }
        }
        recoverTree(root->left);
        recoverTree(root->right);
        return;
    }
};
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
    void preOrder(TreeNode *jadd, vector<int> &jhotta, int k)
    {
        if (!jadd)
            return;
        if (jhotta.size() >= k)
            return;
        preOrder(jadd->left, jhotta, k);
        jhotta.push_back(jadd->val);
        preOrder(jadd->right, jhotta, k);
        return;
    }
    int kthSmallest(TreeNode *root, int k)
    {
        if (!root)
            return 0;
        vector<int> jhotta;
        preOrder(root, jhotta, k);
        return jhotta[k - 1];
    }
};
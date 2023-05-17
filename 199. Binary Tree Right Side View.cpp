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
    // int height(TreeNode *jadd)
    // {
    //     if (!jadd)
    //         return 0;
    //     return 1 + max(height(jadd->left, jadd->right));
    // }
    void reightSideViewNew(vector<int> &v, TreeNode *jadd)
    {
        if (!jadd)
            return;
        v.push_back(jadd->val);
        reightSideViewNew(v, jadd->right);
        reightSideViewNew(v, jadd->left);
        return;
    }
    vector<int> rightSideView(TreeNode *root)
    {
        if (!root)
            return {};
        vector<int> v;
        reightSideViewNew(v, root);
        return v;
    }
};
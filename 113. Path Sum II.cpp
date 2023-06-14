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
    void pathSumToLeaf(TreeNode *jadd, vector<vector<int>> &v, vector<int> &p, int &k, int ans = 0)
    {
        if (!jadd)
            return;
        ans += jadd->val;
        if (!jadd->left && !jadd->right)
        {
            if (ans == k)
            {
                p.push_back(jadd->val);
                v.push_back(p);
                return;
            }
        }
        p.push_back(jadd->val);
        int j = p.size();
        pathSumToLeaf(jadd->left, v, p, k, ans);
        if (j < p.size())
        {
            int m = p.size() - j;
            while (m--)
                p.pop_back();
        }
        pathSumToLeaf(jadd->right, v, p, k, ans);
        return;
    }
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        if (!root)
            return {};
        vector<vector<int>> v;
        vector<int> p;
        pathSumToLeaf(root, v, p, targetSum);
        return v;
    }
};
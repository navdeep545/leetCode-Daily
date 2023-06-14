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
    pair<int, int> helper(TreeNode *root)
    {
        if (!root)
        {
            auto p = make_pair(0, 0);
            return p;
        }
        auto m = helper(root->left);
        auto n = helper(root->right);
        auto ans = make_pair(m.first + n.first + root->val, 1 + m.second + n.second);
        return ans;
    }
    int averageOfSubtree(TreeNode *root)
    {
        if (!root)
            return 0;
        queue<TreeNode *> bus;
        bus.push(root);
        int ans = 0;
        while (bus.size())
        {
            auto front = bus.front();
            bus.pop();
            auto p = helper(front->left);
            auto q = helper(front->right);
            int x = (front->val + p.first + q.first) / (1 + p.second + q.second);
            if (front->val == x)
                ans++;
            if (front->left)
                bus.push(front->left);
            if (front->right)
                bus.push(front->right);
        }
        return ans;
    }
};
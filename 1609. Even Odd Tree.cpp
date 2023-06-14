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
    bool solve(queue<TreeNode *> &bus, bool flag)
    {
        if (bus.empty())
            return true;
        int x = INT_MAX;
        if (flag)
            x = INT_MIN;

        int n = bus.size();

        int p = flag ? 1 : 0;

        while (n--)
        {
            auto front = bus.front();
            bus.pop();

            if (front->left)
                bus.push(front->left);
            if (front->right)
                bus.push(front->right);

            if (front->val % 2 != p)
                return false;
            if (flag)
                if (front->val <= x)
                    return false;
            if (!flag)
                if (front->val >= x)
                    return false;

            x = front->val;
        }

        return true && solve(bus, !flag);
    }

    bool isEvenOddTree(TreeNode *root)
    {
        queue<TreeNode *> bus;
        bus.push(root);
        return solve(bus, true);
    }
};
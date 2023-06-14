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
    vector<int> largestValues(TreeNode *root)
    {
        if (!root)
            return {};
        vector<int> v;
        queue<TreeNode *> bus;
        bus.push(root);
        while (!bus.empty())
        {
            int k = bus.size();
            int curr = INT_MIN;
            for (int i = 0; i < k; i++)
            {
                auto front = bus.front();
                bus.pop();
                curr = max(curr, front->val);
                if (front->left)
                    bus.push(front->left);
                if (front->right)
                    bus.push(front->right);
            }
            v.emplace_back(curr);
        }
        return v;
    }
};
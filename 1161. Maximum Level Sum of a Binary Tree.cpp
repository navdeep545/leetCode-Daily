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
    int maxLevelSum(TreeNode *root)
    {
        if (!root)
            return 0;
        queue<TreeNode *> bus;
        bus.push(root);
        int count = 0;
        int ans = 0;
        int curr = INT_MIN;
        while (bus.size())
        {
            int n = bus.size();
            int temp = 0;
            while (n--)
            {
                auto front = bus.front();
                bus.pop();
                temp += front->val;
                if (front->left)
                    bus.push(front->left);
                if (front->right)
                    bus.push(front->right);
            }
            count++;
            if (temp > curr)
            {
                ans = count;
                curr = temp;
            }
        }
        return ans;
    }
};
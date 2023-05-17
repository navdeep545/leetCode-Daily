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
    void levelOrderPro(queue<TreeNode *> &bus, vector<vector<int>> &jadd)
    {
        if (bus.empty())
            return;
        int n = bus.size();
        vector<int> jhotta;
        while (n)
        {
            auto front = bus.front();
            bus.pop();
            jhotta.push_back(front->val);
            if (front->left)
            {
                bus.push(front->left);
            }
            if (front->right)
            {
                bus.push(front->right);
            }
            n--;
        }
        jadd.push_back(jhotta);
        levelOrderPro(bus, jadd);
        return;
    }

    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (!root)
            return {};
        queue<TreeNode *> bus;
        bus.push(root);
        vector<vector<int>> jhotta;
        levelOrderPro(bus, jhotta);
        return jhotta;
    }
};
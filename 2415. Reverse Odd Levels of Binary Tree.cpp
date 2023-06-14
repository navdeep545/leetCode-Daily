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
    void pusher(vector<vector<TreeNode *>> &v, TreeNode *root)
    {
        if (!root)
            return;

        int i = 0;
        queue<TreeNode *> bus;
        bus.push(root);

        while (!bus.empty())
        {

            int n = bus.size();
            vector<TreeNode *> temp;

            while (n--)
            {
                auto front = bus.front();
                bus.pop();
                if (front->left)
                    bus.push(front->left);
                if (front->right)
                    bus.push(front->right);
                if (i % 2 == 0)
                {
                    temp.push_back(front);
                }
                else
                    temp.insert(temp.begin(), front);
            }

            i++;
            v.push_back(temp);
        }
        return;
    }

    TreeNode *reverseOddLevels(TreeNode *root)
    {
        if (!root)
            return NULL;
        vector<vector<TreeNode *>> v;
        pusher(v, root);

        for (int i = 0; i < v.size() - 1; i++)
        {
            int j = 0;
            for (int k = 0; k < v[i].size(); k++)
            {
                v[i][k]->left = v[i + 1][j];
                v[i][k]->right = v[i + 1][j + 1];
                j += 2;
            }
        }
        return root;
    }
};
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
    int amountOfTime(TreeNode *root, int start)
    {
        if (root && !root->left && !root->right)
            return 0;
        unordered_map<TreeNode *, TreeNode *> umap;
        queue<TreeNode *> bus;
        TreeNode *starter = root;
        bus.push(root);

        while (!bus.empty())
        {
            int len = bus.size();
            while (len--)
            {
                auto front = bus.front();
                bus.pop();
                if (front->val == start)
                {
                    starter = front;
                }
                if (front->left)
                {
                    umap[front->left] = front;
                    bus.push(front->left);
                }
                if (front->right)
                {
                    umap[front->right] = front;
                    bus.push(front->right);
                }
            }
        }

        unordered_set<TreeNode *> visited;
        bus.push(starter);
        int ans = 0;
        while (!bus.empty())
        {
            bool infected = false;
            int len = bus.size();
            while (len--)
            {
                auto front = bus.front();
                bus.pop();
                if (umap.count(front) == 1 && visited.count(umap[front]) == 0)
                {
                    bus.push(umap[front]);
                    visited.insert(umap[front]);
                    infected = true;
                }
                if (front->left && visited.count(front->left) == 0)
                {
                    bus.push(front->left);
                    infected = true;
                    visited.insert(front->left);
                }
                if (front->right && visited.count(front->right) == 0)
                {
                    bus.push(front->right);
                    infected = true;
                    visited.insert(front->right);
                }
                visited.insert(front);
            }
            if (infected)
                ans++;
        }
        return ans;
    }
};
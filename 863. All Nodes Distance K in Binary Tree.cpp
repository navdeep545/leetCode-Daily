/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        if (!root)
            return {};
        unordered_map<TreeNode *, TreeNode *> umap;
        queue<TreeNode *> bus;
        bus.push(root);
        while (!bus.empty())
        {
            auto front = bus.front();
            bus.pop();
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
        vector<int> result;
        unordered_set<TreeNode *> visited;
        visited.insert(target);
        int dist = 0;
        bus.push(target);
        while (!bus.empty())
        {
            int levelSize = bus.size();
            if (dist++ == k)
            {
                while (!bus.empty())
                {
                    auto front = bus.front();
                    bus.pop();
                    // if(front)
                    result.push_back(front->val);
                }
                return result;
            }
            while (levelSize--)
            {
                auto front = bus.front();
                bus.pop();
                if (front->left && visited.find(front->left) == visited.end())
                {
                    bus.push(front->left);
                    visited.insert(front->left);
                }
                if (front->right && visited.find(front->right) == visited.end())
                {
                    bus.push(front->right);
                    visited.insert(front->right);
                }
                if (umap.find(front) != umap.end() && visited.find(umap[front]) == visited.end())
                {
                    bus.push(umap[front]);
                    visited.insert(umap[front]);
                }
            }
        }
        return result;
    }
};
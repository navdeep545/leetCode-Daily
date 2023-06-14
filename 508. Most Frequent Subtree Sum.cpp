class Solution
{
public:
    int solve(TreeNode *root, unordered_map<int, int> &umap)
    {
        if (!root)
            return 0;
        int x = root->val;
        int leftSum = solve(root->left, umap);
        int rightSum = solve(root->right, umap);
        int sum = x + leftSum + rightSum;
        umap[sum]++;
        return sum;
    }

    vector<int> findFrequentTreeSum(TreeNode *root)
    {
        unordered_map<int, int> umap;
        solve(root, umap);

        int maxFreq = 0;
        for (auto i : umap)
        {
            maxFreq = max(maxFreq, i.second);
        }

        vector<int> ans;
        for (auto i : umap)
        {
            if (i.second == maxFreq)
            {
                ans.push_back(i.first);
            }
        }

        return ans;
    }
};

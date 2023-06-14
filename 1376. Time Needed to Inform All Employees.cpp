class Solution
{
public:
    int helper(vector<vector<int>> &m, vector<int> &informTime, int headID)
    {
        // vector<int> v = m[headID] ;
        // if(headID >= v.size()) return 0 ;
        if (m[headID].empty())
            return informTime[headID];
        int ans = INT_MIN;
        for (auto i : m[headID])
        {
            int k = helper(m, informTime, i);
            ans = max(ans, k);
        }
        return informTime[headID] + ans;
    }
    int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
    {
        vector<vector<int>> umap(n);
        int k = manager.size();
        for (int i = 0; i < k; i++)
        {
            if (manager[i] != -1)
                umap[manager[i]].emplace_back(i);
        }
        return helper(umap, informTime, headID);
    }
};
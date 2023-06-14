class Solution
{
public:
    void helper(vector<vector<int>> &v, vector<bool> &vis, int id)
    {
        if (id >= v.size())
            return;
        vis[id] = true;
        int n = v.size();
        for (int i = 0; i < n; i++)
        {
            if (v[id][i] == 1)
            {
                if (!vis[i])
                {
                    helper(v, vis, i);
                }
            }
        }
        return;
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        vector<bool> v(n, false);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (!v[i])
            {
                ans++;
                helper(isConnected, v, i);
            }
        }
        return ans;
    }
};
class Solution
{
public:
    void dfs(vector<vector<int>> &graph, vector<bool> &visited, int &i, int &ans)
    {
        visited[i] = true;
        ans++;
        int n = graph[i].size();
        for (int j = 0; j < n; j++)
        {
            if (!visited[graph[i][j]])
            {
                dfs(graph, visited, graph[i][j], ans);
            }
        }
        return;
    }
    int maximumDetonation(vector<vector<int>> &bombs)
    {
        int n = bombs.size();
        vector<vector<int>> graph(n);
        for (int i = 0; i < n; i++)
        {
            long long int x1 = bombs[i][0];
            long long int y1 = bombs[i][1];
            long long int r1 = bombs[i][2];
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                {
                    long long int x = pow(abs(bombs[j][0] - x1), 2);
                    long long int y = pow(abs(bombs[j][1] - y1), 2);
                    if (x + y <= pow(r1, 2))
                    {
                        graph[i].emplace_back(j);
                    }
                }
            }
        }
        int res = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            int ans = 0;
            vector<bool> visited(n, false);
            dfs(graph, visited, i, ans);
            res = max(res, ans);
        }
        return res;
    }
};
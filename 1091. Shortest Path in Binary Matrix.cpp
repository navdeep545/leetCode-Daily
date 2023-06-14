class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        if (grid[0][0])
            return -1;
        int n = grid.size();
        if (n == 1)
            return grid[0][0] == 0 ? 1 : -1;
        if (grid[n - 1][n - 1])
            return -1;
        queue<pair<int, int>> bus;
        bus.push(make_pair(0, 0));
        grid[0][0] = -1;
        int ans = 2;
        while (bus.size())
        {
            int len = bus.size();
            while (len--)
            {
                auto front = bus.front();
                bus.pop();
                for (int i = max(0, front.first - 1), lmX = min(front.first + 1, n - 1); i <= lmX; i++)
                {
                    for (int j = max(0, front.second - 1), lmY = min(front.second + 1, n - 1); j <= lmY; j++)
                    {
                        if (i == n - 1 && j == n - 1)
                            return ans;
                        if (grid[i][j] == 0)
                        {
                            grid[i][j] = -1;
                            bus.push(make_pair(i, j));
                        }
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};
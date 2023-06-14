class Solution
{
public:
    bool checkStraightLine(vector<vector<int>> &coordinates)
    {
        if (coordinates.size() == 2)
            return true;
        float x;
        if (coordinates[1][0] == coordinates[0][0])
            x = INT_MIN;
        else
            x = (float)(coordinates[1][1] - coordinates[0][1]) / (coordinates[1][0] - coordinates[0][0]);
        int n = coordinates.size();
        for (int i = 1; i < n - 1; i++)
        {
            float m;
            if (coordinates[i + 1][0] == coordinates[i][0])
                m = INT_MIN;
            else
                m = (float)(coordinates[i + 1][1] - coordinates[i][1]) / (coordinates[i + 1][0] - coordinates[i][0]);
            if (x != m)
                return false;
        }
        return true;
    }
};
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> ans;
        int n = matrix.size();
        int m = matrix[0].size();
        int left = 0;
        int right = m - 1;
        int top = 0;
        int bottom = n - 1;
        int dir = 0;
        while (left <= right && top <= bottom)
        {
            if (dir == 0)
            {
                int i = top;
                for (int j = left; j <= right; j++)
                {
                    ans.emplace_back(matrix[i][j]);
                }
                top++;
            }
            else if (dir == 1)
            {
                int j = right;
                for (int i = top; i <= bottom; i++)
                {
                    ans.emplace_back(matrix[i][j]);
                }
                right--;
            }
            else if (dir == 2)
            {
                int i = bottom;
                for (int j = right; j >= left; j--)
                {
                    ans.emplace_back(matrix[i][j]);
                }
                bottom--;
            }
            else if (dir == 3)
            {
                int j = left;
                for (int i = bottom; i >= top; i--)
                {
                    ans.emplace_back(matrix[i][j]);
                }
                left++;
            }
            dir = (dir + 1) % 4;
        }
        return ans;
    }
};
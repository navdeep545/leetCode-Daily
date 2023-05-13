class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> jhotta(n, vector<int>(n));
        int i = 1;
        int direction = 0;
        int top = 0;
        int bottom = n - 1;
        int left = 0;
        int right = n - 1;
        while (i <= n * n)
        {
            int j = top;
            for (int k = left; k <= right; k++)
            {
                jhotta[j][k] = i++;
            }
            top++;
            direction = 1;
            j = right;
            for (int k = top; k <= bottom; k++)
            {
                jhotta[k][j] = i++;
            }
            right--;
            direction = 2;
            j = bottom;
            for (int k = right; k >= left; k--)
            {
                jhotta[j][k] = i++;
            }
            bottom--;
            j = left;
            for (int k = bottom; k >= top; k--)
            {
                jhotta[k][j] = i++;
            }
            left++;
        }
        return jhotta;
    }
};
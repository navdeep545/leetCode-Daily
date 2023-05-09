// pre-requisite = leetcode 560

class Solution
{
public:
    int targetSum(vector<int> v, int k)
    {
        int n = v.size();
        int ans = 0;
        int sum = 0;
        unordered_map<int, int> umap;
        for (int i = 0; i < n; i++)
        {
            sum += v[i];
            if (sum == k)
            {
                ans++;
            }
            if (umap.find(sum - k) != umap.end())
            {
                ans += umap[sum - k];
            }
            umap[sum]++;
        }
        return ans;
    }
    int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target)
    {
        int ans = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 0; i < n; i++)
        {
            vector<int> sumMatrix(m, 0);
            for (int j = i; j < n; j++)
            {
                for (int k = 0; k < m; k++)
                {
                    sumMatrix[k] += matrix[j][k];
                }
                ans += targetSum(sumMatrix, target);
            }
        }
        return ans;
    }
};
// 34/42 TLE solution

class Solution
{
public:
    vector<int> canSeePersonsCount(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> ans(n);
        for (int i = 0; i < n - 1; i++)
        {
            int k = heights[i];
            int count = 0;
            int m = INT_MIN;
            for (int j = i + 1; j < n; j++)
            {
                if (k < m)
                {
                    break;
                }
                if (m < heights[j])
                {
                    count++;
                    m = heights[j];
                }
            }
            ans[i] = count;
        }
        return ans;
    }
};

// leetcode solution

class Solution
{
public:
    vector<int> canSeePersonsCount(vector<int> &A)
    {
        int n = A.size();
        vector<int> res(n), stack;
        for (int i = 0; i < n; ++i)
        {
            while (!stack.empty() && A[stack.back()] <= A[i])
                res[stack.back()]++, stack.pop_back();
            if (!stack.empty())
                res[stack.back()]++;
            stack.push_back(i);
        }
        return res;
    }
};
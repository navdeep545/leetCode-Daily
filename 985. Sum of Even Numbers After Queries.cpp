class Solution
{
public:
    vector<int> sumEvenAfterQueries(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] % 2 == 0)
                ans += nums[i];
        }
        // ans++ ;
        vector<int> vec;
        for (auto i : queries)
        {
            nums[i[1]] = nums[i[1]] + i[0];
            if ((nums[i[1]] % 2) == 0)
            {
                if ((i[0] % 2) == 0)
                    ans = ans + i[0];
                else
                    ans += nums[i[1]];
            }
            else
            {
                int x = nums[i[1]] - i[0];
                if ((x % 2) == 0)
                    ans = ans - x;
            }
            vec.push_back(ans);
        }
        return vec;
    }
};
// class Solution
// {
// public:
//     vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector<int> &r)
//     {
//         int count = nums.size();
//         int n = l.size();
//         int i = 0;
//         vector<bool> ans;
//         while (i < n)
//         {
//             vector<int> curr;
//             for (int x = l[i]; x < r[i]; x++)
//             {
//                 curr.push_back(nums[x]);
//             }
//             sort(curr.begin(), curr.end());
//             if (curr.size() <= 2)
//                 ans.push_back(true);
//             else
//             {

//                 int temp = curr[1] - curr[0];
//                 bool flag = true;
//                 for (int k = 1; k < curr.size() - 1; k++)
//                 {
//                     int newTemp = curr[k + 1] - curr[k];
//                     if (newTemp != temp)
//                     {
//                         ans.push_back(false);
//                         flag = false;
//                         break;
//                     }
//                 }
//                 if (flag)
//                     ans.push_back(true);
//             }
//             i++;
//         }
//         return ans;
//     }
// };

class Solution
{
public:
    vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector<int> &r)
    {
        int n = l.size();
        vector<bool> ans;
        for (int i = 0; i < n; i++)
        {
            vector<int> sub(nums.begin() + l[i], nums.begin() + r[i] + 1);
            sort(sub.begin(), sub.end());
            int diff = sub[1] - sub[0];
            bool flag = true;
            for (int j = 2; j < sub.size(); j++)
            {
                if (sub[j] - sub[j - 1] != diff)
                {
                    flag = false;
                    break;
                }
            }
            ans.push_back(flag);
        }
        return ans;
    }
};

class Solution
{
public:
    static bool myCompare(pair<int, int> &l, pair<int, int> &q)
    {
        return (l.first > q.first);
    }
    vector<vector<int>> sortTheStudents(vector<vector<int>> &score, int k)
    {
        int n = score.size();
        vector<pair<int, int>> pq;
        for (int i = 0; i < n; i++)
        {
            /* code */
            pq.push_back(make_pair(score[i][k], i));
        }
        vector<vector<int>> ans(n);
        sort(pq.begin(), pq.end(), myCompare);
        for (int i = 0; i < n; i++)
        {
            /* code */
            auto front = pq[i];
            ans[i] = score[front.second];
        }
        score = ans;
        ans.clear();
        return score;
    }
};
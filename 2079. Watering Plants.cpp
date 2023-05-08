class Solution
{
public:
    int wateringPlants(vector<int> &plants, int capacity)
    {
        int ans = 0;
        int n = plants.size();
        int currCap = capacity;
        for (int i = 0; i < n; i++)
        {
            ans++;
            if (plants[i] > currCap)
            {
                ans += 2 * i;
                currCap = capacity;
            }
            currCap = currCap - plants[i];
        }
        return ans;
    }
};
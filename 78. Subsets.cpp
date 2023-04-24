class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans ;
        ans.push_back({}) ;
        int n = nums.size() ;
        // int k = 0 ;
        for(int i=0;i<n;i++){
            int x = ans.size() ;
            for(int j=0;j<x;j++){
                vector<vector<int>> v ;
                v.emplace_back(ans[j]) ;
                v[0].emplace_back(nums[i]) ;
                ans.emplace_back(v[0]) ;
            }
        }
        return ans ;
    }
};
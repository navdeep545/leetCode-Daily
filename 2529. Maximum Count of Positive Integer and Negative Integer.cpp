class Solution {
    public:
        int maximumCount(vector<int>& nums) {
            auto l1 = lower_bound(nums.begin(),nums.end(),0) ;
            int i2 = upper_bound(l1,nums.end(),0) - nums.begin() ;
            int ans = max(static_cast<int>(l1 - nums.begin()),static_cast<int>(nums.size() - i2));
            return ans ;
        }
    };
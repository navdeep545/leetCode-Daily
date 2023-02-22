#include <bits/stdc++.h>
#include <set>
using namespace std ;

class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        int n=nums.size() ;
        // int ans = 0 ;
        unordered_set<int> s ;
        for(int i=0;i<n;i++){
            // int x = nums[i] ;
            s.insert(nums[i]) ;
            int after = 0 ;
            while(nums[i]/10 != 0){
                after = after*10 + nums[i]%10 ;
                nums[i] /= 10 ;
            }
            after = after*10 + nums[i]%10 ;
            s.insert(after) ;
        }
        
        return s.size() ;
    }
};
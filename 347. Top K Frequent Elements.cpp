class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mpp ;
        for(auto i:nums){
            mpp[i]++ ;
        }
        priority_queue<pair<int,int>> vec ;
        for(auto i:mpp){
            vec.push({i.second,i.first}) ;
        }
        nums.clear() ;
        while(k--){
            nums.push_back(vec.top().second) ;
            vec.pop() ;
        }
        return nums ;
    }
};

// did with some help
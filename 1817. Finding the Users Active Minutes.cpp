#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        vector<int> v(k,0) ;
        unordered_map<int,int> mpp ;
        for(int i=0;i<logs.size();i++)
        {
            if(mpp.find(logs[i][0]) == mpp.end())
            {
                unordered_map<int,int> umap ;
                for(int j=i;j<logs.size();j++)
                {
                    if(logs[i][0] == logs[j][0])
                    if(umap.find(logs[j][1]) == umap.end())
                    {
                        umap[logs[j][1]]++ ;
                        mpp[logs[i][0]]++ ;
                    }
                }
                v[mpp[logs[i][0]]-1]++ ;
            }
        }
        return v ;
    }
};

// first attempt at hashing took quite a time but finally was able to solve after getting some errors

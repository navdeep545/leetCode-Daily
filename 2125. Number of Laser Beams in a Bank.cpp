class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        if(bank.size() == 1) return 0 ;
        int m=bank.size() ;
        int n=bank[0].length() ;
        vector<int> v(m,0) ;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(bank[i][j]-'0' != 0)
                {
                    v[i]++ ;
                }
            }
        }
        v.erase( remove (v.begin(), v.end(), 0), v.end() );
        if(v.empty()) return 0 ;
        int ans = 0 ;
        for(int i=0;i<v.size()-1;i++)
        {
            ans += v[i] * v[i+1] ;
        }
        return ans ;
    }
};
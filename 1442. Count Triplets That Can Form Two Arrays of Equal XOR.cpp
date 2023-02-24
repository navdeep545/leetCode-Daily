class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size() ;
        vector<int> prefix(n+1) ;
        int ans = 0 ;
        for(int i=1;i<=n;i++)
        prefix[i] = prefix[i-1] ^ arr[i-1] ;
        for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
        for(int k=j;k<=n;k++)
        if(prefix[j-1]^prefix[i-1] == prefix[k]^prefix[j-1])
        ans++ ;
        return ans ;
    }
};

// couldnt understand the question properly, watched the approach from solution
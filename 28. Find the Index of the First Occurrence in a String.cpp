#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length() ;
        int m = needle.length() ;
        for(int i=0;i<n;i++){
            if(haystack[i] == needle[0])
            {
                int ans = i ;
                int j ;
                int x = i ;
                for(j=0;j<m;j++)
                {
                    if(haystack[x] != needle[j] ) break ;
                    x++ ;
                }
                if(j == m) return ans ;
            }
        }
        return -1 ;
    }
};

int main(){
    string s1 ;
    string s2 ;
    cin >> s1 ;
    cin >> s2 ;
    Solution obj ;
    int ans =  obj.strStr(s1,s2) ;
    cout << ans << endl ;
}
